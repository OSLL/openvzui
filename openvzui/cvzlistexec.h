#ifndef CVZLISTEXEC_H
#define CVZLISTEXEC_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QProcess>

#include "cvzcontainer.h"

class CVZListExec : public QObject
{
    Q_OBJECT

    QProcess _proc;

private slots:
    void readCmdOutput();

public:
    explicit CVZListExec(QObject *parent = 0);

    static const QString _vzlistcmd;
    static const QString _listall;
signals:
    void update(const QList<CVZContainer> &list);

public slots:
    void execute();
};

#endif // CVZLISTEXEC_H
