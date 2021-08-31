#include "simo/uart/uart.h"







 static UART_HandleTypeDef UARTS[N_UART]=
                 {
                    { .Instance = USART1 },
                    { .Instance = USART2 },
                    { .Instance = USART3 },
                };




simo_status uart_init(uart_instance uart, uint32_t baud)
{

    simo_status ret = SYSTEM_OK;
    UARTS[uart].Init.BaudRate = baud;
    UARTS[uart].Init.WordLength = UART_WORDLENGTH_8B;
    UARTS[uart].Init.StopBits = UART_STOPBITS_1;
    UARTS[uart].Init.Parity = UART_PARITY_NONE;
    UARTS[uart].Init.Mode = UART_MODE_TX_RX;
    UARTS[uart].Init.HwFlowCtl = UART_HWCONTROL_NONE;
    UARTS[uart].Init.OverSampling = UART_OVERSAMPLING_16;


    if( (HAL_UART_Init(&(UARTS[uart])) !=  HAL_OK))
    {
        ret = SYSTEM_ERROR;
    }

    return ret;
}

void uart_deinit(uart_instance uart){

}


void uart_send_bytes(uart_instance uart, uint8_t *buffer, int16_t buffer_len)
{
     HAL_UART_Transmit(&(UARTS[uart]),buffer,buffer_len,TX_TIMEOUT);
}


void uart_read_bytes(uart_instance uart, uint8_t *buffer, int16_t buffer_len)
{
    HAL_UART_Receive(&(UARTS[uart]),buffer,buffer_len,TX_TIMEOUT);
}


void uart_read_until(uart_instance uart, uint8_t *buffer,int16_t max_len)
{

}