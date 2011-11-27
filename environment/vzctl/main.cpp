#include <QFile>
#include <QTextStream>
#include <QString>
#include <QList>
#include <QDebug>

#include "../../openvzui/cvzcontainer.h"
#include "../common.h"

QList<CVZContainer> readCfgFile()
{
    QFile cfg(FILENAME);
    cfg.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&cfg);
    QList<CVZContainer> result;
    while (!in.atEnd()) {
        CVZContainer ct(in.readLine());
        if (ct.isValid()) {
            result.append(ct);
            qDebug() << "Read:" << static_cast<QString>(ct);
        }
    }
    cfg.close();

    return result;
}

void writeCfgFile(const QList<CVZContainer> &lst)
{
    QFile cfg(FILENAME);
    cfg.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);

    QTextStream out(&cfg);
    QList<CVZContainer>::const_iterator it = lst.begin();
    while (it != lst.end()) {
        out << static_cast<QString>(*it) << endl;
        qDebug() << "Write: " << static_cast<QString>(*it);
        ++it;
    }

    cfg.close();
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        QTextStream err(stderr);
        err << "test environment vzctl usage:" << endl
            << "vzctl (start | stop | add) <ctid>" << endl
            << "where <ctid> - container id" << endl;
    }
    qsrand(1);

    QList<CVZContainer> lst = readCfgFile();

    QString cmd(argv[1]);
    QString ctid(argv[2]);
    int pos = lst.indexOf(ctid);

    if (cmd == "start") {
        lst[pos].setStatus(CVZContainer::Running);
        lst[pos].setNProc(qrand()%128 + 1);
    } else if (cmd == "stop") {
        lst[pos].setStatus(CVZContainer::Stopped);
        lst[pos].setNProc(0);
    } else if (cmd == "add") {
        lst.append(CVZContainer(ctid, CVZContainer::Stopped, 0));
    }
    writeCfgFile(lst);

    return 0;
}
