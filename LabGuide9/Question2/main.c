#include<stdio.h>

int menu()
{
	int choice;
	printf("Display the...\n1. Matrix\n2. Sum of the minor diagonal\n3. Average of the major diagonal\n4. Maximum of the given column\n5. Minimum of the given row\n6. Sum and average of the matrix\n7. Exit\nEnter your choice: ");
	scanf("%d",&choice);
	return choice;
}

int main(){
	
	FILE *pt = fopen("Q2text.txt","r");
	
	if(pt == NULL)
	printf("\nThere is no such a file");
	
      else
	{
		double sum = 0.0,avg;
		int choice,clm,max,min;
		int ar[5][5];
		int i,j,t,p,ta,pa,at,ap,tt;
		for(i=0;i<5;i++)
		{
		  for(j=0;j<5;j++)
		   {
			 fscanf(pt,"%d",&ar[i][j]);
		   }
		}
	choice = menu();
		while(choice != 7)
		{
			switch(choice)
			{
				case 1:
		for( t=0 ; t<5 ; t++)
		{
		  for( p=0;p<5;p++)
		   {
			 printf("%d ",ar[t][p]);
		   }
		   printf("\n");
		}
				break;
				
				case 2:
				sum = 0.0;
				
		for(  ta = 0 ; ta<5 ; ta++)
	    	{
		      for( pa = 4;pa>=0 ; pa--)
		     {
		     	if(ta + pa == 4)
			 sum += ar[ta][pa];
		     }
		   
	    	}
	    	printf("The sum of the minor diagonal in the matrix is: %.2lf\n\n",sum);
				break;
				
				case 3:
				sum = 0;
				for( at = 0 ;at<5 ; at++)
	    	{
		      for( ap = 0;ap<5 ; ap++)
		     {
		     	if(at == ap )
			 sum += ar[at][ap];
		     }
		   avg = sum/5.0;
	    	}
	    	printf("The average of the major diagonal in the matrix is: %.2lf\n\n",avg);
				break;
				
				case 4:
				
				printf("Pls enter the column from which you want the maximum element:\n");
				scanf("%d",&clm);
				max = ar[0][clm];
				for(  tt = 0 ;tt < 5 ; tt++)
	    	{
	    		if( ar[tt][clm] > max)
		         max =ar[tt][clm];
		    }
		    	printf("Maximum number within the specified column is %d\n\n",max);
		    
				break;
				
				case 5:
				printf("Pls enter the row from which you want the minimum element:\n");
				scanf("%d",&clm);
				max = ar[clm][0];
				int op;
				for(  op = 0 ;op < 5 ; op++)
	    	{
	    		if( ar[clm][op] < min )
		         min =ar[clm][op];
		    }
		    	printf("Minimum number within the specified row is %d\n\n",min);
				
				break;
				
				case 6:
					sum = 0,avg = 0;
					int a,b;
					for( a=0;a<5;a++)
					{
						for( b=0;b<5;b++)
					    sum += ar[a][b];
					}
					avg = sum/25;
					printf("The sum of this matrix is %.lf and its average is %.2lf\n\n",sum,avg);
				break;
	
			}
			
			
			choice = menu();
		}
		
	}
	
	
	
	return 0;
}
