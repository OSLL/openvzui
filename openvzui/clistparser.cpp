#include <QDebug>
#include "clistparser.h"

CListParser::CListParser(QObject *parent)
    : QObject(parent), _cmd("vzlist"), _args("-a"),
      _pattern("(\\w+)\\s+(-|\\d+)\\s+(running|stopped)"), _proc(new QProcess(this))
{
    connect(_proc, SIGNAL(readyReadStandardOutput()), this, SLOT(readOutput()));
}

QString CListParser::getCMD() const
{
    return _cmd + _args.join(" ");
}

void CListParser::execute()
{
    _proc->start(_cmd, _args, QIODevice::ReadOnly);
}

void CListParser::readOutput()
{
    _proc->waitForFinished(-1);
    QString output(_proc->readAllStandardOutput());
    QStringList list = output.split('\n');
    list.removeFirst();

    qDebug() << output;

    QList<struct container_t> result;

    QStringList::const_iterator it = list.begin();
    while (it != list.end()) {
        if (_pattern.indexIn(*it) > -1) {
            container_t ct;
            ct._ctid = _pattern.cap(1);
            if (_pattern.cap(2) == "-")
                ct._nproc = 0;
            else
                ct._nproc = _pattern.cap(2).toInt();
            if (_pattern.cap(3) == "running")
                ct._status = Running;
            else
                ct._status = Stopped;
            result.append(ct);
        }
        ++it;
    }

    emit updated(result);
}
