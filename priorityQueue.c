#include <stdlib.h>
#include "./priorityQueue.h"

/**
 * @brief      make queue as array
 *
 * @param      size   queue size
 * @return     queue*
 */
queue* initQueue() {
    queue *Q = (queue*)malloc(sizeof(queue));
	for (int i = 0; i < MAX_QUEUE_SIZE + 1; i++) {
		Q->list[i] = NULL;
	}
    Q->tail = 0;

    return Q;
}

/**
 * @brief      enqueue funtion
 *
 * @param      Q     The queue
 * @param      v     data to enqueue
 * @return     int   index
 */
int enqueue(queue *Q, void *pData) {
	if (Q->tail == MAX_QUEUE_SIZE) {	// if queue is full
		return -1;
	}
	node *new_node = (node*)malloc(sizeof(node));
	new_node->pData = pData;
	new_node->priority = MAX;

	Q->list[++Q->tail] = new_node;
	return Q->tail;
}


void downHeap(queue *Q, int index) {
	// if node has both left and right sub node
	if (RIGHT_SUB_NODE(index) <= Q->tail) {
		// if left sub node priority is minimum
		if (Q->list[LEFT_SUB_NODE(index)]->priority < Q->list[RIGHT_SUB_NODE(index)]->priority &&	\
			Q->list[LEFT_SUB_NODE(index)]->priority < Q->list[index]->priority) {
			// swap
			node *temp = Q->list[LEFT_SUB_NODE(index)];
			Q->list[LEFT_SUB_NODE(index)] = Q->list[index];
			Q->list[index] = temp;
			downHeap(Q, LEFT_SUB_NODE(index));
		}
		// else right sub node priority is minimum
		else if (Q->list[RIGHT_SUB_NODE(index)]->priority < Q->list[index]->priority) {
			// swap
			node *temp = Q->list[RIGHT_SUB_NODE(index)];
			Q->list[RIGHT_SUB_NODE(index)] = Q->list[index];
			Q->list[index] = temp;
			downHeap(Q, RIGHT_SUB_NODE(index));
		}
	}
	// else node has left sub node
	else if (LEFT_SUB_NODE(index) <= Q->tail &&	\
		Q->list[LEFT_SUB_NODE(index)]->priority < Q->list[index]->priority) {
		// swap
		node *temp = Q->list[LEFT_SUB_NODE(index)];
		Q->list[LEFT_SUB_NODE(index)] = Q->list[index];
		Q->list[index] = temp;
		downHeap(Q, LEFT_SUB_NODE(index));
	}
	else
		return;
}

/**
 * @brief      dequeue function
 *
 * @param      Q     The Queue
 * @return     node*
 */
node* dequeue(queue *Q) {
	if (Q->tail == 0) {	// if queue is empty
		return NULL;
	}

	// heap sort
	for (int i = Q->tail / 2; i >= 1; i--) {
		downHeap(Q, i);
	}

	// ret->priority is minimum
	node *ret = Q->list[1];

	// 배열 앞으로 한 칸씩 이동
	for (int i = 1; i < Q->tail; i++) {
		Q->list[i] = Q->list[i + 1];
	}
	Q->list[Q->tail--] = NULL;

	return ret;
}


/**
* @brief      return node* found by *pData
*
* @param      Q			The Queue
* @param      pData		data poiunter to find
* @return     node*
*/
node* findNode(queue *Q, void *pData) {
	for (int i = 1; i <= Q->tail; i++) {
		if (Q->list[i]->pData == pData) {
			return Q->list[i];
		}
	}
	return NULL;
}