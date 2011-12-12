#include <QDebug>
#include <QtAlgorithms>
#include "cvzlistexec.h"

CVZListExec::CVZListExec(QObject *parent) :
    QObject(parent), _cmd("vzlist"), _args("-a")
{
    connect(&_proc, SIGNAL(finished(int)), this, SLOT(readCmdOutput()));
}

void CVZListExec::execute()
{
    _proc.start(_cmd, _args, QProcess::ReadOnly);
}

void CVZListExec::readCmdOutput()
{
    QString procout(_proc.readAllStandardOutput());
    QStringList outlist = procout.split('\n');

    qDebug() << procout;

    QList<CVZContainer> result;
    QStringList::const_iterator it = outlist.begin();
    while (it != outlist.end()) {
        CVZContainer ct(*it);
        if (ct.isValid())
            result.append(ct);
        ++it;
    }
    qSort(result.begin(), result.end());

    emit update(result);
}
