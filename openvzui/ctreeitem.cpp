#include "ctreeitem.h"

CTreeItem::CTreeItem(const struct container_t &ctid, QTreeWidget *parent)
    : QTreeWidgetItem(parent, UserType), _ctid(ctid._ctid), _nproc(ctid._nproc), _status(ctid._status)
{
    QTreeWidgetItem * nproc = new QTreeWidgetItem(Type);
    nproc->setText(0, "number of process: " + QString::number(ctid._nproc));
    QTreeWidgetItem * status = new QTreeWidgetItem(Type);
    if (ctid._status == Running)
        status->setText(0, "state: running");
    else
        status->setText(0, "state: stopped");

    addChild(nproc);
    addChild(status);

    setText(0, ctid._ctid);
}

QString CTreeItem::getCTID() const
{
    return _ctid;
}

qint32 CTreeItem::getNPROC() const
{
    return _nproc;
}

ContainerStatus CTreeItem::getStatus() const
{
    return _status;
}

QString CTreeItem::getIP() const
{
    return _ip;
}

QString CTreeItem::getHostname() const
{
    return _hostname;
}
