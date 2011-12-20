#include "cvzresource.h"

const QRegExp CVZResource::_pattern = QRegExp("(\\w+)\\s+(\\d+)\\s+(\\d+)\\s+(\\d+)\\s+(\\d+)\\s+(\\d+)");

CVZResource::CVZResource(const QString &description)
{
    if (CVZResource::_pattern.indexIn(description) > -1)
    {
        QString temp;
        _resourceName = _pattern.cap(1);
        temp = _pattern.cap(2);
        _held = temp.toInt();
        temp = _pattern.cap(3);
        _maxheld = temp.toInt();
        temp = _pattern.cap(4);
        _barrier = temp.toInt();
        temp = _pattern.cap(5);
        _limit = temp.toInt();
        temp = _pattern.cap(6);
        _failcnt = temp.toInt();
    }
}


CVZResource::CVZResource(QString resourceName, quint32 held, quint32 maxheld, quint32 barrier, quint32 limit, quint32 failcnt):
        _resourceName(resourceName), _held(held), _maxheld(maxheld), _barrier(barrier), _limit(limit), _failcnt(failcnt)
{}

QString CVZResource::getResourceName(void) const
{
    return _resourceName;
}

quint32 CVZResource::getHeld(void) const
{
    return _held;
}

quint32 CVZResource::getMaxheld(void) const
{
    return _maxheld;
}

quint32 CVZResource::getBarrier(void) const
{
    return _barrier;
}

quint32 CVZResource::getLimit(void) const
{
    return _limit;
}

quint32 CVZResource::getFailcnt(void) const
{
    return _failcnt;
}

quint32 CVZResource::getPersent(void) const
{
    quint32 result = 100;
    if(_held < _limit)
        result = (_held * 100) / _limit;
    return result;
}
