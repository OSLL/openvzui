#ifndef CVZCONTAINER_H
#define CVZCONTAINER_H

#include <QString>
#include <QRegExp>

class CVZContainer
{
public:
    enum VZContainerStatus {Running, Stopped, WrongState};

private:
    VZContainerStatus _status;
    quint32 _nproc;
    QString _ctid;

    void validate() const;

public:
    CVZContainer(const QString & description);
    QString ctid() const;
    quint32 nproc() const;
    VZContainerStatus status() const;
    bool isValid() const;

    static const QRegExp _pattern;
};

#endif // CVZCONTAINER_H
