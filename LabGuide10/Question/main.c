#include<stdio.h>



int main(){
	
	char ar[50][50];
	int i = 0 , j = 0;
	
	FILE *pt = fopen("words.txt","r");
	if(pt == NULL)
	printf("There is no such a text");
	else
	{
		
		char ch;
		int status = fscanf(pt," %c",&ch);
		while(status != EOF)
		{
			while(status != EOF && ch != '\n')
			{
				if(ch != ' '){
				
			ar[i][j] = ch;
			j++;
	                        }
	        status = fscanf(pt,"%c",&ch);
			}		
			i++;
			j = 0;
			status = fscanf(pt,"%c",&ch);
		}
		
		}	
	int a;
	fclose(pt);
	printf("Which world do you want to display ?\n");
	scanf("%d",&a);
	printf("The word is: ");
	
	int b;
	for( b =0 ; b<i ; b++)
	{
		printf("%c",ar[b][a-1]);
	}
	
	
	
	return 0;
}
