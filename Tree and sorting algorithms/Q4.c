/*
Write a program to sort a given set of integers using following algorithms. Your program
must display the output for every pass.
a. Insertion sort
b. Selection sort
c. Bubble sort
d. Quick sort
e. Merge sort
f. Heap sort
*/



#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, min;

    for (i = 0; i < n - 1; i++)
    {

        min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;

        swap(&arr[min], &arr[i]);
    }
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int partition(int arr[], int low, int high)
{
    int i, j;
    int pivot = arr[high];
    i = (low - 1);

    for (j = low; j <= high - 1; j++)
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
    int pi;
    if (low < high)
    {
        pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    int m;
    if (l < r)
    {
        m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i > 0; i--)
    {

        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
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
    int c = 0;
    int arr[] = {74, 89, 12, 21, 31, 67, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nGiven array is \n");
    printArray(arr, n);

    while (c != 7)
    {

        printf("\n\n1. Insertion sort\n2. Selection sort\n3. Bubble sort\n4. Quick sort\n5. Merge sort\n6. Heap sort\n7. Exit\n");
        printf("\nEnter your choice:");
        scanf("%d", &c);

        switch (c)
        {

        case 1:
            insertionSort(arr, n);
            printf("\nSorted array: \n");
            printArray(arr, n);
            break;

        case 2:
            selectionSort(arr, n);
            printf("\nSorted array: \n");
            printArray(arr, n);
            break;
        case 3:
            bubbleSort(arr, n);
            printf("\nSorted array: \n");
            printArray(arr, n);
            break;
        case 4:
            quickSort(arr, 0, n - 1);
            printf("\nSorted array: \n");
            printArray(arr, n);
            break;
        case 5:
            mergeSort(arr, 0, n - 1);
            printf("\nSorted array: \n");
            printArray(arr, n);
            break;
        case 6:
            heapSort(arr, n);
            printf("\nSorted array: \n");
            printArray(arr, n);
            break;

        case 7:
            printf("\nExit");
            break;
        default:
            printf("Invalid option\nRetry: ");
            break;
        }
    }
    return 0;
}
