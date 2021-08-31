#include "simo/app/app.h"







static void  _init_config();
static void  _init_timers();
static void   _init_irqs();
static void  _init_uart();
static void  _init_wdt();





void init_app(void)
{


      _init_config();
      _init_timers();
      _init_irqs();
      _init_uart();
      _init_wdt();
}



