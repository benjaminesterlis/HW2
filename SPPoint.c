#include "SPPoint.h"
#include <string.h>

struct sp_point_t
{
	double* data;
	int dim;
	int index;
};

SPPoint* spPointCreate(double* data, int dim, int index) 
{
	SPPoint *sp = malloc(sizeof(*sp));
	if((sp->data = (double *)malloc(sizeof(data))) == NULL)
		return NULL; 
	memcpy(sp->data, data, dim);
	sp->dim = dim;
	sp->index = index;
	return sp;
}

SPPoint* spPointCopy(SPPoint* source) 
{
	if((SPPoint *sp = malloc(sizeof(*source))) == NULL)
		return NULL;
	if((sp->data = (double *)malloc(sizeof(source->data))) == NULL)
		return NULL;
	memcpy(sp->data, source->data, source->dim);
	sp->dim = source->dim;
	sp->index = source->index;
	return sp;
}

void spPointDestroy(SPPoint* point) {}

int spPointGetDimension(SPPoint* point){return 0;}

int spPointGetIndex(SPPoint* point) {return 0;}

double spPointGetAxisCoor(SPPoint* point, int axis) {return 0;}

double spPointL2SquaredDistance(SPPoint* p, SPPoint* q) {return 0;}