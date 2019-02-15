#include<stdio.h>

int main(){
	int i,j;
	int ar[2][3],ar2[2][3],ar3[2][3];
	printf("Enter the elements of array 1:\n");
	
    	for( i = 0;i<2;i++)
	      for( j = 0;j<3;j++)
	        scanf("%d",&ar[i][j]);
	    
	printf("Enter the elements of array 2:\n");
	
     	for(i = 0;i<2;i++)
      	  for( j = 0;j<3;j++)
	        scanf("%d",&ar2[i][j]);
	 
	 
	 printf("\nSum of arrays:\n");
     	for(i = 0;i<2;i++){
  	       for( j = 0;j<3;j++){
  
	    ar3[i][j]= ar[i][j] + ar2[i][j];
      
	      printf("%d ",ar3[i][j]);	     
                         }
printf("\n");}
	return 0;
}
