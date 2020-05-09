#include<stdio.h>
#include "extern.h"
void printname_pid(FILE *fp)
{
  	struct patient p;
  	while(fread(&p,sizeof(struct patient),1,fp))
  	{
	  	printf("\nName of the patient: %s",p.name);
	  	printf("\nPatient ID: %ld",p.pid);
	  	printf("\nDoctor's name: %s\n", p.doc);
  	}
}
