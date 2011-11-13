#ifndef CCENTRALWIDGET_H
#define CCENTRALWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QStringList>

#include "ctree.h"
#include "container.h"

class CCentralWidget : public QWidget
{
    Q_OBJECT

public:
    CCentralWidget(QWidget *parent = 0);

private:
    QPushButton *startButton;
    QPushButton *stopButton;
    CTree *ctree;

public slots:
    void updateTree(QList<struct container_t> lst);

private slots:
    void enableButtons();
    void startCt();
    void stopCt();

signals:
    void startContainer(QString name);
    void stopContainer(QString name);
};

#endif // CCENTRALWIDGET_H
