#include <QDebug>

#include "cvzresourceparser.h"

const QString CVZResourceParser::_cmd = "cat";
const QString CVZResourceParser::_procdir = "/proc/bc/";
const QString CVZResourceParser::_resourcefile = "/resources";

CVZResourceParser::CVZResourceParser(QObject *parent) :
    QObject(parent)
{
    connect(&_proc, SIGNAL(finished(int)), this, SLOT(readCmdOutput()));
}

void CVZResourceParser::execute(QString ctid)
{
    QStringList args;
    args << _procdir + ctid + _resourcefile;
    _proc.start(_cmd, args, QProcess::ReadOnly);
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
