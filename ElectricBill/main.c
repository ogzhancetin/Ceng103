#include<stdio.h>
#define SIZE 20
#include<math.h>
void read(FILE *pt,double ar[][SIZE],int *rSize){
	char ch;
	int i=0,j=0;
	double val;
	pt = fopen("Bill.txt","r");
	if(pt == NULL)
	printf("NO file");
	else
	{
		int status = fscanf(pt,"%lf",&val);
		while(status != EOF)
		{
		 while(j < 12)
		 {
		 	ar[i][j] = val;
		 	
		 	status = fscanf(pt,"%lf",&val);
		 	j++;
		 }
		 i++;
		 j=0;
		 ar[i][j] = val;
		 status = fscanf(pt,"%lf",&val);
		 j++;
		}
		*rSize = i;
		fclose(pt);
		
	
	}
	
}
void find_avg_dev(double ar[][SIZE],int flatNo,double *avg,double *stDev)
{
    int i,j;
	double sum = 0;
	for(i=0;i<12;i++)
    sum += ar[flatNo][i] ;
	
	*avg = sum / (12);
	sum = 0;
	for(i=0;i<12;i++)
	sum += ( ar[flatNo][i] - (*avg) ) *   ( ar[flatNo][i] - (*avg) ) ;	
	
	*stDev   =  sqrt(sum / 12.0 );
}

int main(){
	FILE *pt;
	double ar[SIZE][SIZE],avg,stdev;
	int rSize;
	read(pt,ar,&rSize);
	int i , j;
	printf("    Flat no     Jan    Feb     Mar   Apr     May   Jun  Jul   Aug    Sep    Oct    Nov    Dec     Avg       StDev\n");
	for(i = 0; i< 10 ; i++)
	{
		printf("%-8d ",i+1);
		for(j=0; j<12 ; j++)
		{
			printf("%6.1lf ",ar[i][j]);
			
		}
	    find_avg_dev(ar,i,&avg,&stdev);
	    printf("%6.1lf %8.1lf\n",avg,stdev);
	}
	
	return 0 ;
}
