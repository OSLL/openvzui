#include <QDebug>
#include "cvzresourceparser.h"

CVZResourceParser::CVZResourceParser(QObject *parent) :
    QObject(parent), _cmd("cat")
{
    connect(&_proc, SIGNAL(finished(int)), this, SLOT(readCmdOutput()));
}

void CVZResourceParser::execute(QString args)
{
    _ctid = args;
    _args.clear();
    _args << "/proc/bc/" + _ctid + "/resources";
    _proc.start(_cmd, _args, QProcess::ReadOnly);
}

void CVZResourceParser::readCmdOutput()
{
    QString procout(_proc.readAllStandardOutput());
    QStringList outlist = procout.split('\n');

    qDebug() << procout;

    QList<CVZResource> result;
    QStringList::const_iterator it = outlist.begin();
    while (it != outlist.end()-1)
    {
        CVZResource ct(*it);
        result.append(ct);
        ++it;
    }

    emit update(result);
}
