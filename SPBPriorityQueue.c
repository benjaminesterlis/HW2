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
 * New SPBQueue such that:
 * - is_empty = flag to chack is empty, set to False.
 * - size = the current size of the queue, set to zero.
 * - max_value =  the max value in the queue.
 * - elements = pointer to the first element in the queue.
 * - max_size = the upper bould of elements in the Queue.
 * 
 * @param  maxSize - int, which refer to the upperbound to no. of elements
 * @return spq - pointer to SPBPQueue
 * NULL in case of allocation failure.
 * NULL in case of non-positive maxSize.
 */
SPBPQueue* spBPQueueCreate(int maxSize)
{
	if (maxSize <= 0 )
		return SP_BPQUEUE_INVALID_ARGUMENT;

	SPBQueue *spq = malloc(sizeof(*spq));
	if ( spq == NULL )
		return NULL;
	
	if ((spq->elements = (BPQueueElement*) malloc(sizeof(BPQueueElement) * maxSize) == NULL))	
		return NULL;

	spq->is_empty = True;
	spq->size = 0;
	spq->max_size = maxSize;
	spq->max_value = 0;
	return spq;
}


/**
 * Copy and elements array from source to target
 *
 * @param target - the destination Queue to insert the elements array.
 * @param source - the source Queue which we copy elemnts from.
 */
void ElementCopy(SPBPQueue* target,SPBPQueue* source){
	int i;
	for (i = 0; i < source->size; ++i)
	{
		target->elements[i].index = source->elements[i].index;//ask beni if need ->elements
		target->elements[i].value = source->elements[i].value;//ask beni if need ->elements
	}
}

/**
 * Allocate a copu of the source SPBPQueue.
 * Copy the source SPBPQueue into a new Queue called spcpy such that:
 *
 * - is_empty(spcpy) = is_empty(source) (spcpy and source has the same flag for emptyness). 
 * - size(spcpy) = size(source) (spcpy and source have the same size).
 * - max_value(spcpy) = max_value(source) (spcpy and source have the same max value).
 * - max_size(spcpy) = max_size(source) (spcpy and source have the same upper bound of elements).
 * - elements(spcpy) = elements(source) (spcpy and source have the same elements, which include the same index and value inside).
 *
 * @param source - the SPBPQueue we want to copy.
 * @return spcpy - copy of source.
 * NULL in case of allocation failure.  
 */
SPBPQueue* spBPQueueCopy(SPBPQueue* source)
{
	SPBPQueue *spcpy = malloc(sizeof(*spcpy));
	if ( spcpy == NULL )
		return NULL;

	spcpy->is_empty = source->is_empty;
	spcpy->size = source->size;
	spcpy->max_size = source->max_size;
	spcpy->max_value = source->max_value;
	if ((spcpy->elements = (BPQueueElement*) malloc(sizeof(BPQueueElement) * maxSize) == NULL))	
		return NULL;
	Elementcopy(spcpy,source);
	return spcpy;
}

/**
 * Free all memory allocation associated with the Queue,
 * First, free all data from the cells.
 * Second, free the point to the arrary.
 * Third, free the Queue pointer.
 *
 * @param source - the Queue we want to free all memory aloocation associated.
 * Assert if source == NULL or queue is empty
*/
void spBPQueueDestroy(SPBPQueue* source)
{
	if (source == NULL)
		return;

	if (is_empty)
		return;

	int i;
	for (i = 0; i < source->size; ++i)
		free(source->elements[source->size -i]);

	free(source->elements);
	free(source);
}

/**
 * remove all elemnts in the Queue.
 *
 *
 *
 */
void spBPQueueClear(SPBPQueue* source)
{
	if (source == NULL)
		return;

	if (is_empty)
		return;

	int i;
	for (i = 0; i < source->size; ++i)
		free(source->elements[source->size -i]);

}


int spBPQueueSize(SPBPQueue* source);


int spBPQueueGetMaxSize(SPBPQueue* source);


SP_BPQUEUE_MSG spBPQueueEnqueue(SPBPQueue* source, int index, double value);


SP_BPQUEUE_MSG spBPQueueDequeue(SPBPQueue* source);


SP_BPQUEUE_MSG spBPQueuePeek(SPBPQueue* source, BPQueueElement* res);


SP_BPQUEUE_MSG spBPQueuePeekLast(SPBPQueue* source, BPQueueElement* res);


double spBPQueueMinValue(SPBPQueue* source);


double spBPQueueMaxValue(SPBPQueue* source);

/**
 * say whatever the Queue is empty or not.
 *
 * @param source - the Queue to check.
 * @retrun True in case Queue is empty.
 *Otherwise, return False.
 */
bool spBPQueueIsEmpty(SPBPQueue* source)
{
	return is_empty;
}

bool spBPQueueIsFull(SPBPQueue* source);
