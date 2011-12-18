#include "cvzmodel.h"

CVZModel::CVZModel(QObject *parent)
    :QAbstractItemModel(parent)
{}

int CVZModel::rowCount(const QModelIndex &parent) const
{
    if (_ctlist.isEmpty())
        return 0;
    if (!parent.isValid())
        return _ctlist.count();
    else if (parent.internalId() == -1)
        return PROPCOUNT;
    else
        return 0;
}

int CVZModel::columnCount(const QModelIndex &) const
{
    return 1;
}

QVariant CVZModel::data(const QModelIndex &index, int role) const
{
    if ( (role != Qt::DisplayRole) || (!index.isValid()) || (_ctlist.isEmpty()) )
        return QVariant();

    if (index.internalId() == -1)
        return QVariant((_ctlist.at(index.row())).ctid());
    else {
        CVZContainer ct = _ctlist.at(index.internalId());
        switch (index.row()) {
        case 0:
            return QVariant(tr("nproc: ") + QString::number(ct.nproc()));
        case 1:
            return QVariant(tr("status: ") + ((ct.status() == CVZContainer::Running) ? tr("running") : tr("stopped")) );
        default:
            return QVariant();
        }
    }

    return QVariant();
}

QVariant CVZModel::headerData(int, Qt::Orientation, int role) const
{
    if ( role != Qt::DisplayRole )
        return QVariant();

    return QVariant(tr("Containers list"));
}

QModelIndex CVZModel::index(int row, int, const QModelIndex &parent) const
{
    if (_ctlist.isEmpty())
        return QModelIndex();

    if (parent.isValid())
        return createIndex(row, 0, parent.row());
    else
        return createIndex(row, 0, -1);
}

QModelIndex CVZModel::parent(const QModelIndex &child) const
{
    if ( !child.isValid() || (child.internalId() == -1) )
        return QModelIndex();
    else
        return createIndex(child.internalId(), 0, -1);
}

void CVZModel::update(const QList<CVZContainer> &lst)
{
    _ctlist.clear();
    _ctlist.append(lst);
    reset();
}

CVZContainer CVZModel::getSelectedContainer(const QModelIndex &index) const
{
    if (index.internalId() == -1)
        return _ctlist.at(index.row());
    else
        return _ctlist.at(index.internalId());
}
