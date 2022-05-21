#include "cs50.h"
#include <stdio.h>

void pyramid(int height);

int main(void)
{
    int height = get_int("Enter the height of the pyramid: ");
    pyramid(height);
}

void pyramid(height){
    int count = 1;
    while (count <= height){
        for (int i = 0; i < count; i++){
            printf("# ");
        }
        printf(" ");
        for (int i = 0; i < count; i++){
            printf(" #");

        }
        printf("\n");
        count++;
    }
}