#include "selectmonitor.h"

SelectMonitor::SelectMonitor()
{
    ddca_init2(NULL,DDCA_SYSLOG_NEVER,DDCA_INIT_OPTIONS_NONE,NULL);
    ddca_get_display_info_list2(false,&displays);
}

void SelectMonitor::change(int id)
{
    ddca_close_display(dh);
    ddca_open_display2(displays->info[id].dref,true,&dh);
    emit screenOpen(dh);
}
