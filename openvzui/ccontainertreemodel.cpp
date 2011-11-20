#include "ccontainertreemodel.h"

CContainerTreeModel::CContainerTreeModel(QObject * parent)
    :QAbstractItemModel(parent)
{}

int CContainerTreeModel::columnCount(const QModelIndex &) const
{
    return 1;
}

int CContainerTreeModel::rowCount(const QModelIndex &) const
{
    return _ctlist.count();
}

QVariant CContainerTreeModel::data(const QModelIndex &index, int) const
{
    if (!index.isValid()) return QVariant();
    if (index.internalId() == -1)
        return QVariant(_ctlist.at(index.row())._ctid);

    QModelIndex parent = index.parent();
    struct container_t ct =  _ctlist.at(parent.row());

    switch (index.row()) {
        case 0: return QVariant(ct._nproc);
        case 1: return QVariant(ct._status);
        default: return QVariant();
    }
}

QModelIndex CContainerTreeModel::index(int row, int, const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return createIndex(row, 0, parent.row());
    } else {
        return createIndex(row, 0, -1);
    }
}

QModelIndex CContainerTreeModel::parent(const QModelIndex &child) const
{
    if (child.isValid() && (child.internalId() != -1) ) {
        return createIndex(child.internalId(), 0, -1);
    } else return QModelIndex();
}

QVariant CContainerTreeModel::headerData(int, Qt::Orientation, int) const
{
    return QVariant("containers list");
}

void CContainerTreeModel::update(const QList<struct container_t> &lst)
{
    _ctlist = lst;
    emit layoutChanged();
}
