#include "ctreeitem.h"

CTreeItem::CTreeItem(const struct container_t &ctid, QTreeWidget *parent)
    : QTreeWidgetItem(parent, UserType), ctid(ctid.ctid), nproc(ctid.nproc), status(ctid.status)
{
    QTreeWidgetItem * _nproc = new QTreeWidgetItem(Type);
    _nproc->setText(0, "number of process: " + QString::number(ctid.nproc));
    QTreeWidgetItem * _status = new QTreeWidgetItem(Type);
    if (ctid.status == Running)
        _status->setText(0, "state: running");
    else
        _status->setText(0, "state: stopped");

    addChild(_nproc);
    addChild(_status);

    setText(0, ctid.ctid);
}

QString CTreeItem::getCTID() const
{
    return ctid;
}

qint32 CTreeItem::getNPROC() const
{
    return nproc;
}

ContainerStatus CTreeItem::getStatus() const
{
    return status;
}

QString CTreeItem::getIP() const
{
    return ip;
}

QString CTreeItem::getHostname() const
{
    return hostname;
}
