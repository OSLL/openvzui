#include "cvzresourcepanel.h"

#include <QVBoxLayout>


CVZResourcePanel::CVZResourcePanel(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *main = new QVBoxLayout(this);
    widgetForResourceItem = new QWidget(this);
    QGridLayout *layoutForResourceItem = new QGridLayout(widgetForResourceItem);
    scrollArea = new QScrollArea;

    for (size_t i(0); i<21; i++)
    {
        _resLabel[i] = new QLabel();
        layoutForResourceItem->addWidget(_resLabel[i],i,0);
        _resCurValue[i] = new QLabel();
        layoutForResourceItem->addWidget(_resCurValue[i],i,1,Qt::AlignRight);
        _resMaxValue[i] = new QLabel();
        layoutForResourceItem->addWidget(_resMaxValue[i],i,2,Qt::AlignLeft);
        _resVision[i] = new QProgressBar();
        layoutForResourceItem->addWidget(_resVision[i],i,3);
    }
    layoutForResourceItem->setColumnStretch(0,2);
    layoutForResourceItem->setColumnStretch(1,1);
    layoutForResourceItem->setColumnStretch(2,2);
    layoutForResourceItem->setColumnStretch(3,6);

    scrollArea->setWidget(widgetForResourceItem);

    main->addWidget(scrollArea);
    setLayout(main);
}

void CVZResourcePanel::update(const QList<CVZResource> &lst)
{
    for (size_t i(0); i<21; i++)
    {
        _resLabel[i]->setText(lst[i].getResourceName());
        _resCurValue[i]->setText(QString::number(lst[i].getHeld()));
        _resMaxValue[i]->setText(QString::number(lst[i].getLimit()));
        _resVision[i]->setValue(lst[i].getPersent());
    }
    if (scrollArea->width()*0.9 > 300)
        widgetForResourceItem->setFixedWidth(scrollArea->width()*0.9);
    else
        widgetForResourceItem->setFixedWidth(300);
}
