#ifndef CVZRESOURCEPANEL_H
#define CVZRESOURCEPANEL_H

#include <QWidget>
#include <QLabel>
#include <QProgressBar>
#include <QScrollArea>

#include "cvzresource.h"

class CVZResourcePanel : public QWidget
{
    Q_OBJECT

    QLabel *_resLabel[21];
    QLabel *_resCurValue[21];
    QLabel *_resMaxValue[21];
    QProgressBar *_resVision[21];

    QWidget *widgetForResourceItem;
    QScrollArea *scrollArea;
public:
    explicit CVZResourcePanel(QWidget *parent = 0);

public slots:
    void update(const QList<CVZResource> &lst);
};

#endif // CVZRESOURCEPANEL_H
