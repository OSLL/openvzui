#ifndef CCONTAINERTREEMODEL_H
#define CCONTAINERTREEMODEL_H

#include <QAbstractItemModel>
#include <QList>
#include "container.h"

class CContainerTreeModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    CContainerTreeModel(QObject * parent = 0);

    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    virtual QModelIndex parent(const QModelIndex &child = QModelIndex()) const;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;

public slots:
    void update(const QList<struct container_t> &lst);

private:
    QList<struct container_t> _ctlist;
};

#endif // CCONTAINERTREEMODEL_H
