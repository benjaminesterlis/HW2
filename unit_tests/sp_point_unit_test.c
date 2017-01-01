#include "../SPPoint.h"
#include "unit_test_util.h"
#include <stdbool.h>

bool spPointCreateCheck()
{
	double data[2] = { 1.0, 1.0 };
	int dim = 2;
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
	double data[2] = { 1.0, 1.0 };
	int dim = 2;
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
	double data[2] = { 1.0, 1.0 };
	int dim = 2;
	int index = 1;
	SPPoint* p = spPointCreate(data, dim, index);
	ASSERT_TRUE(spPointGetDimension(p) == dim);
	spPointDestroy(p);
	return true;
}

bool spPointGetIndexCheck()
{
	double data[2] = { 1.0, 1.0 };
	int dim = 2;
	int index = 1;
	SPPoint* p = spPointCreate(data, dim, index);
	ASSERT_TRUE(spPointGetIndex(p) == index);
	spPointDestroy(p);
	return true;
}

bool spPointGetAxisCoorCheck()
{
	double data[2] = { 1.0, 1.0 };
	int dim = 2;
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
	double data1[2] = { 1.0, 1.0 };
	double data2[2] = { 1.0, 0.0 };
	int dim1 = 2;
	int dim2 = 2;
	int index1 = 1;
	int index2 = 1;
	SPPoint* p = spPointCreate(data1, dim1, index1);
	SPPoint* q = spPointCreate(data2, dim2, index2);
	ASSERT_TRUE(spPointL2SquaredDistance(p, p) == 0.0);
	ASSERT_TRUE(spPointL2SquaredDistance(q, q) == 0.0);
	ASSERT_FALSE(spPointL2SquaredDistance(p, q) == 0.0);
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