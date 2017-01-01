#include "../SPPoint.h"
#include "unit_test_util.h"
#include <stdbool.h>

bool spPointCreateCheck()
{
	double d[3] = {0.23,0.7,0.24};
	int dim = 3;
	int index = 1;
	int i;
	SPPoint* p = spPointCreate(data, dim, index);
	ASSERT_TRUE(spPointCreate(NULL, dim, index) == NULL);
	ASSERT_TRUE(spPointCreate(data , 0, index) == NULL);
	ASSERT_TRUE(spPointCreate(NULL, dim, -1) == NULL);
	ASSERT_TRUE(spPointGetIndex(p) == index);
	ASSERT_TRUE(spPointGetDimension(p) == dim);
	for (i = 0; i < spPointGetDimension(p); ++i)
	{
		ASSERT_TRUE(spPointGetAxisCoor(p, i+1) == data[i]);
	}
	spPointDestroy(p);
	return true;
}

bool spPointCopyCheck()
{
	double d[3] = {0.23,0.7,0.24};
	int dim = 3;
	int index = 1;
	int i;
	SPPoint* p = spPointCreate(data, dim, index);
	SPPoint* q = spPointCopy(p);
	ASSERT_TRUE(spPointGetIndex(p) == spPointGetIndex(q));
	ASSERT_TRUE(spPointGetDimension(p) == spPointGetDimension(q));
	for (i = 0; i < spPointGetDimension(p); ++i)
	{
		ASSERT_TRUE(spPointGetAxisCoor(p, i) == spPointGetAxisCoor(q, i));
	}
	spPointDestroy(p);
	spPointDestroy(q);
	return true;
}

bool spPointGetDimensionCheck()
{
	double d[3] = {0.23,0.7,0.24};
	int dim = 3;
	int index = 1;
	SPPoint* p = spPointCreate(data, dim, index);
	ASSERT_TRUE(spPointGetDimension(p) == dim);
	spPointDestroy(p);
	return true;
}

bool spPointGetIndexCheck()
{
	double d[3] = {0.23,0.7,0.24};
	int dim = 3;
	int index = 1;
	SPPoint* p = spPointCreate(data, dim, index);
	ASSERT_TRUE(spPointGetIndex(p) == index);
	spPointDestroy(p);
	return true;
}

bool spPointGetAxisCoorCheck()
{
	double d[3] = {0.23,0.7,0.24};
	int dim = 3;
	int index = 1;
	int i;
	SPPoint* p = spPointCreate(data, dim, index);
	for (i = 0; i < dim; ++i)
	{
		ASSERT_TRUE(spPointGetAxisCoor(p, i+1) == data[i]);
	}
	spPointDestroy(p);
	return true;
}

bool spPointL2SquaredDistanceCheck()
{
	double d[3] = {0.23,0.7,0.24};
	double d1[3] = {1.23,0.7,0.25};
	int dim = 3;
	int ind1 = 13;
	int ind2 = 12;
	SPPoint* p = spPointCreate(d, dim, ind1);
	SPPoint* q = spPointCreate(d1, dim, ind2);
	ASSERT_TRUE(spPointL2SquaredDistance(p, p) == 0.0);
	ASSERT_TRUE(spPointL2SquaredDistance(q, q) == 0.0);
	ASSERT_FALSE(spPointL2SquaredDistance(p, q) == 1.00005);
	spPointDestroy(p);
	spPointDestroy(q);
	return true;
}

int main()
{
	RUN_TEST(spPointCreateCheck);
	RUN_TEST(spPointCopyCheck);
	RUN_TEST(spPointGetDimensionCheck);
	RUN_TEST(spPointGetIndexCheck);
	RUN_TEST(spPointGetAxisCoorCheck);
	RUN_TEST(spPointL2SquaredDistanceCheck);
	return 0;
}