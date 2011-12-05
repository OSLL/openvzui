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
    CVZContainer(const QString &description);
    CVZContainer(const QString &ctid, VZContainerStatus status, quint32 nproc);

    QString ctid() const;
    quint32 nproc() const;
    VZContainerStatus status() const;

    void setStatus(enum VZContainerStatus status);
    void setNProc(quint32 nproc);

    bool isValid() const;
    bool isStatusChanged(const CVZContainer &ct) const;
    bool isNProcessChanged(const CVZContainer &ct) const;
    bool operator<(const CVZContainer &ct) const;
    bool operator>(const CVZContainer &ct) const;
    bool operator==(const CVZContainer &ct) const;
    bool operator!=(const CVZContainer &ct) const;

    operator QString() const;

    static const QRegExp _pattern;
};

#endif // CVZCONTAINER_H
