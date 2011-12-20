#ifndef CVZRESOURCE_H
#define CVZRESOURCE_H

#include <QString>
#include <QRegExp>

class CVZResource
{
    QString _resourceName;
    quint32 _held;
    quint32 _maxheld;
    quint32 _barrier;
    quint32 _limit;
    quint32 _failcnt;

public:
    CVZResource(const QString &description);
    CVZResource(QString resourceName, quint32 held, quint32 maxheld, quint32 barrier, quint32 limit, quint32 failcnt);

    QString getResourceName(void) const;
    quint32 getHeld(void) const;
    quint32 getMaxheld(void) const;
    quint32 getBarrier(void) const;
    quint32 getLimit(void) const;
    quint32 getFailcnt(void) const;

    quint32 getPersent(void) const;
    static const QRegExp _pattern;
};

#endif // CVZRESOURCE_H
