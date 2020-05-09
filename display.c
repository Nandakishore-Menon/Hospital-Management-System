#include<stdio.h>
#include "extern.h"
void display(struct patient p)
{
        printf("\n------------------------------------------------------");
	printf("\nName of the patient 	     :%s",p.name);
        printf("\nPatient Id 		     :%ld",p.pid);
	printf("\nSex of the patient 	     :%c",p.sex);
	printf("\nName of the doctor 	     :%s",p.doc);
	printf("\nDiagnosis		     :%s",p.diag);
	printf("\nHeight of the patient      :%f",p.height);
        printf("\nWeight of the patient      :%f",p.weight);
	printf("\nBlood group of the patient : %s",p.bgrp);
	printf("\nStatus of the patient      :%d",p.stat);
	printf("\nFinal bill                 :%lf",p.bill);
	printf("\nAmount deposited           :%lf",p.amtdep);
        printf("\n------------------------------------------------------\n");

}
