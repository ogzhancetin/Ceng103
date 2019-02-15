
#include<stdio.h>

int menu()
{
	int choice;
	printf("----------------------------------------------------------------\n ----- Pass Grade : 70 ------ Midterm %40 ------ Final %60 ------\n --------------------------------MENU----------------------------\n 1. Read ID and Midterm Informations of Students From Files\n 2. Display the Grades\n 3. Calculate the Average of Midterms\n 4. Calculate the Final grade of each student to pass this course\n 5. List the Failed Students (Final Grade is bigger than 100)\n 6. Write Calculated Final Grade to Final.txt\n 7. Exit\n ---------------------------------------------------------------- \n");
    scanf("%d",&choice);
    return choice;
}

int findSize(FILE *pt)
{
	int a,size = 0;
	int status = fscanf(pt,"%d",&a);
	while(status!=EOF)
	{
		size++;
		
	status = fscanf(pt,"%d",&a);	
	}
	
	return size;
}
void readFromFile(FILE *pt,int *ar,int size)
{
	int a,i=0;
	int status = fscanf(pt,"%d",&a);
	while(status!=EOF)
	{
	ar[i]=a;
	//	printf("%d\n",*(ar+i));
	
		i++;
		
	status = fscanf(pt,"%d",&a);	
	}
	
	
	
}
int main(){
	int mAr[20],sAr[20];
	double fAr[20];
	FILE *ps = fopen("studentID.txt","r");
	int p;
	FILE *pm = fopen("midterm.txt","r");
	if(ps == NULL|| pm == NULL)
	printf("There is no such a file !!!");
	int psSize,pmSize;
	int a;


int choice,j;
double sum=0.0;
choice=menu();
 while(choice != 7)
 {
 	switch(choice)
 	{
 		case 1:
 	psSize = findSize(ps);

	pmSize = findSize(pm);	

	fclose(ps);
	fclose(pm);
	ps = fopen("studentID.txt","r");
	pm = fopen("midterm.txt","r");
	readFromFile(pm,mAr,pmSize);
 	readFromFile(ps,sAr,psSize);
		
	
 		break;
		 	
 		case 2:
 			printf("--ID--------Midterm----\n");
 	    for(int p =0 ; p<psSize;p++){
		    printf("%d         %d\n",sAr[p],mAr[p]);
	        sum+= mAr[p];   
	}
 		break;	
 		
        case 3:
 			printf("Average of midterms is: %.2lf\n",(double)(sum/pmSize));
 		break;	
 		
	    case 4:
	    	printf("-Midterm----Final to Pass--\n");
 			for( j = 0;j<pmSize;j++)
 			{
 			fAr[j]= (70 - (40*mAr[j])	/100.0)*(5.0/3.0);
 				printf("%d           %.2lf \n",mAr[j],fAr[j]);
			 }
 		break;	
 		
	    case 5:
 			for(j=0;j<pmSize;j++)
 			{
 				if(fAr[j]>100)
 				printf("%d is failed from the course\n",sAr[j]);
			 }
 		break;	
 		
	    case 6:
 		FILE *fp = fopen("Final.txt","w");
		for(j=0;j<pmSize;j++)
		{
		  fprintf(fp,"%.2lf\n",fAr[j]);
	    } 	
	    printf("***Final grades now on file***\n");
	    fclose(fp);
 		break;	
 		
	 
	 }
 	choice=menu();
 }

	
	
	fclose(ps);
	fclose(pm);
	
	return 0;
}
