
#include "simo/gpio/gpio_core.h"   





/**
  * @brief GPIO Initialization Function
  * @param int8_t: pin to start
  * @retval None
  */
void gpio_init(int8_t pin, gpio_mode mode);


/**
  * @brief GPIO Deinitialization Function
  * @param int8_t: pin to disable
  * @retval None
  */
void gpio_deinit(int8_t pin );


/**
  * @brief GPIO read function
  * @param int8_t: pin number.
  * @retval gpio_level: level pin              
  */
gpio_level gpio_read(int8_t pin);


/**
  * @brief GPIO write Function
  * @param int8_t: pin_number
  * @retval None
  */
void gpio_write(int8_t pin,gpio_level level);





