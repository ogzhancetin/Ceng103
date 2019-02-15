#include<stdio.h>
#include<ctype.h>


int main(){

FILE *pt = fopen("lines.txt","r");
if(pt == NULL)
printf("!!!!");
else
{
	char ch;
	int up=0,low=0,dig=0,s=1;
	int status = fscanf(pt," %c",&ch);
	while(status != EOF)
	{
		while(status != EOF && ch != '\n')
		{
		if(isupper(ch))
		up++;
		else if ( islower(ch))
		low++;
		else if ( isdigit(ch))
        dig++;
        status = fscanf(pt,"%c",&ch);
        }
      printf("%d. line contains :\n",s);
      printf("%d uppercase, %d lower , %d digit\n",up,low,dig);
      up=0;
      low = 0;
      dig = 0;
      s++;
      status = fscanf(pt,"%c",&ch);
   	}
	
}
	return 0;
}
