#include <stdlib.h>
#include <stdio.h>

int main()
{
    const int N = 20;
    int arr[N], x = 7;
    printf("Enter 20 integer  values for array ");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("%d", arr[0]);

    printf("Enter a value to be search: ");
    scanf("%d", &x);

    int low = 0, high = N - 1;

    while (low <= high)
    {

        int mid = ((low + high) / 2);

        if (arr[mid] == x)
        {
            printf("%d", mid);
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

    return 0;
}
