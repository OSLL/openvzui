#include "ctree.h"

CTree::CTree(QWidget *parent)
    : QTreeWidget(parent)
{
    setSelectionMode(SingleSelection);
    setEditTriggers(NoEditTriggers);
    setDragDropMode(NoDragDrop);
    setHeaderLabel(tr("Containers list"));

    clear();
}

void CTree::redrawTree(QList<struct container_t> lst)
{
    clear();

    QList<struct container_t>::const_iterator it = lst.begin();
    while (it != lst.end()) {
        addTopLevelItem(new CTreeItem(*it));
        ++it;
    }
}

CTreeItem* CTree::getParentItem()
{
    QList<QTreeWidgetItem *> lst = selectedItems();
    CTreeItem * item = NULL;

    if ( !lst.isEmpty() )
        item = static_cast<CTreeItem *>((lst.first()->type() != QTreeWidgetItem::UserType)?
                                            lst.first()->parent():
                                            lst.first());

    return item;
}
