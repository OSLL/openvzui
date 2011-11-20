#ifndef CVZLISTEXEC_H
#define CVZLISTEXEC_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QProcess>

#include "cvzcontainer.h"

#define TIMEDELAY 1000

class CVZListExec : public QObject
{
    Q_OBJECT

    const QString _cmd;
    const QStringList _args;
    QProcess _proc;

private slots:
    void readCmdOutput();

public:
    explicit CVZListExec(QObject *parent = 0);

signals:
    void update(const QList<CVZContainer> &list);

public slots:
    void execute();
};

#endif // CVZLISTEXEC_H
