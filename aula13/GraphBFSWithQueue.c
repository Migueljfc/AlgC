//
// Joaquim Madeira, AlgC, May 2020
// João Manuel Rodrigues, AlgC, May 2020
//
// GraphBFS - QUEUE-based Breadth-First Search
//

#include "GraphBFSWithQueue.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "IntegersQueue.h"
#include "IntegersStack.h"

struct _GraphBFSWithQueue {
  unsigned int* marked;
  int* distance;
  int* predecessor;
  Graph* graph;
  unsigned int startVertex;
};

GraphBFSWithQueue* GraphBFSWithQueueExecute(Graph* g,
                                            unsigned int startVertex) {
  assert(g != NULL);
  assert(0 <= startVertex && startVertex < GraphGetNumVertices(g));

  GraphBFSWithQueue* traversal =
      (GraphBFSWithQueue*)malloc(sizeof(struct _GraphBFSWithQueue));
  assert(traversal != NULL);

  unsigned int numVertices = GraphGetNumVertices(g);

  //
  // COMPLETAR !!
  //
  // CRIAR e INICIALIZAR os campos de traversal
  // traversal->marked
  // traversal->distance
  // traversal->predecessor
  
  traversal->marked = (unsigned int*)calloc(numVertices, sizeof(unsigned int));
  if(traversal->marked == NULL){
    return NULL;
  } 
  traversal->predecessor = (int*)malloc(numVertices* sizeof(int));
  if(traversal->predecessor == NULL){
    return NULL;
  }

  for(int i = 0; i < numVertices;i++){
    traversal->predecessor[i] = -1;
  }
  traversal->distance = (int*)malloc(numVertices* sizeof(int));
  if(traversal->distance == NULL){
    return NULL;
  }
  for(int i = 0; i < numVertices;i++){
    traversal->predecessor[i] = 0;
  }

  traversal->predecessor[startVertex] = 0;
  
  traversal->graph = g;
  traversal->startVertex = startVertex;

  // EFETUAR A TRAVESSIA

  // COMPLETAR !!
  Queue* queue = QueueCreate(numVertices);
  QueueEnqueue(queue,startVertex);
  traversal->marked[startVertex] = 1;
  
  while (!QueueIsEmpty(queue))
  {
    startVertex = QueueDequeue(queue);
    int* adj = GraphGetAdjacentsTo(g,startVertex);
    for(int i = 1;i < adj[0]; i++){
      int adjVer = adj[i];
      if(!traversal->marked[adjVer]){
        traversal->distance[adjVer] = traversal->distance[startVertex] + 1;
        traversal->predecessor[adjVer] = startVertex;
        QueueEnqueue(queue,adjVer);
        traversal->marked[adjVer] = 1;
      }
    }
  }
  
  return traversal;
}

void GraphBFSWithQueueDestroy(GraphBFSWithQueue** p) {
  assert(*p != NULL);

  GraphBFSWithQueue* aux = *p;

  free(aux->marked);
  free(aux->predecessor);

  free(*p);
  *p = NULL;
}

// Getting the result

unsigned int GraphBFSWithQueueHasPathTo(const GraphBFSWithQueue* p,
                                        unsigned int v) {
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  return p->marked[v];
}

Stack* GraphBFSWithQueuePathTo(const GraphBFSWithQueue* p, unsigned int v) {
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  Stack* s = StackCreate(GraphGetNumVertices(p->graph));

  if (p->marked[v] == 0) {
    return s;
  }

  // Store the path
  for (unsigned int current = v; current != p->startVertex;
       current = p->predecessor[current]) {
    StackPush(s, current);
  }

  StackPush(s, p->startVertex);

  return s;
}

// DISPLAYING on the console

void GraphBFSWithQueueShowPath(const GraphBFSWithQueue* p, unsigned int v) {
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  Stack* s = GraphBFSWithQueuePathTo(p, v);

  while (StackIsEmpty(s) == 0) {
    printf("%d ", StackPop(s));
  }

  StackDestroy(&s);
}

void GraphBFSWithQueueDisplay(const GraphBFSWithQueue* p) {
   // COMPLETAR !!
  for(int i = 0;i < GraphGetNumVertices(p->graph); i++){
    GraphDFSWithQueueShowPath(p,i);
  }
}
