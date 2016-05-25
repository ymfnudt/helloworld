#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void print(int L[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%d ",L[i]);
	}
	printf("\n");
}

//冒泡排序 
void bubblesort(int L[], int n)
{
	int i,j,temp;
	for(i = 0; i < n-1; i++)
	{
		for(j = 0; j < n - 1 - i; j++)
		{
			if(L[j] > L[j+1])
			{
				temp = L[j];
				L[j] = L[j+1];
				L[j+1] = temp;
			}
		}
		print(L,n); 
	} 
}

//快速排序
//数据划分 
int patation(int L[], int low, int high)
{
    int key = L[low];
	while(low < high)	
    {
    	while(low < high && key <= L[high])
    	{
    		high--; //从右往左寻找比key小的值 
		}
		if(low < high)
		{
			L[low] = L[high]; 
		}
		while(low < high && key >= L[low])
		{
			low++; //从左往右寻找比key大的值 
		}
		if(low < high)
		{
			L[high] = L[low];
		}
	}
	L[low] = key; //最后low = high，为key的轴位置 ，左边为比key小的值，右边为比Key大的值。 
	return low; 
} 

void quicksort(int L[], int low, int high)
{
	int k;
	if(low < high)
	{
		k = patation(L, low, high);
		quicksort(L, low, k-1);
		quicksort(L, k+1, high);
	}
} 

int main()
{
	int a[SIZE] = {1, 2, 6, 7, 8, 3, 9, 4, 5, 0};
	print(a,SIZE);
	//bubblesort(a,SIZE);
	quicksort(a,0,SIZE-1);
	print(a,SIZE);
	return 0;
	
}
