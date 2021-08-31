

#include "simo/uart/uart_core.h"











simo_status uart_init(uart_instance uart, uint32_t baud);

void uart_deinit(uart_instance uart);


void uart_send_bytes(uart_instance uart, uint8_t *buffer, int16_t buffer_len);


void uart_read_bytes(uart_instance uart, uint8_t *buffer, int16_t buffer_len);


void uart_read_until(uart_instance uart, uint8_t *buffer,int16_t max_len);




