#include <stdio.h>
#include "dijkstra.h"

/*
    ----'8'---- A ----'4'----
   /            |            \
  /            '1'            \
 /              |              \
B -----'7'----- C -----'5'----- D
 \             / \             /
  '4'         '3' '9'         '4'
   \         /     \         /
    \-- E --/       \-- F --/
*/

/* main */
int main(void) {
	graph G = { 0, NULL };
	char from, to;
	DijekstraResult shortest_path;

	// insert vertex to graph
	newVertexToGraph(&G, 'A');
	newVertexToGraph(&G, 'B');
	newVertexToGraph(&G, 'C');
	newVertexToGraph(&G, 'D');
	newVertexToGraph(&G, 'E');
	newVertexToGraph(&G, 'F');

	// make undirect edge
	insertEdge(getVertexAddr(&G, 'A'), getVertexAddr(&G, 'B'), 8, UNDIRECT);
	insertEdge(getVertexAddr(&G, 'A'), getVertexAddr(&G, 'C'), 1, UNDIRECT);
	insertEdge(getVertexAddr(&G, 'A'), getVertexAddr(&G, 'D'), 4, UNDIRECT);
	insertEdge(getVertexAddr(&G, 'B'), getVertexAddr(&G, 'C'), 7, UNDIRECT);
	insertEdge(getVertexAddr(&G, 'B'), getVertexAddr(&G, 'E'), 4, UNDIRECT);
	insertEdge(getVertexAddr(&G, 'C'), getVertexAddr(&G, 'D'), 5, UNDIRECT);
	insertEdge(getVertexAddr(&G, 'C'), getVertexAddr(&G, 'E'), 3, UNDIRECT);
	insertEdge(getVertexAddr(&G, 'C'), getVertexAddr(&G, 'F'), 9, UNDIRECT);
	insertEdge(getVertexAddr(&G, 'D'), getVertexAddr(&G, 'F'), 4, UNDIRECT);

	scanf("%c %c", &from, &to);
	shortest_path = DijkstraShortestPathsSingleTargetCount(&G, getVertexAddr(&G, from), getVertexAddr(&G, to));
	printf("%c, %c: 최단 경로 = %d, 최단 경로의 수 = %d\n", from, to, shortest_path.cost, shortest_path.count);
}
