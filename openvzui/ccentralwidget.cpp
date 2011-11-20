#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

#include "ccentralwidget.h"

CCentralWidget::CCentralWidget(QWidget *parent)
    : QWidget(parent)
{
    _startButton = new QPushButton(tr("start"));
    _stopButton = new QPushButton(tr("stop"));
    _updateButton = new QPushButton(tr("update"));
//    _ctree = new CTree;
    _model = new CContainerTreeModel(this);
    _view = new QTreeView(this);
    _view->setModel(_model);
    _view->setRootIndex(QModelIndex());

    _startButton->setEnabled(false);
    _stopButton->setEnabled(false);

    QHBoxLayout *ctl = new QHBoxLayout;
    QVBoxLayout *main = new QVBoxLayout;

    ctl->addWidget(_startButton);
    ctl->addWidget(_stopButton);
    ctl->addWidget(_updateButton);
//    main->addWidget(_ctree);
    main->addWidget(_view);
    main->addLayout(ctl);
    setLayout(main);

    connect(_startButton, SIGNAL(clicked()), this, SLOT(startCt()));
    connect(_stopButton, SIGNAL(clicked()), this, SLOT(stopCt()));
    connect(_updateButton, SIGNAL(clicked()), this, SLOT(updateCt()));
//    connect(_ctree, SIGNAL(itemSelectionChanged()), this, SLOT(enableButtons()));
}

void CCentralWidget::updateTree(const QList<struct container_t> &lst)
{
    //_ctree->redrawTree(lst);
    qDebug() << "signal recieved";
    _model->update(lst);
}

void CCentralWidget::startCt()
{
    //emit startContainer(_ctree->getParentItem()->getCTID());
}

void CCentralWidget::stopCt()
{
    //emit stopContainer(_ctree->getParentItem()->getCTID());
}

void CCentralWidget::updateCt()
{
    emit updateContainer();
}

void CCentralWidget::enableButtons()
{
/*    if (_ctree->getParentItem() != NULL) {
        if (_ctree->getParentItem()->getStatus() == Running) {
            _startButton->setEnabled(false);
            _stopButton->setEnabled(true);
        } else {
            _startButton->setEnabled(true);
            _stopButton->setEnabled(false);
        }
    } else {
        _startButton->setEnabled(false);
        _stopButton->setEnabled(false);
    }*/
}
