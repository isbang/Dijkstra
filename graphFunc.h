#define DIRECT      0           // 단방향
#define UNDIRECT    1           // 양방향

typedef struct _edge {  // 간선
    int weight;     // 가중치
    struct _vertex *pVer;  // 연결될 곳
    struct _edge *pNext;
}edge;

typedef struct _vertex { // 정점
    char name;  // 정점 이름
    int deg;    // 계수
    struct _edge *pEdge;    // 간선
    struct _vertex *pNext;
}vertex;

typedef struct _graph { // 그래프 노드
    int v_num;  // 정점 갯수
    vertex *pVHead;  // 정점
}graph;

/* 그래프 구조도
/-- graph ------------------------------------------------------
| v_num
| *pVHead  ->/==== vertex ====\  /->/===== edge =====\  /-> edge
|           | name           |  |  | weight         |  |
|           | deg            |  |  | vertex *pVer   |  |
|           | edge *pEdge ---|--/  | edge *pNext  --|--/
|       /---|-vertex *pNext  |     \================/
|       |   \================/
|       |
|       \-->/==== vertex ====\  /->/===== edge =====\  /-> edge
|           | name           |  |  | weight         |  |
*/

vertex* getVertexAddr(graph *G, const char Name);
void newVertexToGraph(graph *G, const char Name);
void insertEdge(vertex *from, vertex *to, int weight, int mod);
