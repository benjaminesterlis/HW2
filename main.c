#include "SPPoint.h"
#include "main_aux.h"
#include "SPBPriorityQueue.h"
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int n, d, k;
	int i;

	printf("Enter an integer n,Enter an integer d >= 0,Enter an integer n>= k >= 0:\t");
	scanf("%d",&n);
	scanf("%d",&d);
	scanf("%d",&k);
	
	double *data = (double*) malloc(sizeof(double)*d);
	SPPoint *q;
	SPPoint **spp = (SPPoint**) malloc(sizeof(SPPoint *)*n);
	SPBPQueue *length_l2 = spBPQueueCreate(k);
	for (i = 0; i < n; i++)
	{	
		scan_point(d,data);
		spp[i] = spPointCreate(data,d ,i);
	}
	printf("enter the point q:\t\n");

	scan_point(d,data);

	q = spPointCreate(data,d ,i);
	for (i = 0; i < n; ++i)
		spBPQueueEnqueue(length_l2,spPointGetIndex(spp[i]),spPointL2SquaredDistance(spp[i],q));

	printq(length_l2,1);
	return 0;
}