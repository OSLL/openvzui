#include <QVBoxLayout>
#include <QHBoxLayout>

#include "cmainwindow.h"

CMainWindow::CMainWindow(QWidget *parent)
    :QMainWindow(parent)
{
    main = new CCentralWidget;

    connect(&parser, SIGNAL(updated(QList<struct container_t>)), main, SLOT(updateTree(QList<struct container_t>)));
    connect(main, SIGNAL(startContainer(QString)), this, SLOT(startContainer(QString)));
    connect(main, SIGNAL(stopContainer(QString)), this, SLOT(stopContainer(QString)));

    setCentralWidget(main);
    parser.execute();
}

void CMainWindow::startContainer(QString name)
{
}

void CMainWindow::stopContainer(QString name)
{
}
