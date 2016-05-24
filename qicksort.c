#include <stdio.h>
#include <stdlib.h>

#define LEN 10

int patation(int L[],int low, int high)
{
    int key = L[low];
    while(low < high)
    {
        while(low < high && key <= L[high])
            high--;
        if(low < high)
            L[low] = L[high];
        while(low < high && key >= L[low])
            low++;
        if(low < high)
            L[high] = L[low];
    }
    L[low] = key;
    return low;
}

void quicksort(int L[], int low, int high)
{
    int k;
    if(low < high)
    {
        k = patation(L, low, high);
        quicksort(L, low, k - 1);
        quicksort(L, k+1, high);
    }
}


int main()
{
    int array[LEN] = {1,55,6,8,17,99,4,20,33,0};
    int i = 0;
    quicksort(array,0,9);
    for(i = 0; i < LEN; i++)
    {
       printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}
