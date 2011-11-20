#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>

#include "clistparser.h"
#include "ctree.h"
#include "ccentralwidget.h"

class CMainWindow : public QMainWindow
{
    Q_OBJECT

private:
    CCentralWidget *_main;
    CListParser *_parser;

private slots:
    void startContainer(const QString &name);
    void stopContainer(const QString &name);

public:
    CMainWindow(QWidget *parent = 0);
};

#endif // CMAINWINDOW_H
