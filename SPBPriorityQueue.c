#include "SPBPriorityQueue.h"

struct sp_bp_queue_t
{
	BPQueueElement *elements;
	int is_empty;
	int size;
	int maxsize;

};


SPBPQueue* spBPQueueCreate(int maxSize);


SPBPQueue* spBPQueueCopy(SPBPQueue* source);


void spBPQueueDestroy(SPBPQueue* source);


void spBPQueueClear(SPBPQueue* source);


int spBPQueueSize(SPBPQueue* source);


int spBPQueueGetMaxSize(SPBPQueue* source);


SP_BPQUEUE_MSG spBPQueueEnqueue(SPBPQueue* source, int index, double value);


SP_BPQUEUE_MSG spBPQueueDequeue(SPBPQueue* source);


SP_BPQUEUE_MSG spBPQueuePeek(SPBPQueue* source, BPQueueElement* res);


SP_BPQUEUE_MSG spBPQueuePeekLast(SPBPQueue* source, BPQueueElement* res);


double spBPQueueMinValue(SPBPQueue* source);


double spBPQueueMaxValue(SPBPQueue* source);


bool spBPQueueIsEmpty(SPBPQueue* source);


bool spBPQueueIsFull(SPBPQueue* source);