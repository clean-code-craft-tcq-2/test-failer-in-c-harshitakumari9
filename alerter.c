#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    if(celcius > 200)
    {
        printf("ALERT: Temperature is %.1f celcius.\n", celcius);
        return 500;
    }
    else
    {
        return 200;
    }
}

//Code Separation task: Actual network function 
int networkAlert(float celcius) {
    if( celcius > 200){
        printf("ALERT: Temperature is %.1f celcius.\n", celcius);
        return 500;
    }
    else 
    {
    return 200;
    }
} 

//Function to calculate tempature in Celcius
float Farenheit_to_Celcius(float farenheit) 
{
    float celcius = (farenheit - 32) * 5 / 9;
    return celcius;
}

void alertInCelcius(float farenheit, int (*fnPtrForNetworkAlert)(float)) {
    int (*fnPtrForNetworkAlert)(float) = networkAlert;
    float temperature_in_celcius = Farenheit_to_Celcius(farenheit);
    int return_code = fnPtrForNetworkAlert(temperature_in_celcius); //from actual network alert function
    if (return_code != 200) {
        alertFailureCount ++;
    }
}

int main() 
{
    
    
    alertInCelcius(400.5, fnPtrForNetworkAlert);
    alertInCelcius(303.6, fnPtrForNetworkAlert);
    assert(alertFailureCount == 2);
    printf("%d alerts failed.\n", alertFailureCount);
    return 0;
}
