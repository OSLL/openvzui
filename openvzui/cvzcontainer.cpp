#include <QDebug>
#include "cvzcontainer.h"

const QRegExp CVZContainer::_pattern = QRegExp("(\\w+)\\s+(-|\\d+)\\s+(running|stopped)");

CVZContainer::CVZContainer(const QString &description)
    : _status(CVZContainer::WrongState), _nproc(0)
{
    if (CVZContainer::_pattern.indexIn(description) > -1) {
        _ctid = _pattern.cap(1);

        QString nproc = _pattern.cap(2);
        if (nproc != "-")
            _nproc = nproc.toInt();

        QString status = _pattern.cap(3);
        if (status == "running")
            _status = CVZContainer::Running;
        else if (status == "stopped")
            _status = CVZContainer::Stopped;
        else
            _status = CVZContainer::WrongState;
    }
}

void CVZContainer::validate() const
{
    if (!isValid())
        qDebug() << "CVZContainer is not valid";
}

QString CVZContainer::ctid() const
{
    validate();
    return _ctid;
}

quint32 CVZContainer::nproc() const
{
    validate();
    return _nproc;
}

CVZContainer::VZContainerStatus CVZContainer::status() const
{
    validate();
    return _status;
}

bool CVZContainer::isValid() const
{
    return (_status != CVZContainer::WrongState);
}
