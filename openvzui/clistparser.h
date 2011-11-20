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
    CListParser(QObject * parent = 0);
    QString getCMD() const;

public slots:
    void execute();

signals:
    void updated(QList<struct container_t> list);

private:
    const QString _cmd;
    const QStringList _args;
    const QRegExp _pattern;
    QProcess * _proc;

private slots:
    void readOutput();
};

#endif // CLISTPARSER_H
