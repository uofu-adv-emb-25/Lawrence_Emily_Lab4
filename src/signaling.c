#include "signaling.h"
#include <stdio.h>


void signal_handle_calculation(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data)
{
    xSemaphoreTake(request,portMAX_DELAY);
    printf("Request received\n");
    data->output = data->input+5;
    xSemaphoreGive(response);
    printf("Calculation finished\n");
}

BaseType_t signal_request_calculate(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data)
{
    printf("Giving task to worker\n");
    xSemaphoreGive(request);
    printf("Waiting for results\n");
    return xSemaphoreTake(response,100);
}
