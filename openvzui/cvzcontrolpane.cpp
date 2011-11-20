#include <QHBoxLayout>
#include "cvzcontrolpane.h"

CVZControlPane::CVZControlPane(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout *main = new QHBoxLayout;
    _startButton = new QPushButton(tr("start"));
    _stopButton = new QPushButton(tr("stop"));
    _updateButton = new QPushButton(tr("update"));

    _startButton->setEnabled(false);
    _stopButton->setEnabled(false);
    _updateButton->setEnabled(true);

    main->addWidget(_startButton);
    main->addWidget(_stopButton);
    main->addWidget(_updateButton);

    connect(_startButton, SIGNAL(clicked()), this, SIGNAL(startClicked()));
    connect(_stopButton, SIGNAL(clicked()), this, SIGNAL(stopClicked()));
    connect(_updateButton, SIGNAL(clicked()), this, SIGNAL(updateClicked()));

    setLayout(main);
}

void CVZControlPane::enableStartButton(bool state)
{
    _startButton->setEnabled(state);
}

void CVZControlPane::enableStopButton(bool state)
{
    _stopButton->setEnabled(state);
}

void CVZControlPane::enableUpdateButton(bool state)
{
    _updateButton->setEnabled(state);
}
