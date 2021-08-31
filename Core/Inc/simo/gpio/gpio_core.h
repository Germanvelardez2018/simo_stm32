
#include "simo/config.h"
#include "simo/core.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"






typedef enum{
    OUTPUT_PIN,
    INPUT_PIN,
    ANALOG_PIN
} gpio_mode;



typedef enum {
    PIN_LOW ,
    PIN_HIGH
} gpio_level;






#if         STM32BOARD == 1



              //STM32F103CBT6
              //abstraccion simple...pines numericos en vez de puerto y numero de pin.
              #define    PPPORT              16
              #define    PORTS_DEFINED       2
              #define    N_PINES            PORTS_DEFINED * PPPORT
              
              #define     A0                  0
              #define     A1                  1
              #define     A2                  2
              #define     A3                  3
              #define     A4                  4
              #define     A5                  5
              #define     A6                  6
              #define     A7                  7
              #define     A8                  8
              #define     A9                  9
              #define     A10                 10
              #define     A11                 11
              #define     A12                 12
              #define     A13                 13
              #define     A14                 14
              #define     A15                 15


              #define     B0                  16
              #define     B1                  17
              #define     B2                  18
              #define     B3                  19
              #define     B4                  20
              #define     B5                  21
              #define     B6                  22
              #define     B7                  23
              #define     B8                  24
              #define     B9                  25
              #define     B10                 26
              #define     B11                 27
              #define     B12                 28
              #define     B13                 29
              #define     B14                 30
              #define     B15                 31


    //struct needed for stm32 devices
 
            typedef struct 
            {

                GPIO_TypeDef    *port;
                uint16_t         pin;
                
            } simo_pin ;


#else


//other pins definitions


#endif