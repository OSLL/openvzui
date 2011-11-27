#include <QFile>
#include <QTextStream>

#include "../common.h"


int main()
{
    QFile lst(FILENAME);
    lst.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&lst);
    QTextStream out(stdout);

    while (!in.atEnd()) {
        QString line = in.readLine();
        out << line << endl;
    }
    lst.close();

    return 0;
}
