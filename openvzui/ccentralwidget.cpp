#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "ccentralwidget.h"

CCentralWidget::CCentralWidget(QWidget *parent)
    : QWidget(parent)
{
    startButton = new QPushButton(tr("start"));
    stopButton = new QPushButton(tr("stop"));
    ctree = new CTree;

    startButton->setEnabled(false);
    stopButton->setEnabled(false);

    QHBoxLayout *ctl = new QHBoxLayout;
    QVBoxLayout *main = new QVBoxLayout;

    ctl->addWidget(startButton);
    ctl->addWidget(stopButton);
    main->addWidget(ctree);
    main->addLayout(ctl);
    setLayout(main);

    connect(startButton, SIGNAL(clicked()), this, SLOT(startCt()));
    connect(stopButton, SIGNAL(clicked()), this, SLOT(stopCt()));
    connect(ctree, SIGNAL(itemSelectionChanged()), this, SLOT(enableButtons()));
}

void CCentralWidget::updateTree(QList<struct container_t> lst)
{
    ctree->redrawTree(lst);
}

void CCentralWidget::startCt()
{
    emit startContainer(ctree->getParentItem()->getCTID());
}

void CCentralWidget::stopCt()
{
    emit stopContainer(ctree->getParentItem()->getCTID());
}

void CCentralWidget::enableButtons()
{
    if (ctree->getParentItem() != NULL) {
        if (ctree->getParentItem()->getStatus() == Running) {
            startButton->setEnabled(false);
            stopButton->setEnabled(true);
        } else {
            startButton->setEnabled(true);
            stopButton->setEnabled(false);
        }
    } else {
        startButton->setEnabled(false);
        stopButton->setEnabled(false);
    }
}
