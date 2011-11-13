#ifndef CTREE_H
#define CTREE_H

#include <QTreeWidget>
#include <QStringList>

#include "ctreeitem.h"
#include "container.h"

class CTree : public QTreeWidget
{
    Q_OBJECT

public:
    CTree(QWidget *parent = 0);

public slots:
    void redrawTree(QList<struct container_t> lst);
    CTreeItem * getParentItem();
};

#endif // CTREE_H
