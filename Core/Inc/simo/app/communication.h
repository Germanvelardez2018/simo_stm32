

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "config.h"




typedef enum 
{
    SEND_FRAME,
    RECIBE_FRAME

} comm_mode_t;



typedef struct 
{
    uint16_t temp;
    uint16_t pressure;



}sensors_t;


typedef struct 
{
    uint8_t day;
    uint8_t week;
    uint8_t year;
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;
}date_t;


typedef struct 
{
    // frame       
    comm_mode_t    mode;
    // 
    sensors_t     data;
    //
    date_t        date;

} frame_t;







#define   MSGSIZE      sizeof(frame_t*)




//public funcions 


void init_communication(void);


void deinit_communication(void);




void communication_set_periode(int32_t periode);


