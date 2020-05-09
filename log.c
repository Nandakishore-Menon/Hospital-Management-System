#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "extern.h"
#include"print.h"

int log_patient(FILE *fptr, int date[])		//Date file
{
	int da[3];
	while(fread(da, sizeof(da), 1, fptr)==1)
	{
		int count = 0;
		for(int i=0; i<3; i++)
			if(da[i]==date[i])
				count++;
		if(count==3)
		{
			return 1;
		}
	}
	return 0;
}

void openfile(/*FILE *fptr, int date[]*/)	//Main record file.
{
	int d, m, y,flag=0;
	printf("Enter date(dd)  : "); scanf("%d", &d);
	printf("Enter month(mm) : "); scanf("%d", &m);
	printf("Enter year(yyyy): "); scanf("%d", &y);
	FILE* fptr=fopen("records.dat","rb");
	int date[3]={d, m, y};
	struct patient p;
	FILE *log = fopen("log.dat", "wb+");
	if(log==NULL)
	{
		printf("error\n");
		exit(0);
	}
	while(fread(&p, sizeof(struct patient), 1, fptr)==1)
	{
		FILE *date_file = fopen(p.name, "rb");
		if(date_file==NULL)
		{
			printf("Couldn't open file.\n");
		}
		if(log_patient(date_file, date)==1)
		{
			fwrite(&p, sizeof(struct patient), 1, log);
			flag=1;
		}
		
		fclose(date_file);
	}
	fseek(log, 0, SEEK_SET);
	if(flag==0)
	{
		printf("No records found.\n");
		fclose(log);
		fclose(fptr);
	}
	else
	{
		print(log);
		fclose(log);
		fclose(fptr);
	}
}
