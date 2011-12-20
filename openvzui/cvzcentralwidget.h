#ifndef CVZCENTRALWIDGET_H
#define CVZCENTRALWIDGET_H

#include <QWidget>
#include <QTreeView>
#include <QString>

#include "cvzcontrolpane.h"
#include "cvzmodel.h"
#include "cvzlistexec.h"
#include "cvzresourcepanel.h"
#include "cvzresourceparser.h"

class CVZCentralWidget : public QWidget
{
    Q_OBJECT

    CVZControlPane * _ctl;
    CVZResourcePanel * _res;
    CVZResourceParser * _pars;
    CVZModel * _model;
    QTreeView * _view;
    CVZListExec * _listcmd;
    QProcess * _util;
    QString _current;
    bool _currentRunning;

private slots:
    void updateCtl(const QModelIndex &index);
    void runCt();
    void stopCt();
    void timerEvent(QTimerEvent *);

public:
    explicit CVZCentralWidget(QWidget *parent = 0);

    static const QString _vzctlcmd;
    static const QString _ctstart;
    static const QString _ctstop;

signals:
    void enableStart(bool);
    void enableStop(bool);
};

#endif // CVZCENTRALWIDGET_H
