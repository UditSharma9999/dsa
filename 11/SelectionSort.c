#include <stdio.h>
#include <conio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
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

int main()
{
    int arr[] = {12, 4, 2, 14, 6, 7, 5, 3, 46};
    int n = sizeof(arr) / sizeof(arr[0]);

    SelectionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
