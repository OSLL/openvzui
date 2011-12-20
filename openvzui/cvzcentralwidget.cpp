#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

#include "cvzcentralwidget.h"

const QString CVZCentralWidget::_vzctlcmd = "vzctl";
const QString CVZCentralWidget::_ctstart = "start";
const QString CVZCentralWidget::_ctstop = "stop";

CVZCentralWidget::CVZCentralWidget(QWidget *parent) :
    QWidget(parent), _currentRunning(false)
{
    _ctl = new CVZControlPane(this);
    _res = new CVZResourcePanel(this);
    _pars = new CVZResourceParser(this);
    _model = new CVZModel(this);
    _view = new QTreeView(this);
    _listcmd = new CVZListExec(this);
    _util = new QProcess(this);

    QVBoxLayout *main = new QVBoxLayout;
    QHBoxLayout *subMain = new QHBoxLayout;

    subMain->addWidget(_view);
    subMain->addWidget(_res);
    subMain->setStretch(0,1);
    subMain->setStretch(1,3);
    main->addLayout(subMain);
    main->addWidget(_ctl);

    _view->setModel(_model);

    connect(_listcmd, SIGNAL(update(QList<CVZContainer>)), _model, SLOT(update(QList<CVZContainer>)));
    connect(_pars, SIGNAL(update(QList<CVZResource>)), _res, SLOT(update(QList<CVZResource>)));
    connect(_ctl, SIGNAL(updateClicked()), _listcmd, SLOT(execute()));
    connect(_util, SIGNAL(finished(int)), _listcmd, SLOT(execute()));
    connect(_ctl, SIGNAL(startClicked()), this, SLOT(runCt()));
    connect(_ctl, SIGNAL(stopClicked()), this, SLOT(stopCt()));
    connect(_view, SIGNAL(clicked(QModelIndex)), this, SLOT(updateCtl(QModelIndex)));
    connect(_view, SIGNAL(activated(QModelIndex)), this, SLOT(updateCtl(QModelIndex)));
    connect(_view, SIGNAL(pressed(QModelIndex)), this, SLOT(updateCtl(QModelIndex)));
    connect(_view, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(updateCtl(QModelIndex)));
    connect(this, SIGNAL(enableStart(bool)), _ctl, SLOT(enableStartButton(bool)));
    connect(this, SIGNAL(enableStop(bool)), _ctl, SLOT(enableStopButton(bool)));

    _listcmd->execute();
    _res->hide();
    startTimer(1000);
    setLayout(main);
}

void CVZCentralWidget::updateCtl(const QModelIndex &index)
{
    if (index.isValid()) {
        CVZContainer ct = _model->getSelectedContainer(index);
        _current = ct.ctid();

        qDebug() << "current changed: " + _current;

        if (ct.status() == CVZContainer::Running) {
            _currentRunning = true;
            emit enableStart(false);
            emit enableStop(true);
        } else {
            _currentRunning = false;
            emit enableStart(true);
            emit enableStop(false);
        }
    }
}

void CVZCentralWidget::runCt()
{
    QStringList args(_ctstart);
    args << _current;

    qDebug() << "execute: " << _vzctlcmd << " " << args;

    _util->start(_vzctlcmd, args);
}

void CVZCentralWidget::stopCt()
{
    QStringList args(_ctstop);
    args << _current;

    qDebug() << "execute: " << _vzctlcmd << " " << args;

    _util->start(_vzctlcmd, args);
}

void CVZCentralWidget::timerEvent(QTimerEvent *)
{
    if (_currentRunning)
    {
        _pars->execute(_current);
        _res->show();
    } else {
        _res->hide();
    }
}
