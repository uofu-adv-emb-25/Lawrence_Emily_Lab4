#include "signaling.h"
#include <stdio.h>


void signal_handle_calculation(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data)
{
    xSemaphoreTake(request,portMAX_DELAY);
    printf("Request received");
    data->output = data->input+5;
    xSemaphoreGive(response);
    printf("Calculation finished");
}

BaseType_t signal_request_calculate(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data)
{
    printf("Giving task to worker");
    xSemaphoreGive(request);
    printf("Waiting for results");
    return xSemaphoreTake(response,100);
}
