#include<stdio.h>

void negate(int ar[][3],int x)
{
	int i,j;
	for(i = 0 ; i<x ; i++)
	{
		for(j=0;j<3;j++)
		{
			ar[i][j] = -1*(ar[i][j]);
		}
	}
	
}
void displayColumnWise(int ar[][3],int x)
{
	printf("Your new array is :\n");
	int i,j;
	int arr[3][3];
	for(i=0;i<x;i++)
	{
		for(j=0;j<3;j++)
		{
			arr[j][i] =ar[i][j]; 
		   
		}
	
	}
	
	for(i=0;i<x;i++)
	{
		for(j=0;j<3;j++)
		{
			//arr[j][i] =ar[i][j]; 
			printf("%d ",arr[i][j]);
		}
	printf("\n");
	}
}

int main(){
	
	int ar[3][3];
	printf("Enter the array elements:\n");
	int i,j;
	for( i =0 ; i<3;i++)
	{
		for( j = 0 ; j <3;j++)
		{
			scanf("%d",&ar[i][j]);
		}
	}
	
	negate(ar,3);
	displayColumnWise(ar,3);
	
	return 0 ;
}
