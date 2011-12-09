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
    QProcess * _util;
    QString _current;
    QString _ctCmd;

private slots:
    void updateCtl(const QModelIndex &index);
    void runCt();
    void stopCt();

public:
    explicit CVZCentralWidget(QWidget *parent = 0);

signals:
    void enableStart(bool);
    void enableStop(bool);

public slots:

};

#endif // CVZCENTRALWIDGET_H
