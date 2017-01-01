#include <stdio.h>
#include "main_aux.h"

void scan_point(int d,double* data)
{
	int j;
	printf("enter new point\n");
	for ( j = 0; j < d; j++)
	{
		scanf("%lf",&data[j]);
	}
}
