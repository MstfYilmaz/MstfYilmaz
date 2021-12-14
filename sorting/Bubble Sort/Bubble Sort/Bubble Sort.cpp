#include <stdio.h> 
#include<time.h>

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

     
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}


void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main()
{
    clock_t start, stop;
    long int x;
    double duration;

    start = clock();
    
    int arr[] = { 2, 0, 1, 4, 5, 5, 6 ,0 ,7 ,1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    stop = clock();  

    duration = (double)(stop - start) / CLOCKS_PER_SEC;

    printf("\nThe number of seconds for loop to run was %.7lf\n", duration);

    return 0;
}