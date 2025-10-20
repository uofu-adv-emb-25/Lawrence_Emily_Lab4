#include "fifo.h"

void fifo_worker_handler(QueueHandle_t requests, QueueHandle_t results, int id)
{
    while(1) 
    {
        //Get task off request queue
        struct request_msg data = {};
        xQueueReceive(requests, &data, portMAX_DELAY);

        //Perform work
        data.output = data.input+5;
        data.handled_by = id;

        //Place finished work on results queue
        xQueueSendToBack(results, &data, portMAX_DELAY);
    }

}
