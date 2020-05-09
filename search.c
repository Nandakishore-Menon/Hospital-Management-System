#include<stdio.h>
#include "extern.h"
#include "edit.h"
#include<string.h>
#include<ctype.h>
#include "display.h"
#include "printname_pid.h"
void name_pid(struct patient p);
void strlower(char* p,char* c);
void search(FILE* fptr)
{
    	FILE* fnew,fdum;
    	char ch;
    	struct patient pat;
    	char s[100];
    	char c[100];
    	int flag=0;
a:    	fnew=fopen("search.dat","wb+");
  	printf("\nBy which field would you like to search?");
	printf("\n1)Name");
	printf("\n2)Patient ID");
	printf("\n3)Doctor consulted");
	printf("\n4)Status\nPlease enter your choice: ");
    	int inp;
    	scanf("%d",&inp);
    	switch (inp)
    	{
        	case 1:
            		flag=0;
            		fseek(fptr,0,SEEK_SET);
            		printf("\nEnter the name of the patient : ");
            		scanf("%s",s);
            		strlower(s,s);
            		while(fread(&pat,sizeof(pat),1,fptr))
            		{
                		strlower(pat.name,c);
                		if(strstr(c,s))
                		{
                    			fwrite(&pat,sizeof(pat),1,fnew);
                    			flag=1;
                		}
            		}
            		if(flag==0)
            		{
            			printf("No records found.\n\n");
            			break;
            		}
            		fseek(fnew,0,SEEK_SET);
            		printname_pid(fnew);
            		goto case2;
            		break;
        	case 2:
            		
case2:
            		fseek(fptr,0,SEEK_SET);
            		printf("\nEnter the Patient Id : ");
            		int num;
            		scanf("%d",&num);
            		while(fread(&pat,sizeof(pat),1,fptr))
            		{
                		if(pat.pid==num)
                		{
                    			display(pat);
                    			goto d;
                		}
            		}
            		printf("No records found.");
            		goto case2;
d:            		break;
        	case 3:
            		fseek(fptr,0,SEEK_SET);
            		flag=0;
            		while((ch=getchar())!='\n')
				;
            		printf("\nEnter the name of the doctor : ");
            		gets(s);
            		strlower(s,s);
            		while(fread(&pat,sizeof(pat),1,fptr))
            		{
                		strlower(pat.doc,c);
                		if(strstr(c,s))
                		{
                    			fwrite(&pat,sizeof(pat),1,fnew);
                    			flag=1;
                		}
            		}
            		if(flag==0)
            		{
            			printf("No records found.\n\n");
            			break;
            		}
            		fseek(fnew,0,SEEK_SET);
            		printname_pid(fnew);
            		goto case2;
        	case 4:
            		flag=0;
            		fseek(fptr,0,SEEK_SET);
            		int status;
b:            		printf("\n Enter the status of the patient that you want to search:\n0:Discharged\n1:OPD\n2:Emergency\n");
            		scanf("%d",&status);
            		if(status!=0 && status!=1 && status!=2)
            		{
            			printf("Enter valid option.");
            			goto b;
            		}
            		while(fread(&pat,sizeof(pat),1,fptr))
            		{
                		if(pat.stat==status)
                		{
                    			name_pid(pat);
                    			flag=1;
                		}
            		}
            		if(flag==0)
            		{
            			printf("No records\n");
            		}
            		while((ch=getchar())!='\n')
				;
            		printf("\nFilter applied.\n");
c:            		printf("Search by");
            		printf("\n1)Name");
            		printf("\n2)Doctor consulted\n");
			printf("Enter choice: ");            
            		scanf("%d",&inp);
            		if(inp!=1 && inp!=2)
            		{
            			printf("\nEnter valid option.\n");
            			goto c;
            		}
            		switch(inp)
            		{
                		case 1:
                    			flag=0;
                    			while((ch=getchar())!='\n')
						;
                    			printf("\nEnter the name of the patient : ");
                    			gets(s);
                    			strlower(s,s);
                    			strlower(pat.name,c);
                    			fseek(fptr,0,SEEK_SET);
                    			while(fread(&pat,sizeof(pat),1,fptr))
                    			{
                        			strlower(pat.name,c);
                        			if((strstr(c,s))&&(pat.stat==status))
                        			{
                            				display(pat);
                            				flag=1;
                        			}
                    			}
                    			if(flag==0)
                    			{
                    				printf("No records found\n\n");
                    			}
                    			break;
                		case 2:
                    			flag=0;
                    			fseek(fptr,0,SEEK_SET);
                    			while((ch=getchar())!='\n')
						;
                    			printf("\nEnter the name of the doctor : ");
                    			gets(s);
                    			strlower(s,s);
                    			while(fread(&pat,sizeof(pat),1,fptr))
                    			{
                        			strlower(pat.doc,c);
                        			if((strstr(c,s))&&(pat.stat==status))
                        			{
                            				display(pat);
                            				flag=1;
                        			}
                    			}
                    			if(flag==0)
                    			{
                    				printf("No records found\n\n");
                    			}
                    			break;
                    		default:
                    			printf("\nPlease enter valid option");
            		}
            		break;
        	default:
            		printf("\nPlease enter a valid option");
            		goto a;
            		break;
    	}
    	
    	fclose(fnew);
    	while((ch=getchar())!='\n')
		;
    	printf("Would you like to search by some other field?(Y/N): ");
    	char choice;
    	scanf("%c",&choice);
    	if((choice=='Y') || (choice=='y'))
    	{
    		goto a;
    	}
    	fclose(fptr);
}
void name_pid(struct patient p)
{
	printf("\nName : ");
	printf("%s",p.name);
	printf("\nPatient ID : ");
	printf("%ld\n",p.pid);
	printf("Doctor's name: %s\n",p.doc);
}

void strlower(char* p,char* c)
{
    	for(int i=0;i<strlen(p);i++)
    	{
        	c[i]=tolower(p[i]);
    	}
}
