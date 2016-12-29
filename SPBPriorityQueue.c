#include "SPBPriorityQueue.h"
#include <stdbool.h>

struct sp_bp_queue_t
{
	BPQueueElement *elements;
	int is_empty;
	int size;
	int max_size;
	int max_value;

};

/**
 * Allocate a new Queue in the memory.
 * new SPBQueue such that:
 * - is_empty = flag to chack is empty, set to False.
 * - size = the current size of the queue, set to zero.
 * - max_value =  the max value in the queue.
 * - elements = pointer to the first element in the queue.
 * 
 * @param  maxSize - int, which refer to the upperbound to no. of elements
 * @return spq - pointer to SPBPQueue
 * SP_BPQUEUE_OUT_OF_MEMORY in case of allocation failure.
 * SP_BPQUEUE_INVALID_ARGUMENT in case of non-positive maxSize.
 */
SPBPQueue* spBPQueueCreate(int maxSize)
{
	if (maxSize <= 0 )
		return SP_BPQUEUE_INVALID_ARGUMENT;

	SPBQueue *spq = malloc(sizeof(*spq));
	if ( spq == NULL )
		return SP_BPQUEUE_OUT_OF_MEMORY;
	
	if ((spq->elements = (BPQueueElement*) malloc(sizeof(BPQueueElement) * maxSize) == NULL)	
		return SP_BPQUEUE_OUT_OF_MEMORY;

	spq->is_empty = True;
	spq->size = 0;
	spq->max_size = maxSize;
	spq->max_value = 0;
	return spq;

}

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


bool spBPQueueIsEmpty(SPBPQueue* source)
{
	if (source->is_empty == 0)
		return True;
	return False;
};


bool spBPQueueIsFull(SPBPQueue* source);