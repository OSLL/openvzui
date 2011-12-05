#ifndef CVZMODEL_H
#define CVZMODEL_H

#include <QAbstractItemModel>
#include <QString>
#include <QList>

#include "cvzcontainer.h"

#define PROPCOUNT 2

class CVZModel : public QAbstractItemModel
{
    Q_OBJECT

    QList<CVZContainer> _ctlist;

public:
    CVZModel(QObject * parent = 0);

    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index = QModelIndex(), int role = Qt::DisplayRole) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    virtual QModelIndex parent(const QModelIndex &child = QModelIndex()) const;

    CVZContainer getSelectedContainer(const QModelIndex &index) const;

public slots:
    void update(const QList<CVZContainer> &lst);
};

#endif // CVZMODEL_H
