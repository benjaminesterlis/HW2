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
	sp->data = memcpy(sp->data, data, dim);
	sp->dim = dim;
	sp->index = index;
	return sp;
}

SPPoint* spPointCopy(SPPoint* source) {return NULL;}

void spPointDestroy(SPPoint* point) {}

int spPointGetDimension(SPPoint* point){return 0;}

int spPointGetIndex(SPPoint* point) {return 0;}

double spPointGetAxisCoor(SPPoint* point, int axis) {return 0;}

double spPointL2SquaredDistance(SPPoint* p, SPPoint* q) {return 0;}