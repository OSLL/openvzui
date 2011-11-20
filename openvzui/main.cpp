#include <QApplication>
#include "cvzcentralwidget.h"

int main (int argc, char **argv)
{
    QApplication app(argc, argv);
    CVZCentralWidget *window = new CVZCentralWidget();
    window->show();
    return app.exec();
}
