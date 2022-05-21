#include <stdio.h>

int main(void)
{

    int arr[] = {3, 0, 4, 1, 2};

    for (int i = 0; i < 5; i++)
    {
        printf("%i: ", arr[i]);

        for (int j = i; j < 5; j++)
        {
            
            printf("%i%i | ", arr[i],arr[j]);            
        }
       
        printf("\n");
    }
}