#include <stdio.h>
#include <assert.h>

char size(int cms) 
{
    char sizeName = '\0';
  
    //Assuming the Minimum Size is greeater than 0 and Maximum size is 100.
    if(cms <= 0 || cms > 100)
    {
        printf("Invalid Size !");
    }
    else if(cms <= 38) 
    {
        sizeName = 'S';
    } 
    else if(cms > 38 && cms <= 42)
    {
        sizeName = 'M';
    } 
    else if(cms > 42 && cms <= 100) 
    {
        sizeName = 'L';
    }
    return sizeName;
}

int main() 
{
    //Modified Testcases
    assert(size(38) == 'S');
    assert(size(42) == 'M');
    assert(size(-2) == '\0');
    assert(size(100) == 'L');   
    assert(size(0) == '\0');
    assert(size(132) == '\0');
    
    return 0;
}
