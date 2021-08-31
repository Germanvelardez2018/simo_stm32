#include "simo/config.h"
#include "simo/core.h"

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_uart.h"







#if         STM32BOARD == 1

            #define      N_UART          3
            #define      TIMEOUT         20
            #define      RX_TIMEOUT      TIMEOUT
            #define      TX_TIMEOUT      TIMEOUT
         
            #ifndef SIMO_UART
                #define SIMO_UART
                typedef enum
                {
                    UART1,
                    UART2,
                    UART3
                }uart_instance;

               
            #endif




#else
    #define nada


#endif