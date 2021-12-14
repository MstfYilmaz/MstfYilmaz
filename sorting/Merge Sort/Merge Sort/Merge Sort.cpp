﻿
#include <stdio.h>
#include<time.h>

#define max 10

int a[11] = { 2, 0, 1, 4, 5, 5, 6, 0, 7, 1};
int b[10];

void merging(int low, int mid, int high) {
    int l1, l2, i;

    for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
        if (a[l1] <= a[l2])
            b[i] = a[l1++];
        else
            b[i] = a[l2++];
    }

    while (l1 <= mid)
        b[i++] = a[l1++];

    while (l2 <= high)
        b[i++] = a[l2++];

    for (i = low; i <= high; i++)
        a[i] = b[i];
}

void sort(int low, int high) {
    int mid;

    if (low < high) {
        mid = (low + high) / 2;
        sort(low, mid);
        sort(mid + 1, high);
        merging(low, mid, high);
    }
    else {
        return;
    }
}

int main() {
    int i;
    clock_t start, stop;
    long int x;
    double duration;
    start = clock();
    sort(0, max);

    for (i = 0; i <= max; i++)
        printf("%d ", a[i]);
    stop = clock();  

    duration = (double)(stop - start) / CLOCKS_PER_SEC;

    printf("\nThe number of seconds for loop to run was %.7lf\n", duration);
}