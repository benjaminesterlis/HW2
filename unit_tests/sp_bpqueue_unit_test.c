#include "../SPBPriorityQueue.h"
#include "unit_test_util.h"
#include <stdbool.h>
#include <stdlib.h>

bool spBPQueueCreateCheck()
{
	int maxSize = 3;
	SPBPQueue* q = spBPQueueCreate(maxSize);
	ASSERT_TRUE(spBPQueueGetMaxSize(q) == maxSize);
	ASSERT_TRUE(spBPQueueSize(q) == 0);
	spBPQueueDestroy(q);
	return true;
}

bool spBPQueueCopyCheck()
{
	int maxSize = 3;
	SPBPQueue* q = spBPQueueCreate(maxSize);
	SPBPQueue* q2;
	spBPQueueEnqueue(q, 1, 3);
	spBPQueueEnqueue(q, 5, 2);
	spBPQueueEnqueue(q, 7, 23);
	q2 = spBPQueueCopy(q);
	ASSERT_TRUE(spBPQueueGetMaxSize(q) == spBPQueueGetMaxSize(q2));
	ASSERT_TRUE(spBPQueueSize(q) == spBPQueueSize(q2));
	ASSERT_TRUE(spBPQueueMinValue(q) == spBPQueueMinValue(q2));
	ASSERT_TRUE(spBPQueueMaxValue(q) == spBPQueueMaxValue(q2));
	spBPQueueDestroy(q);
	spBPQueueDestroy(q2);
	return true;
}

bool spBPQueueClearCheck()
{
	int maxSize = 3;
	SPBPQueue* q = spBPQueueCreate(maxSize);
	spBPQueueEnqueue(q, 1, 3);
	spBPQueueClear(q);
	ASSERT_TRUE(spBPQueueSize(q) == 0);
	spBPQueueDestroy(q);
	return true;
}

bool spBPQueueSizeCheck()
{
	int maxSize = 3;
	SPBPQueue* q = spBPQueueCreate(maxSize);
	ASSERT_TRUE(spBPQueueSize(q) == 0);
	spBPQueueEnqueue(q, 1, 3);
	ASSERT_TRUE(spBPQueueSize(q) == 1);
	spBPQueueDestroy(q);
	return true;
}

bool spBPQueueGetMaxSizeCheck()
{
	int maxSize = 3;
	SPBPQueue* q = spBPQueueCreate(maxSize);
	ASSERT_TRUE(spBPQueueGetMaxSize(q) == maxSize);
	spBPQueueDestroy(q);
	return true;
}

bool spBPQueueEnqueueCheck()
{
	int maxSize = 3;
	SPBPQueue* q = spBPQueueCreate(maxSize);
	ASSERT_TRUE(spBPQueueEnqueue(NULL, 2, 3) == SP_BPQUEUE_INVALID_ARGUMENT);
	ASSERT_TRUE(spBPQueueEnqueue(q, -1, 3) == SP_BPQUEUE_INVALID_ARGUMENT);
	ASSERT_TRUE(spBPQueueEnqueue(q, 2, -1) == SP_BPQUEUE_INVALID_ARGUMENT);
	ASSERT_TRUE(spBPQueueEnqueue(q, 1, 3) == SP_BPQUEUE_SUCCESS);
	ASSERT_TRUE(spBPQueueEnqueue(q, 5, 2) == SP_BPQUEUE_SUCCESS);
	ASSERT_TRUE(spBPQueueMaxValue(q) == 3);
	ASSERT_TRUE(spBPQueueMinValue(q) == 2);
	ASSERT_TRUE(spBPQueueEnqueue(q, 7, 23) == SP_BPQUEUE_SUCCESS);
	ASSERT_TRUE(spBPQueueEnqueue(q, 7, 40) == SP_BPQUEUE_FULL);
	ASSERT_TRUE(spBPQueueEnqueue(q, 9, 23) == SP_BPQUEUE_FULL);
	ASSERT_TRUE(spBPQueueEnqueue(q, 6, 2.5) == SP_BPQUEUE_SUCCESS);
	ASSERT_TRUE(spBPQueueMaxValue(q) == 3);
	spBPQueueDestroy(q);
	return true;
}

bool spBPQueueDequeueCheck()
{
	int maxSize = 3;
	SPBPQueue* q = spBPQueueCreate(maxSize);
	ASSERT_TRUE(spBPQueueDequeue(NULL) == SP_BPQUEUE_INVALID_ARGUMENT);
	ASSERT_TRUE(spBPQueueDequeue(q) == SP_BPQUEUE_EMPTY);
	spBPQueueEnqueue(q, 1, 3);
	spBPQueueEnqueue(q, 5, 2);
	spBPQueueEnqueue(q, 7, 23);
	ASSERT_TRUE(spBPQueueDequeue(q) == SP_BPQUEUE_SUCCESS);
	ASSERT_TRUE(spBPQueueSize(q) == 2);
	spBPQueueDestroy(q);
	return true;
}

