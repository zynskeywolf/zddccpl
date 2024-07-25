#include "Widgets.h"

Slider::Slider(QBoxLayout *parent, SelectMonitor *sm, QString label, int c)
{
    controlnum = c;
    parent->addWidget(new QLabel(label));
    QWidget *wSliderWithValue = new QWidget();
    parent->addWidget(wSliderWithValue);
    QHBoxLayout *lSliderWithValue = new QHBoxLayout();
    wSliderWithValue->setLayout(lSliderWithValue);
    s = new QSlider(Qt::Horizontal);
    lSliderWithValue->addWidget(s);
    lVal = new QLabel();
    lVal->setFixedWidth(24);
    lSliderWithValue->addWidget(lVal);
    connect(sm,SIGNAL(screenOpen(DDCA_Display_Handle)),this,SLOT(update(DDCA_Display_Handle)));
}

void Slider::setVal(int val)
{
    lVal->setText(QString::number(val));
    ddca_set_non_table_vcp_value(display,controlnum,0,val);
}

void Slider::update(DDCA_Display_Handle d)
{
    disconnect(s,SIGNAL(valueChanged(int)),this,SLOT(setVal(int)));
    display = d;
    DDCA_Non_Table_Vcp_Value val;
    ddca_get_non_table_vcp_value(d,controlnum,&val);
    s->setRange(0,val.ml);
    s->setValue(val.sl);
    lVal->setText(QString::number(val.sl));
    connect(s,SIGNAL(valueChanged(int)),this,SLOT(setVal(int)));
}

DropDown::DropDown(QBoxLayout *parent, SelectMonitor *sm, QString label, int c)
{
    controlnum = c;
    parent->addWidget(new QLabel(label));
    cb = new QComboBox();
    parent->addWidget(cb);
    connect(sm,SIGNAL(screenOpen(DDCA_Display_Handle)),this,SLOT(update(DDCA_Display_Handle)));
}

void DropDown::setVal(int val)
{
    ddca_set_non_table_vcp_value(display,controlnum,0,val+1);
}

void DropDown::update(DDCA_Display_Handle d)
{
    display = d;
    DDCA_Non_Table_Vcp_Value val;
    ddca_get_non_table_vcp_value(d,controlnum,&val);
    DDCA_Feature_Metadata *meta;
    ddca_get_feature_metadata_by_dh(controlnum,d,false,&meta);
    disconnect(cb,SIGNAL(currentIndexChanged(int)),this,SLOT(setVal(int)));
    for(int i=0;i<=val.ml;i++)
    {

        cb->addItem(QString(meta->sl_values[i].value_name));
    }
    cb->setCurrentIndex(val.sl-1);
    connect(cb,SIGNAL(currentIndexChanged(int)),this,SLOT(setVal(int)));
}
