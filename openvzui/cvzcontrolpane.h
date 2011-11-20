#ifndef CVZCONTROLPANE_H
#define CVZCONTROLPANE_H

#include <QWidget>
#include <QPushButton>

class CVZControlPane : public QWidget
{
    Q_OBJECT

    QPushButton * _startButton;
    QPushButton * _stopButton;
    QPushButton * _updateButton;

public:
    explicit CVZControlPane(QWidget *parent = 0);

signals:
    void startClicked();
    void stopClicked();
    void updateClicked();

public slots:
    void enableStopButton(bool state);
    void enableStartButton(bool state);
    void enableUpdateButton(bool state);
};

#endif // CVZCONTROLPANE_H
