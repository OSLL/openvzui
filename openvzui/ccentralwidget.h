#ifndef CCENTRALWIDGET_H
#define CCENTRALWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QStringList>
#include <QTreeView>

#include "ctree.h"
#include "container.h"
#include "ccontainertreemodel.h"

class CCentralWidget : public QWidget
{
    Q_OBJECT

public:
    CCentralWidget(QWidget *parent = 0);

public slots:
    void updateTree(const QList<struct container_t> &lst);

signals:
    void startContainer(const QString &name);
    void stopContainer(const QString &name);
    void updateContainer();

private:
    QPushButton *_startButton;
    QPushButton *_stopButton;
    QPushButton *_updateButton;
    CTree *_ctree;
    CContainerTreeModel *_model;
    QTreeView *_view;

private slots:
    void enableButtons();
    void startCt();
    void stopCt();
    void updateCt();
};

#endif // CCENTRALWIDGET_H
