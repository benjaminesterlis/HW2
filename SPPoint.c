#include "SPPoint.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

struct sp_point_t
{
	double* data;
	int dim;
	int index;
};

SPPoint* spPointCreate(double* data, int dim, int index) 
{
	SPPoint *sp = malloc(sizeof(*sp));
	if ((sp->data = (double *)malloc(sizeof(data))) == NULL)
		return NULL; 
	memcpy(sp->data, data, dim);
	sp->dim = dim;
	sp->index = index;
	return sp;
}

SPPoint* spPointCopy(SPPoint* source) 
{
	assert (source != NULL);
	SPPoint *sp = malloc(sizeof(*source));
	if (sp == NULL)
		return NULL;
	if ((sp->data = (double *)malloc(sizeof(source->data))) == NULL)
		return NULL;
	memcpy(sp->data, source->data, source->dim);
	sp->dim = source->dim;
	sp->index = source->index;
	return sp;
}


void spPointDestroy(SPPoint* point) 
{	
	assert (point != NULL);
	free(point->data);
	free(point);
}

int spPointGetDimension(SPPoint* point)
{
	assert (point != NULL);
	return point->dim;
}

int spPointGetIndex(SPPoint* point) 
{
	assert (point != NULL);
	return point->index;
}

int main(void)
{
	double d[3] = {0.23,0.7,0.24};
	SPPoint *sp = spPointCreate(d,3,1);
	SPPoint *spcpy = spPointCopy(sp);
	if (spPointGetAxisCoor(sp,2) != sp->data[1])
	{
		printf("%s\n", "something wrong");
	}
	printf("dim is: %d index is: %d\n", spPointGetDimension(spcpy), spPointGetIndex(spcpy));
	spPointDestroy(sp);
	spPointDestroy(spcpy);
	printf("%s\n", "destroied");
	return 0;
}

double spPointGetAxisCoor(SPPoint* point, int axis) 
{
	assert (point!=NULL && axis < point->dim);
	return point->data[axis-1];
}

double spPointL2SquaredDistance(SPPoint* p, SPPoint* q) 
{
	int i;
	double dist = 0;
	assert (p!=NULL && q!=NULL && p->dim == q->dim);

	for (i = 0; i < count; ++i)
	{
		dist += pow((p->data[i])-(p->data[i]),2);
	}
	return dist;
}
