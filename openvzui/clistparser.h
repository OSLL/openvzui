#ifndef CLISTPARSER_H
#define CLISTPARSER_H

#include <QString>
#include <QStringList>
#include <QRegExp>
#include <QTimer>
#include <QProcess>

#include "container.h"

class CListParser : public QObject
{
    Q_OBJECT

public:
    QString cmd;
    QStringList args;
    QRegExp pattern;
    QTimer timer;
    QProcess proc;

private slots:
    void readOutput();
    void onTime();

public:
    CListParser(qint32 interval = 3000, QObject * parent = 0);
    QString getCMD() const;
    void setInterval(qint32 val);

public slots:
    void start();
    void execute();

signals:
    void updated(QList<struct container_t> list);
};

#endif // CLISTPARSER_H
