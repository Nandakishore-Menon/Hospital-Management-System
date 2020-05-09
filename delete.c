#include<stdio.h>
#include "extern.h"
#include "search.h" 
#include<string.h>
#include "printname_pid.h"
int delete()
{
    		char s[100];
		char ch[100];
		int flag=0;
		char yn,c;
		long int pid;
		struct patient pat;
		FILE *fptr=fopen("records.dat","rb");
		FILE* fnew=fopen("search.dat","wb");
del:		fseek(fptr,0,SEEK_SET);
        	printf("Enter the name of the patient whose record is to be deleted : ");
            	scanf("%s",s);
            	strlower(s,s);
            	while(fread(&pat,sizeof(pat),1,fptr))
            	{
                	strlower(pat.name,ch);
                	if(strstr(ch,s))
                	{
                    		fwrite(&pat,sizeof(pat),1,fnew);
                    		flag=1;
                	}
		}
		if(flag==0)
		{
			while((c=getchar())!='\n')
				;
			printf("\nPatient not found. Try again!\n");
			printf("Do you want to go to main menu?(Y/N): ");
			scanf("%c", &yn);
			if(yn=='Y' || yn=='y')
			{
				return 0;
			}
			goto del;
		}
        	fclose(fptr);
        	fclose(fnew);
        	fnew=fopen("search.dat","rb");
        	printname_pid(fnew);
        	fclose(fnew);
        	while((c=getchar())!='\n')
			;
        	printf("\nEnter the patient ID of the patient whose record is to be deleted : ");
        	scanf("%ld",&pid);
    	struct patient input,del;
    	FILE *fptr1;
    	fptr = fopen("records.dat","rb");
    	fptr1 = fopen("record1.dat","wb");
    	while(fread(&input, sizeof(struct patient), 1, fptr))
    	{
        	if(input.pid!=pid)
        	{
            		fwrite(&input ,sizeof(struct patient), 1, fptr1);
        	}
        	else
        	{
        		del=input;
        	}
    	}
    	fclose(fptr);
    	fclose(fptr1);
    	remove(del.name);
    	remove("records.dat");
    	rename("record1.dat","records.dat");
    	printf("\nPatient record deleted.\n");
    	return 1;
}
