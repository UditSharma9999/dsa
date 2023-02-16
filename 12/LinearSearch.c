#include<stdlib.h>
#include<stdio.h>

int main()
{
    const int N = 20;
    int arr[N], x;
    printf("Enter 20 integer  values for array ");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter a value to be search: ");
    scanf("%d",&x);

    for (int i = 0; i < N; i++)
    {
        if(arr[i]==x){
            printf("value find at index: %d",i+1);
            break;
        }
    }
    
    
    return 0;
}
