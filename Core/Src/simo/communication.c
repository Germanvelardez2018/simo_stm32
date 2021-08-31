#include "simo/app/communication.h"
#include "simo/uart/uart.h"



static QueueHandle_t  _queue_in;
static QueueHandle_t  _queue_out;


static TickType_t _periode;


//private functions
static void communication_task(void* params);




static void processing_frame(frame_t* frame);



//public funcions 


void init_communication(void)
{
    //init puerto serie
    uart_init(UART1,115200);

        //
    // creo tarea
    //creo las dos tareas: 
    xTaskCreate(communication_task,"COMM TASK",2*1024,NULL,tskIDLE_PRIORITY+1,NULL);
    
    




}


void deinit_communication(void)
{
    //elimino tareas y limpio recursos
}


static void communication_send(char* msg)
{
    //envio el mensaje a la tarea que gestionara el puerto uart
    xQueueSend(_queue_out,&msg,0);
}


void communication_set_periode(int32_t periode)    //cambio cada cuanto tiempo debo transmitir
{
    _periode = periode;
}



static void communication_task(void* params)
{
    uint32_t periode = DELAY_COMM_TASK;   //PARAMETRO POR DEFECTO
    frame_t* buffer;
    //create the queue
    _queue_in = xQueueCreate(MSGSIZE,N_QUEUE_COMM);

    UBaseType_t messages_wait;

    while(1)
    {

        messages_wait =  uxQueueMessagesWaiting( _queue_in );      //entrada de mensaje

        if(messages_wait != 0)
        {
          xQueueReceive(_queue_in,&buffer,0);

          
        
          //darle formato al mensaje

          //enviar mensaje por puerto uart
          //communication_send_block();

        }
      

       

        vTaskDelay(period);
    }
}







static void processing_frame(frame_t* frame)
{
    //if input or output

    if(frame->mode ==SEND_FRAME)
    {
        // FUNCION PARA FORMATEO DE MENSAJE     transforma  frame_t -->  char*

        //uart_send()
    }
    else
    {
        //el frame fue recibido y son comandos remotos
        //funcion que recibe
    }


}
