#include "SPPoint.h"

struct sp_point_t
{

};

SPPoint* spPointCreate(double* data, int dim, int index);

SPPoint* spPointCopy(SPPoint* source);

void spPointDestroy(SPPoint* point);

int spPointGetDimension(SPPoint* point);

int spPointGetIndex(SPPoint* point);

double spPointGetAxisCoor(SPPoint* point, int axis);

double spPointL2SquaredDistance(SPPoint* p, SPPoint* q);