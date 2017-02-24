#include "graphFunc.h"
#include "priorityQueue.h"

typedef struct _DijekstraResult {
	int count;
	int cost;
}DijekstraResult;


DijekstraResult DijkstraShortestPathsSingleTargetCount(graph* G, vertex* from, vertex* to);
