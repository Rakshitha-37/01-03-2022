/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define SIZE 5
void bubble_sort(int *arr, int size)
{
    int temp;
    for(int i=0;i<size;i++) //Iterate from 0 to SIZE-1
    {
        for(int j=i+1;j<size;j++) //Iterate from i+1 to SIZE-1
        {
            if(arr[i] > arr[j]) //Check whether arr[i] is greater than arr[j] or not
            {
                //Swap the elements if arr[i] is greater than arr[j]
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main()
{
    int arr[SIZE];
    printf("Enter array elements: ");
    for(int i=0;i<SIZE;i++)
    {
        scanf("%d", &arr[i]);
    }
    bubble_sort(arr, SIZE);
    printf("After sorting, array elements: ");
    for(int i=0;i<SIZE;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

