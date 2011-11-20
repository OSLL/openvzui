#ifndef CVZCENTRALWIDGET_H
#define CVZCENTRALWIDGET_H

#include <QWidget>
#include <QTreeView>
#include <QString>

#include "cvzcontrolpane.h"
#include "cvzmodel.h"
#include "cvzlistexec.h"

class CVZCentralWidget : public QWidget
{
    Q_OBJECT

    CVZControlPane * _ctl;
    CVZModel * _model;
    QTreeView * _view;
    CVZListExec * _listcmd;
    QString _current;

private slots:
    void updateCtl(const QModelIndex &index);

public:
    explicit CVZCentralWidget(QWidget *parent = 0);

signals:
    void enableStart(bool);
    void enableStop(bool);

public slots:

};

#endif // CVZCENTRALWIDGET_H
