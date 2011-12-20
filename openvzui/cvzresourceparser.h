#ifndef CVZRESOURCEPARSER_H
#define CVZRESOURCEPARSER_H

#include <QObject>
#include <QProcess>

#include "cvzresource.h"

class CVZResourceParser : public QObject
{
    Q_OBJECT

    QProcess _proc;

private slots:
    void readCmdOutput();

public:
    explicit CVZResourceParser(QObject *parent = 0);

    static const QString _cmd;
    static const QString _procdir;
    static const QString _resourcefile;

signals:
    void update(const QList<CVZResource> &list);

public slots:
    void execute(QString ctid);
};

#endif // CVZRESOURCEPARSER_H
