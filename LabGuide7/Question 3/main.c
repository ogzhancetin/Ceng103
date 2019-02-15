#include<stdio.h>
#include<ctype.h>

int main(){
	int tcounter=0,counter = 0;
	FILE *wp ,* pt = fopen("sentence.txt","r");
	char status,letter,ch;
	if(pt == NULL)
	printf("There is no such a file");
	else
	{
		  printf("Enter a lowercase letter : ");
	      scanf("%c",&ch);
	      printf("%c",ch);
		  wp = fopen("words.txt","w");
		      status = fscanf(pt,"%c",&letter);
		while(status != EOF)
		{
	    	
		    
		
			   if( (letter == ch) || (letter == toupper(ch) )  ) 
			    {
			   
		          while( (letter != ' ') && (letter != '\n') )
		          {
				   
				   fprintf(wp,"%c",letter);
		           fscanf(pt,"%c",letter); 
				  }
		     	   
					fprintf(wp,"\n");
	                counter++;
	            }
					else
					{
						while(letter != ' ' && letter !='\n')
						{
						
						fscanf(pt,"%c",&letter);
					    tcounter++;
						} 
					 }
		
		    
		    
			status  = fscanf(pt,"%c",&letter);
		}
		
		
		
	}
	fclose(pt);
	fclose(wp);
	printf("\nThere are %d words totally, and %d of them are starting with '%c' ",tcounter+counter,counter,ch);
	
	
	return 0;
}
