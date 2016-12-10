#include "SPPoint.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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

int main(void)
{
	double d[3] = {0.23,0.7,0.24};
	SPPoint *sp = spPointCreate(d,3,1);
	SPPoint *spcpy = spPointCopy(sp);
	printf("dim is: %d index is: %d\n", spcpy->dim, spcpy->index);
	spPointDestroy(sp);
	spPointDestroy(spcpy);
	printf("%s\n", "destroied");
	return 0;
}

void spPointDestroy(SPPoint* point) 
{
	free(point->data);
	free(point);
}

/*
int spPointGetDimension(SPPoint* point){return 0;}

int spPointGetIndex(SPPoint* point) {return 0;}

double spPointGetAxisCoor(SPPoint* point, int axis) {return 0;}

double spPointL2SquaredDistance(SPPoint* p, SPPoint* q) {return 0;}
*/
