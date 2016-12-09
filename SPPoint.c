#include "SPPoint.h"

struct sp_point_t
{

};

SPPoint* spPointCreate(double* data, int dim, int index) {return NULL;}

SPPoint* spPointCopy(SPPoint* source) {return NULL;}

void spPointDestroy(SPPoint* point) {}

int spPointGetDimension(SPPoint* point){return 0;}

int spPointGetIndex(SPPoint* point) {return 0;}

double spPointGetAxisCoor(SPPoint* point, int axis) {return 0;}

double spPointL2SquaredDistance(SPPoint* p, SPPoint* q) {return 0;}