bool spBPQueuePeekCheck()
{
	int maxSize = 3;
	BPQueueElement* res;
	SPBPQueue* q = spBPQueueCreate(maxSize);
	if ((res = (BPQueueElement*)malloc(sizeof(res))) == NULL)
		return false;
	ASSERT_TRUE(spBPQueuePeek(q, NULL) == SP_BPQUEUE_INVALID_ARGUMENT);
	ASSERT_TRUE(spBPQueuePeek(NULL, res) == SP_BPQUEUE_INVALID_ARGUMENT);
	ASSERT_TRUE(spBPQueuePeek(q, res) == SP_BPQUEUE_EMPTY);
	spBPQueueEnqueue(q, 1, 3);
	spBPQueueEnqueue(q, 5, 2);
	spBPQueueEnqueue(q, 7, 23);
	ASSERT_TRUE(spBPQueuePeek(q, res) == SP_BPQUEUE_SUCCESS);
	ASSERT_TRUE(res->value == 2 && res->index == 5);
	spBPQueueDestroy(q);
	free(res);
	return true;
}

bool spBPQueuePeekLastCheck()
{
	int maxSize = 3;
	BPQueueElement* res;
	SPBPQueue* q = spBPQueueCreate(maxSize);
	if ((res = (BPQueueElement*)malloc(sizeof(res))) == NULL)
		return false;
	ASSERT_TRUE(spBPQueuePeekLast(q, NULL) == SP_BPQUEUE_INVALID_ARGUMENT);
	ASSERT_TRUE(spBPQueuePeekLast(NULL, res) == SP_BPQUEUE_INVALID_ARGUMENT);
	ASSERT_TRUE(spBPQueuePeekLast(q, res) == SP_BPQUEUE_EMPTY);
	spBPQueueEnqueue(q, 1, 3);
	spBPQueueEnqueue(q, 5, 2);
	spBPQueueEnqueue(q, 7, 23);
	ASSERT_TRUE(spBPQueuePeekLast(q, res) == SP_BPQUEUE_SUCCESS);
	ASSERT_TRUE(res->value == 23 && res->index == 7);
	spBPQueueDestroy(q);
	free(res);
	return true;
}


bool spBPQueueMinValueCheck()
{
	int maxSize = 3;
	SPBPQueue* q = spBPQueueCreate(maxSize);
	spBPQueueEnqueue(q, 1, 3);
	spBPQueueEnqueue(q, 8, 2);
	ASSERT_TRUE(spBPQueueMinValue(q) == 2);
	spBPQueueEnqueue(q, 3, 1);
	ASSERT_TRUE(spBPQueueMinValue(q) == 1);
	spBPQueueDestroy(q);
	return true;
}

bool spBPQueueMaxValueCheck()
{
	int maxSize = 3;
	SPBPQueue* q = spBPQueueCreate(maxSize);
	spBPQueueEnqueue(q, 1, 3);
	spBPQueueEnqueue(q, 6, 2);
	ASSERT_TRUE(spBPQueueMaxValue(q) == 3);
	spBPQueueEnqueue(q, 8, 23);
	ASSERT_TRUE(spBPQueueMaxValue(q) == 23);
	spBPQueueDestroy(q);
	return true;
}

bool spBPQueueIsEmptyCheck()
{
	int maxSize = 3;
	SPBPQueue* q = spBPQueueCreate(maxSize);
	ASSERT_TRUE(spBPQueueIsEmpty(q) == true);
	spBPQueueEnqueue(q, 1, 3);
	ASSERT_TRUE(spBPQueueIsEmpty(q) == false);
	spBPQueueDestroy(q);
	return true;
}

bool spBPQueueIsFullCheck()
{
	int maxSize = 1;
	SPBPQueue* q = spBPQueueCreate(maxSize);
	ASSERT_TRUE(spBPQueueIsFull(q) == false);
	spBPQueueEnqueue(q, 1, 3);
	ASSERT_TRUE(spBPQueueIsFull(q) == true);
	spBPQueueDestroy(q);
	return true;
}
int main()
{
	RUN_TEST(spBPQueueCreateCheck);
	RUN_TEST(spBPQueueCopyCheck);
	RUN_TEST(spBPQueueClearCheck);
	RUN_TEST(spBPQueueSizeCheck);
	RUN_TEST(spBPQueueGetMaxSizeCheck);
	RUN_TEST(spBPQueueEnqueueCheck);
	RUN_TEST(spBPQueueDequeueCheck);
	RUN_TEST(spBPQueuePeekCheck);
	RUN_TEST(spBPQueuePeekLastCheck);
	RUN_TEST(spBPQueueMinValueCheck);
	RUN_TEST(spBPQueueMaxValueCheck);
	RUN_TEST(spBPQueueIsEmptyCheck);
	RUN_TEST(spBPQueueIsFullCheck);

	return 0;
}