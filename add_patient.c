#include<stdio.h>
#include<string.h>
#include"extern.h"
#include<time.h>

void add_patient()
{
    	struct patient p;
    	int pid;
	char c,yn;
add:	printf("ENTER PATIENT DETAILS\n");
	while((c=getchar())!='\n')
		;
	printf("Enter name: ");gets(p.name);
	printf("Enter age: "); scanf("%d", &p.age);
	while((c=getchar())!='\n')
		;
	printf("Enter sex: \nM for Male\nF for Female\nO for Others\n"); p.sex=getchar();
	printf("Enter height(in cm): "); scanf("%f", &p.height);
	printf("Enter weight(in kg): "); scanf("%f", &p.weight);
	printf("Enter blood group: "); scanf("%s", p.bgrp);
	while((c=getchar())!='\n')
		;
	printf("Enter doctor's name: "); gets(p.doc);	
	printf("Enter diagnosis: ");gets(p.diag);
	printf("Enter status: \n0 for Discharged\n1 for O.P.D\n2 for Emergency\n"); scanf("%d", &p.stat);
	printf("Enter bill: "); scanf("%lf", &p.bill);
	printf("Enter amount deposited: "); scanf("%lf", &p.amtdep);
	p.pid=100;
	p.fpat=fopen(p.name,"ab");
    	time_t T=time(NULL);
    	struct tm tm=*localtime(&T);
    	int arr[3];
    	arr[0]=tm.tm_mday;
    	arr[1]=tm.tm_mon+1;
    	arr[2]=tm.tm_year+1900;
    	fwrite(arr,sizeof(arr),1,p.fpat);
	fclose(p.fpat);
    
	FILE *fptr= fopen("records.dat", "ab+");
	fseek(fptr,-1*sizeof(struct patient),SEEK_END);
	struct patient dummy;
	if(fread(&dummy,sizeof(struct patient),1,fptr)!=0)
		p.pid=dummy.pid+1;
	fwrite(&p, sizeof(struct patient), 1, fptr);
	fclose(fptr);
	while((c=getchar())!='\n')
			;
	printf("\nDo you want to add another patient record?(Y/N): ");
	scanf("%c", &yn);
	if(yn == 'Y' || yn == 'y')
	{
		goto add;
	}
	printf("\n");
}
