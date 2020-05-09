#include <stdio.h>
#include<string.h>
#include"extern.h"
#include <ctype.h>
#include "print.h"

void lower(char *upr, char *low)
{
	int l = strlen(upr);
	for (int i=0; i<l; i++)
		low[i] = tolower(upr[i]);
}

int diagnosis()
{
	char c,di[100];
	while((c=getchar())!='\n')
			;
diag:	printf("Enter diagnosis: ");
	gets(di);
	FILE* fptr=fopen("records.dat","rb");
	
	FILE *diag = fopen("diagnosis.dat", "wb+");
	int l, i;
	int flag=0;
	l = strlen(di);
	struct patient p;
	char s_diag[l];
	for(i=0; i<=l; i++)
		s_diag[i] = tolower(di[i]);
	while(fread(&p, sizeof(struct patient), 1, fptr)==1)
	{
		l = strlen(p.diag);
		char p_diag[l];
		for(i=0; i<l; i++)
			p_diag[i] = tolower(*(p.diag+i));
		if(strstr(p_diag, s_diag))
		{
			fwrite(&p, sizeof(struct patient), 1, diag);
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("No records found.\n");
		fclose(diag);
		fclose(fptr);
		goto diag;
	}
	else
	{
		fseek(diag,0,SEEK_SET);
		print(diag);
		fclose(diag);
		fclose(fptr);
		return 0;
	}
}
