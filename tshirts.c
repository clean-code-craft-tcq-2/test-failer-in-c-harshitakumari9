#include <stdio.h>
#include <assert.h>

char size(int cms) 
{
    char sizeName = '\0';
    
    if(cms <= 0 && cms > 128)
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
    else if(cms > 42 && cms <= 127) 
    {
        sizeName = 'L';
    }
    printf("%d\n",cms);
    return sizeName;
}

int main() 
{
    //Modified Testcases
    assert(size(38) == 'S');
    assert(size(42) == 'M');
    assert(size(-2) == '\0');
    assert(size(125) == 'L');   
    assert(size(0) == '\0');
    assert(size(132) == '\0');
    
    return 0;
}
