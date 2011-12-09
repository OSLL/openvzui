#include <QVBoxLayout>
#include <QDebug>
#include "cvzcentralwidget.h"

CVZCentralWidget::CVZCentralWidget(QWidget *parent) :
    QWidget(parent), _ctCmd("/home/mirovingen/aptu/parallels/vzctl")
{
    _ctl = new CVZControlPane(this);
    _model = new CVZModel(this);
    _view = new QTreeView(this);
    _listcmd = new CVZListExec(this);
    _util = new QProcess(this);

    QVBoxLayout *main = new QVBoxLayout;
    main->addWidget(_view);
    main->addWidget(_ctl);

    _view->setModel(_model);

    connect(_listcmd, SIGNAL(update(QList<CVZContainer>)), _model, SLOT(update(QList<CVZContainer>)));
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

    setLayout(main);
    _listcmd->execute();
}

void CVZCentralWidget::updateCtl(const QModelIndex &index)
{
    if (index.isValid()) {
        CVZContainer ct = _model->getSelectedContainer(index);
        _current = ct.ctid();

        qDebug() << "current changed: " + _current;

        if (ct.status() == CVZContainer::Running) {
            emit enableStart(false);
            emit enableStop(true);
        } else {
            emit enableStart(true);
            emit enableStop(false);
        }
    }
}

void CVZCentralWidget::runCt()
{
    QStringList args("start");
    args << _current;

    qDebug() << "execute: " << _ctCmd << " " << args;

    _util->start(_ctCmd, args);
}

void CVZCentralWidget::stopCt()
{
    QStringList args("stop");
    args << _current;

    qDebug() << "execute: " << _ctCmd << " " << args;

    _util->start(_ctCmd, args);
}
