#include <QSlider>
#include <QBoxLayout>
#include <QLabel>
#include <QComboBox>
#include "selectmonitor.h"

class Slider : public QObject
{
    Q_OBJECT

    QSlider *s;
    QLabel *lVal;
    DDCA_Display_Handle display;
    int controlnum;
public:
    Slider(QBoxLayout *, SelectMonitor *, QString, int);
    void setValue(int val){s->setValue(val);}

public slots:
    void setVal(int val);
    void update(DDCA_Display_Handle);
};

class DropDown : public QObject
{
    Q_OBJECT

    QComboBox *cb;
    DDCA_Display_Handle display;
    int controlnum;
public:
    DropDown(QBoxLayout *, SelectMonitor *, QString, int);
    void setValue(int val){cb->setCurrentIndex(val);}

public slots:
    void setVal(int val);
    void update(DDCA_Display_Handle);
};
