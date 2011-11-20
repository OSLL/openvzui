#ifndef CTREEITEM_H
#define CTREEITEM_H

#include <QTreeWidgetItem>
#include <QString>

#include "container.h"

class CTreeItem : public QTreeWidgetItem
{
private:
    QString _ctid;
    qint32 _nproc;
    ContainerStatus _status;
    QString _ip;
    QString _hostname;

public:
    CTreeItem(const struct container_t &ct, QTreeWidget *parent = 0);

    QString getCTID() const;
    qint32 getNPROC() const;
    ContainerStatus getStatus() const;
    QString getIP() const;
    QString getHostname() const;
};

#endif // CTREEITEM_H
