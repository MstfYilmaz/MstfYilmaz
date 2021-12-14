#include<stdio.h> 
#include<time.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int arr[], int low, int high)
{
    int pivot = arr[high];    
    int i = (low - 1);  

    for (int j = low; j <= high - 1; j++)
    {
        
        if (arr[j] < pivot)
        {
            i++;   
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        
        int pi = partition(arr, low, high);

        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
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
    int arr[] = { 2, 0, 1, 4, 5, 5, 6, 0, 7, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    stop = clock();

    duration = (double)(stop - start) / CLOCKS_PER_SEC;

    printf("\nThe number of seconds for loop to run was %.7lf\n", duration);
    
    
    return 0;
}