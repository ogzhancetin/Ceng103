#include<stdio.h>



int main(){
	
	FILE *ip = fopen("sentence.txt","r");
	FILE *op = fopen("reverse_a.txt","w");
	FILE *op2 = fopen("reverse_b.txt","w");
	char ch;
	char status = fscanf(ip,"%c",&ch);
	//printf("%c\n",ch);
    char ar[30];
    char ar2[30];
    int acSize = 0;
	int counter = 0; 
	while(status != EOF)
	{
		
	    while(status != EOF && ch != ' ')
	      {
	      	ar[counter]=ch;
	      	ar2[acSize] = ch;
	      	counter++;
	      	acSize++;
	      	status = fscanf(ip,"%c",&ch);
	      //	printf("%c\n",ch);
		  }
		  int i;
		  for( i = acSize-1;i>=0;i--)
		  {
		  	fprintf(op2,"%c",ar2[i]);
		  	printf("%c",ar2[i]);
		  }
		  acSize=0;
	    fprintf(op2," ");
	 	ar[counter] = ch;
	 	counter++;
	status = fscanf(ip,"%c",&ch);
	}
	int i;
	for( i = counter-2;i>=0;i--)
		  {
		  	fprintf(op,"%c",ar[i]);
		 	//printf("%c",ar[i]);
		  }
	return 0;
}
