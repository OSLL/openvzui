#ifndef CVZRESOURCEPARSER_H
#define CVZRESOURCEPARSER_H

#include <QObject>
#include <QProcess>

#include "cvzresource.h"

class CVZResourceParser : public QObject
{
    Q_OBJECT

    QString _ctid;
    const QString _cmd;
    QStringList _args;
    QProcess _proc;

private slots:
    void readCmdOutput();

public:
    explicit CVZResourceParser(QObject *parent = 0);

signals:
    void update(const QList<CVZResource> &list);

public slots:
    void execute(QString args);
};

#endif // CVZRESOURCEPARSER_H
