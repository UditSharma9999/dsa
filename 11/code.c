#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int position = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[position] > arr[j])
            {
                position = j;
            }
        }

        if (position != i)
        {
            swap(&arr[position], &arr[i]);
        }
    }
}

void merge(int arr[], int l, int mid, int r)
{
    int n1 = (mid - l) + 1;
    int n2 = r - mid;

    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

int partition(int array[], int low, int high)
{

    int pivot = array[high];

    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;

            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int main()
{

    int N = 10, choice;
    int arr[N];

    printf("Enter 10 value in an array: \n");
    for (int i = 0; i < N; i++)
    {
        printf("value %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\n Enter your choice\n");
    printf("\n 1. Bubble Sort\n 2.Selection Sort\n 3.Insertion Sort\n 4.Merge Sort\n 5. Quick Sort\n ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        BubbleSort(arr, N);
        break;
    case 2:
        SelectionSort(arr, N);
        break;
    case 3:
        insertionSort(arr, N);
        break;
    case 4:
        mergeSort(arr, 0, N - 1);
        break;
    case 5:
        quickSort(arr, 0, N - 1);
        break;

    default:
        printf("Invalid Choices....\n");
        break;
    }

    printArray(arr, N);

    return 0;
}
