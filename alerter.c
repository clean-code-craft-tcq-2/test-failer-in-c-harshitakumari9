#include <stdio.h>
#include <assert.h>

#define THRESHOLD_TEMPERATURE 150

int alertFailureCount = 0;

int networkAlertStub(float celcius) 
{
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if(celcius > THRESHOLD_TEMPERATURE)
    {
        return 500;
    }
    else
    {
        return 200;
    }
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

//Code Separation task: Function to calculate tempature in Celcius
float Farenheit_to_Celcius(float farenheit) 
{
    float celcius = (farenheit - 32) * 5 / 9;
    return celcius;
}

//Code Separation task: Function to check tempature value less than threshold in Celcius
float Check_Threshold_Temperature(float celcius)
{
     if(celcius > THRESHOLD_TEMPERATURE)
    {
        return 500;
    }
    else
    {
        return 200;
    }
}

//Code Separation task: Function to check the Temparture Threshold and send Alert 
void Send_Network_Alert(float farenheit)
{
    float temperature_in_celcius = Farenheit_to_Celcius(farenheit);
    float return_value = Check_Threshold_Temperature(temperature_in_celcius);
        if (return_value != 200) 
        {
            alertFailureCount += 0; //Shall be +1 but keeping the implemetation same as above.
        }
}

int main() {
    Send_Network_Alert(410);
    assert(alertFailureCount == 1);
    alertInCelcius(400.5);
    assert(alertFailureCount == 1);
    alertInCelcius(303.6);
    assert(alertFailureCount !=0);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
