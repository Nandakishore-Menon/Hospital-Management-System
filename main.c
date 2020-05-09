#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add_patient.h"
#include "search.h"
#include "edit.h"
#include "printname_pid.h"
#include "doctor.h"
#include "delete.h"
#include "doctor.h"
#include "print.h"
#include "diagnosis.h"
#include "bgrp.h"
#include "log.h"
#include <unistd.h>
int main()
{
	int option,id;
	char yn;
	char c;
	int flag=0;
	system("clear");
	printf("\n\n\n\n\t\t\t\t\t*******************************\t\tWELCOME TO WE-CARE\t*******************************\n\n");
	sleep(1);
menu:	menu();
	printf("Enter option number: ");
	scanf("%d", &option);
	printf("\n");
	if(option==1)
	{
		FILE * fptr;
		fptr= fopen("records.dat", "rb");
		if(fptr==NULL)
			printf("No records to be displayed\n");
		else
		{
			print(fptr);
			fclose(fptr);
		}
	}
	else if(option==2)
	{
		add_patient();
	}
	else if(option==3)
	{
		search(fopen("records.dat","rb"));
	}
	else if(option==4)
	{
        	edit();
	}
	else if(option==5)
	{
        	if(delete()==0)
        		goto menu;
	}
	else if(option == 6)
	{
		bloodgroup();
	}
	else if(option == 7)
	{
		doctor();
	}
	else if(option == 8)
	{
		diagnosis();
	}
	else if(option == 9)
	{
		openfile();
	}
	else if(option==0)
	{
		system("clear");
		printf("\n\n\t\t\t\t*******************************\t\tThank you for using our services.\t*******************************\n\n\n");
		sleep(2);
		system("clear");
		exit(0);
	}
	else
	{
		printf("Enter valid option\n");
		goto menu;
	}
	while((c=getchar())!='\n')
			;
	printf("\nDo you want to perform any other operation?(Y/N): ");
	scanf("%c", &yn);
	if(yn=='Y' || yn=='y')
		goto menu;
	else
	{
		system("clear");
		printf("\n\n\t\t\t*******************************\t\tThank you for using our services.\t*******************************\n\n\n");
		sleep(2);
		system("clear");
		exit(0);
	}
	return 0;
}
