#include "simo/gpio/gpio.h"






static simo_pin _GPIO_[N_PINES]=
{

    //PortA

    [A0]= { GPIOA,GPIO_PIN_0},
    [A1]= { GPIOA,GPIO_PIN_1},
    [A2]= { GPIOA,GPIO_PIN_2},
    [A3]= { GPIOA,GPIO_PIN_3},
    [A4]= { GPIOA,GPIO_PIN_4},
    [A5]= { GPIOA,GPIO_PIN_5},
    [A6]= { GPIOA,GPIO_PIN_6},
    [A7]= { GPIOA,GPIO_PIN_7},
    [A8]= { GPIOA,GPIO_PIN_8},
    [A9]= { GPIOA,GPIO_PIN_9},
    [A10]={ GPIOA,GPIO_PIN_10},
    [A11]={ GPIOA,GPIO_PIN_11},
    [A12]={ GPIOA,GPIO_PIN_12},
    [A13]={ GPIOA,GPIO_PIN_13},
    [A14]={ GPIOA,GPIO_PIN_14},
    [A15]={ GPIOA,GPIO_PIN_15},


    //PortB

    [B0]= { GPIOB,GPIO_PIN_0},
    [B1]= { GPIOB,GPIO_PIN_1},
    [B2]= { GPIOB,GPIO_PIN_2},
    [B3]= { GPIOB,GPIO_PIN_3},
    [B4]= { GPIOB,GPIO_PIN_4},
    [B5]= { GPIOB,GPIO_PIN_5},
    [B6]= { GPIOB,GPIO_PIN_6},
    [B7]= { GPIOB,GPIO_PIN_7},
    [B8]= { GPIOB,GPIO_PIN_8},
    [B9]= { GPIOB,GPIO_PIN_9},
    [B10]={ GPIOB,GPIO_PIN_10},
    [B11]={ GPIOB,GPIO_PIN_11},
    [B12]={ GPIOB,GPIO_PIN_12},
    [B13]={ GPIOB,GPIO_PIN_13},
    [B14]={ GPIOB,GPIO_PIN_14},
    [B15]={ GPIOB,GPIO_PIN_15},


    //Port C   // NO DEFINED 




};


void gpio_init(int8_t pin, gpio_mode mode)
{

   


     GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(_GPIO_[pin].port, _GPIO_[pin].pin, GPIO_PIN_RESET);

    /*Configure GPIO pin : LED_PIN_Pin */
    GPIO_InitStruct.Pin = _GPIO_[pin].pin;



    switch (mode)
    {
    case OUTPUT_PIN:
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;

        break;
    case INPUT_PIN:
          GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
          GPIO_InitStruct.Pull = GPIO_PULLUP;

          break;
    case ANALOG_PIN:
          GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
          GPIO_InitStruct.Pull = GPIO_PULLDOWN;
          break;
    default:
           //default config
        break;
    }

    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(_GPIO_[pin].port, &GPIO_InitStruct);


}






void gpio_deinit(int8_t pin )
{
    HAL_GPIO_DeInit(_GPIO_[pin].port,_GPIO_[pin].pin);
    return SYSTEM_OK;
}


gpio_level gpio_read(int8_t pin)
{
  return (gpio_level)HAL_GPIO_ReadPin(_GPIO_[pin].port,_GPIO_[pin].pin);
}



void gpio_write(int8_t pin,gpio_level level)
{
     HAL_GPIO_WritePin(_GPIO_[pin].port,_GPIO_[pin].pin,(GPIO_PinState)level);
}