#include "SPBPriorityQueue.h"
#include <stdbool.h>

struct sp_bp_queue_t
{
	BPQueueElement *elements;
	int is_empty;
	int size;
	int max_size;
};

/**
 * Allocate a new Queue in the memory.
 * New SPBQueue such that:
 *
 * - is_empty = flag to chack is empty, set to false.
 * - size = the current size of the queue, set to zero.
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

	spq->is_empty = true;
	spq->size = 0;
	spq->max_size = maxSize;
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
 * 'Ignore' if source == NULL or queue is empty.
*/
void spBPQueueDestroy(SPBPQueue* source)
{
	if ( source != NULL && !is_empty)
	{
		int i;
		for (i = 0; i < source->size; ++i)
			free(source->elements[source->size -1 -i]);

		free(source->elements);
		free(source);
	}
}

/**
 * Remove all elements in the Queue.
 *
 * @param source - the Queue need to clear.
 * 'Ignore' if source == NULL
 */
void spBPQueueClear(SPBPQueue* source)
{
	if ( source == NULL)
		return;
	source->is_empty = true;
	source->size = 0;

}

/**
 * Give the size of the Queue.
 *
 * @param source - the queue need to check size.
 * @retrun the size of the queue,
 * In case NULL pointer retrun -1.
 */
int spBPQueueSize(SPBPQueue* source)
{
	if (source != NULL)
		return source->size;
	return -1;
}

/**
 * Give the upperbound of the elements to insert source queue.
 *
 * @param source - the queue need to check upperbound.
 * @retrun the upperbound of the array,
 * In case NULL pointer retrun -1.
 */
int spBPQueueGetMaxSize(SPBPQueue* source){
	if (source != NULL)
		return source->max_size;
	return -1;
}


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
 * @retrun true in case Queue is empty or the Queue is a NULL pointer,
 *Otherwise, return false.
 */
bool spBPQueueIsEmpty(SPBPQueue* source)
{
	if (source != NULL)
		return is_empty;
	return true;
}

/**
 * say whatever the Queue is full or not
 *
 * @param source - the Queue to check.
 * @retrun true in case Queue is full or the Queue is a NULL pointer,
 * Otherwise, return false.
 */
bool spBPQueueIsFull(SPBPQueue* source);
{
	if (source != NULL)
		return (source->size == source->max_size);
	return true;
}
