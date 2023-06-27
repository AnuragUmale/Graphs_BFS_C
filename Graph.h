/*
==========================================
Name: Anurag Prashant Umale              =   
Student Id: 1887255                      =
E-mail: aumale@ucsc.edu                  =
File: Graph.h                            =
Class: CSE 101 Spring 2023               =
==========================================
*/

#ifndef GRAPH_H_INCLUDE_
#define GRAPH_H_INCLUDE_

#include <stdio.h>
#include "List.h" // Including the list ADT
#define INF -1 // defining INF as -1
#define NIL 0 // defining NIL as 0
#define WHITE 0 // defining WHITE as 0
#define GRAY 1 // defining GRAY as 1
#define BLACK 2 // defining BLACK as 2

typedef struct GraphObj* Graph; // typecasting the object pointer to type Graph

// ===================== Constructor & Destructor =====================
Graph newGraph(int n);

void freeGraph(Graph* pG);

// ===================== Access Function =====================

int getOrder(Graph G);

int getSource(Graph G);

int getSize(Graph G);

int getParent(Graph G, int u);

int getDist(Graph G, int u);

void getPath(List L, Graph G, int u);

// ===================== Malipulation Function =====================

void makeNull(Graph G);

void addEdge(Graph G, int u, int v);

void addArc(Graph G, int u, int v);

void BFS(Graph G, int s);

// ===================== Other Function =====================

void printGraph(FILE* out, Graph G);

#endif