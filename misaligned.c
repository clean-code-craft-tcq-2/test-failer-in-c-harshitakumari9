#include <stdio.h>
#include <assert.h>

#define Color_Number 5U

int printColorMap ()
{
  const char *majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
  const char *minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
  int i, j; 

  for (i = 0; i < 5; i++)
  {
      for (j = 0; j < 5; j++)
	{
	    printf ("%d | %s | %s\n", ((i * 5 + j) + 1), majorColor[i], minorColor[j]);
	}
  }
  return ((i * 5 + j) + 1);
}

//Test Code added for checking whether correct color pair is received
void Test_Color_Pair(int pair_number, const char* major_color , const char* minor_color)
{
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
       
    assert( majorColor[pair_number / Color_Number] == major_color);
    assert( minorColor[(pair_number % Color_Number)-1] == minor_color);
     
    printf("%d | %s | %s\n", pair_number, major_color, minor_color);
}

int main() 
{
    Test_Color_Pair(18,"Yellow","Green");
    Test_Color_Pair(9,"Red","Brown");
    Test_Color_Pair(23,"Violet","Green");
    return 0;
}
