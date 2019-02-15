#include<stdio.h>



int main(){
	int id[10];
	double avg[10][5];
	double sum = 0;
	int i =0,j,t=0;

	FILE *pt = fopen("grades.txt","r");
	if(pt == NULL)
	printf("ERROR");
	
	else{
	
	int status = fscanf(pt,"%d",&id[i]);
	while(status != EOF)
	{
		i++; 
		for(j=0;j<5;j++){
		
		 fscanf(pt,"%lf",&avg[t][j]);
		
                                	}
		 t++;
		status = fscanf(pt,"%d",&id[i]);
	}

	double sumA[10],q[5],qq = 0.0;
	FILE *ap = fopen("average.txt","w");
	int a,b;
	for(a = 0; a<10;a++){
	
	  for( b = 0; b<5;b++)
                          	{
       
	    sum += avg[a][b];
                            }
                 sumA[a]=sum / 5;
				 sum=0.0;  
				 fprintf(ap,"%d %.1lf\n",id[a],sumA[a]);
				                     }
				int tp;                     
		for( tp = 0; tp<10;tp++)
		 qq += avg[tp][0];

		q[0]=qq/10;
	
		qq = 0;
		
				                     
		for( tp = 0; tp<10;tp++)
		 qq += avg[tp][1];
		q[1]=qq/10;
		qq = 0;
				                     
		for( tp = 0; tp<10;tp++)
		 qq += avg[tp][2];
		q[2]=qq/10;
		qq = 0;
				                     
		for( tp = 0; tp<10;tp++)
		 qq += avg[tp][3];
		q[3]=qq/10;
		qq = 0;
				                     
		for( tp = 0; tp<10;tp++)
		 qq += avg[tp][4];
		q[4]=qq/10;
		
		
		printf("Quiz Number     Average\n");
		int n;
		for( n =0 ; n<5;n++)
		printf("%d                %.2lf\n",n+1,q[n]);
	}
	return 0; 
}
