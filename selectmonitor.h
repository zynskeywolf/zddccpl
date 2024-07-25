#include <QObject>
#include <ddcutil_c_api.h>

class SelectMonitor : public QObject
{
    Q_OBJECT
public:
    DDCA_Display_Info_List *displays;
    DDCA_Display_Handle dh;
    SelectMonitor();
public slots:
    void change(int);
signals:
    void screenOpen(DDCA_Display_Handle);
};
