#include <stdlib.h>
#include <stdio.h>

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


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void BinarySearch(int arr[], int N, int x)
{

    insertionSort(arr,N);
    printf("array after sorting...\n");
    printArray(arr, N);

    int low = 0, high = N, mid;

    while (low <= high)
    {

        mid = ((low + high) / 2);

        if (arr[mid] == x)
        {   
            printf("found the value at index %d", mid);
            break;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
}


void LinearSearch(int arr[], int N, int x){

    insertionSort(arr,N);
    printf("array after sorting...\n");
    printArray(arr, N);

    for (int i = 0; i < N; i++)
    {
        if(arr[i]==x){
            printf("found the value at index %d ", i);
            break;
        }
    }
}

int main()
{

    int N = 20;
    int arr[N], x;

    printf("Enter 20 integer  values for array \n");
    for (int i = 0; i < N; i++){
        printf("value %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter a value to be search: ");
    scanf("%d", &x);

    int choice;
    printf("\nEnter your choice\n");
    printf("1. Linear Search\n2. Binary Search\n");
    scanf("%d", &choice);




    switch (choice)
    {
    case 1:
        LinearSearch(arr, N, x);
        break;
    case 2:
        BinarySearch(arr,N,x);
        break;
    default:
        break;
    }

    return 0;
}
