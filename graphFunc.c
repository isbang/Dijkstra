#include <stdlib.h>
#include "graphFunc.h"


/**
 * @brief      return vertex address which found by name
 *
 * @param      G     Graph
 * @param      Name  vertex name to find address
 *
 * @return     [vertex*]
 */
vertex* getVertexAddr(graph *G, const char Name) {
    vertex *pVer = G->pVHead;
    while (pVer) {
        if (pVer->name == Name) return pVer;
        pVer = pVer->pNext;
    }
    return NULL;
}


/**
 * @brief      make new vertex into graph
 *
 * @param      G     Graph
 * @param      Name  vertex name
 */
void newVertexToGraph(graph *G, const char Name) {
    vertex *pVer = G->pVHead;

    // new vertex init
    vertex *new_vertex = (vertex*)malloc(sizeof(vertex));
    new_vertex->name = Name;
    new_vertex->deg = 0;
    new_vertex->pEdge = NULL;
    new_vertex->pNext = NULL;

    // if graph is empty
    if (pVer == NULL) {
        G->pVHead = new_vertex;
    }
    else {
        // find last vertex
        while (pVer->pNext) pVer = pVer->pNext;
        pVer->pNext = new_vertex;
    }

    G->v_num++;
}


/**
 * @brief      add edge
 *
 * @param      from    vertex address to start
 * @param      to      vertex address to end
 * @param      weight  length between [from] to [to]
 * @param      mod     (0: DIRECT, 1: UNDIRECT)
 */
void insertEdge(vertex *from, vertex *to, int weight, int mod) {
    edge *pEdg = from->pEdge;

    // new edge init
    edge *new_edge = (edge*)malloc(sizeof(edge));
    new_edge->weight = weight;
    new_edge->pVer = to;
    new_edge->pNext = NULL;

    if (pEdg == NULL) {
        from->pEdge = new_edge;
    }
    else {
        while (pEdg->pNext) pEdg = pEdg->pNext;
        pEdg->pNext = new_edge;
    }

    if (mod) insertEdge(to, from, weight, DIRECT);
}
