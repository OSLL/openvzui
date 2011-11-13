#include "clistparser.h"

CListParser::CListParser(qint32 interval, QObject *parent)
    : QObject(parent), cmd("vzlist"), args("-a"),
      pattern("(\\w+)\\s+(-|\\d+)\\s+(running|stopped)")
{
    timer.setInterval(interval);
    connect(&timer, SIGNAL(timeout()), this, SLOT(onTime()));
    connect(&proc, SIGNAL(readyReadStandardOutput()), this, SLOT(readOutput()));
}

QString CListParser::getCMD() const
{
    return cmd + args.join(" ");
}

void CListParser::setInterval(qint32 interval)
{
    timer.stop();
    timer.setInterval(interval);
}

void CListParser::start()
{
    timer.start();
}

void CListParser::execute()
{
    proc.start(cmd, args, QIODevice::ReadOnly);
}

void CListParser::onTime()
{
    execute();
}

void CListParser::readOutput()
{
    proc.waitForFinished(-1);
    QString output(proc.readAllStandardOutput());
    QStringList list = output.split('\n');
    list.removeFirst();

    QList<struct container_t> result;

    QStringList::const_iterator it = list.begin();
    while (it != list.end()) {
        if (pattern.indexIn(*it) > -1) {
            container_t ct;
            ct.ctid = pattern.cap(1);
            if (pattern.cap(2) == "-")
                ct.nproc = 0;
            else
                ct.nproc = pattern.cap(2).toInt();
            if (pattern.cap(3) == "running")
                ct.status = Running;
            else
                ct.status = Stopped;
            result.append(ct);
        }
        ++it;
    }

    emit updated(result);
}
