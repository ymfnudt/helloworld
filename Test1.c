/**********************
���������� 
����n������������1<= n <= 1000��
 1<= si <= 10000; 1<= i <=n 
�ҳ���n�������ظ����ִ���������������ж���������С�ġ�

������
���룺
6
10 20 30 20 30 40
�����
20 
 **********************/
 
#include <stdio.h>
#include <stdlib.h>


void BubbleSort(int *a,int len)
{
	int i,j,temp;
	
	for(i=0;i<len-1;i++)
	{
		for(j=len-1;j>i;j--)
		{
			if(a[j-1]>a[j])
			{
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			 } 
		}
	}
}


int GetMaxI(int *b,int len)
{
	int i,j,max,maxi;
	maxi=0;
	max = b[0];
	for(i=0;i<len;i++)
	{
		if(b[i]>max)
		{
			max = b[i];
			maxi = i;
		}
	}
	return maxi;
}
int main()
{
	int n;
	scanf("%d",&n);
	if(n<1 || n>1000)
	{
		scanf("%d",&n);
	}
	int s[n],i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
		if(s[i]<1 || s[i]>10000)
		{
			scanf("%d",&s[i]);
		}	
	}
	BubbleSort(s,n);
	int j,count[n];
	for(i=0;i<n;i++)
	{
		count[i] = 1;
	}
	int flag=0;
	for(i=0;i<n-1;)
	{
		for(j=n-1;j>i;)
		{
			if(s[i] == s[j])
			{
				count[i] = j-i+1; 
				flag = 1;
				i = j+1;
				break;
			}
			else 
				j--;
		}
		if(flag == 1)
			i = j+1;
		else
			i++;
	}
	int k;
	k= GetMaxI(count,n);
	printf("%d",s[k]); 
	return 0;
}




