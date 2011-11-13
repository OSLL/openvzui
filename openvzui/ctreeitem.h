#ifndef CTREEITEM_H
#define CTREEITEM_H

#include <QTreeWidgetItem>
#include <QString>

#include "container.h"

class CTreeItem : public QTreeWidgetItem
{
private:
    QString ctid;
    qint32 nproc;
    ContainerStatus status;
    QString ip;
    QString hostname;

public:
    CTreeItem(const struct container_t &ct, QTreeWidget *parent = 0);

    QString getCTID() const;
    qint32 getNPROC() const;
    ContainerStatus getStatus() const;
    QString getIP() const;
    QString getHostname() const;
};

#endif // CTREEITEM_H
