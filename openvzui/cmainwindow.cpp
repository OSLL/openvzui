#include <QVBoxLayout>
#include <QHBoxLayout>

#include "cmainwindow.h"

CMainWindow::CMainWindow(QWidget *parent)
    :QMainWindow(parent)
{
    _main = new CCentralWidget(this);
    _parser = new CListParser(this);

    connect(_parser, SIGNAL(updated(QList<struct container_t>)), _main, SLOT(updateTree(QList<struct container_t>)));
    connect(_main, SIGNAL(updateContainer()), _parser, SLOT(execute()));
    connect(_main, SIGNAL(startContainer(QString)), this, SLOT(startContainer(QString)));
    connect(_main, SIGNAL(stopContainer(QString)), this, SLOT(stopContainer(QString)));

    setCentralWidget(_main);
    _parser->execute();
}

void CMainWindow::startContainer(const QString &name)
{
}

void CMainWindow::stopContainer(const QString &name)
{
}
