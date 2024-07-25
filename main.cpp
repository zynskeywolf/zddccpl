#include <QApplication>
#include <QMainWindow>
#include <QComboBox>
#include <QTabWidget>
#include "Widgets.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow *win = new QMainWindow();
    win->resize(480, 480);
    win->setWindowTitle("Monitor settings");
    QWidget *container = new QWidget(win);
    container->resize(480, 480);
    QVBoxLayout *l = new QVBoxLayout();
    container->setLayout(l);
    QComboBox *cbMon = new QComboBox();
    l->addWidget(cbMon);
    QTabWidget *tab = new QTabWidget();
    l->addWidget(tab);

    SelectMonitor *sm = new SelectMonitor();
    for (int i=0;i<sm->displays->ct;i++)
        cbMon->addItem(QString(sm->displays->info[i].mfg_id)+" "+QString(sm->displays->info[i].model_name));
    QObject::connect(cbMon,SIGNAL(currentIndexChanged(int)),sm,SLOT(change(int)));

    // Controls

    QWidget *wGen = new QWidget();
    QBoxLayout *lGen = new QBoxLayout(QBoxLayout::TopToBottom);
    wGen->setLayout(lGen);
    tab->addTab(wGen,"General");

    new Slider(lGen,sm,"Brightness / Backlight",0x10);
    new Slider(lGen,sm,"Contrast",0x12);
    new Slider(lGen,sm,"Sharpness",0x87);
    new DropDown(lGen,sm,"Colour temperature preset",0x14);
    lGen->addStretch();

    QWidget *wRGB = new QWidget();
    QBoxLayout *lRGB = new QBoxLayout(QBoxLayout::TopToBottom);
    wRGB->setLayout(lRGB);
    tab->addTab(wRGB,"RGB");

    new Slider(lRGB,sm,"R gain",0x16);
    new Slider(lRGB,sm,"G gain",0x18);
    new Slider(lRGB,sm,"B gain",0x1a);
    new Slider(lRGB,sm,"R bias",0x6c);
    new Slider(lRGB,sm,"G bias",0x6e);
    new Slider(lRGB,sm,"B bias",0x70);
    lRGB->addStretch();

    QWidget *w6ax = new QWidget();
    QBoxLayout *l6ax = new QBoxLayout(QBoxLayout::TopToBottom);
    w6ax->setLayout(l6ax);
    tab->addTab(w6ax,"6-axis saturation");

    new Slider(l6ax,sm,"Red",0x59);
    new Slider(l6ax,sm,"Yellow",0x5a);
    new Slider(l6ax,sm,"Green",0x5b);
    new Slider(l6ax,sm,"Cyan",0x5c);
    new Slider(l6ax,sm,"Blue",0x5d);
    new Slider(l6ax,sm,"Magenta",0x5e);
    l6ax->addStretch();

    QWidget *wSnc = new QWidget();
    QBoxLayout *lSnc = new QBoxLayout(QBoxLayout::TopToBottom);
    wSnc->setLayout(lSnc);
    tab->addTab(wSnc,"Sync");

    new Slider(lSnc,sm,"H position",0x20);
    new Slider(lSnc,sm,"V position",0x30);
    new Slider(lSnc,sm,"Pixel clock",0x0e);
    new Slider(lSnc,sm,"Phase",0x3e);
    lSnc->addStretch();

    sm->change(0);
    win->show();
    return app.exec();
}
