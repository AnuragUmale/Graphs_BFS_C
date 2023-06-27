/*
=============================================
Name: Anurag Prashant Umale                 =
Student Id: 1887255                         =
E-mail: aumale@ucsc.edu                     =
File: GraphTest.c (Testing the Graph ADT)   =
Class: CSE 101 Spring 2023                  =
=============================================
*/
#include "Graph.h" // Including the Graph header file
#include <stdio.h>
#include <stdlib.h>

void GraphTest_constructorDestructor()
{
  fprintf(stdout, "============= Constructor & Destructor Test =============\n");

  for (int n = 1; n < 100; n++) // running loop 100 times
  {
    Graph G = newGraph(n); // Creating the graph
    freeGraph(&G); // Freeing the graph
    if (G != NULL) // Checking if G not equal to NULL
    {
      fprintf(stdout, "***** Constructor & Destructor Failed *****\n"); // Error Message
      exit(EXIT_FAILURE); // Exiting in failure
    }
  }
  fprintf(stdout, "============= Constructor & Destructor Test Passed =============\n");
}

void GraphTest_getOrder()
{
  fprintf(stdout, "============= getOrder Test =============\n");
  for (int n = 1; n < 100; n++) // running loop 100 times
  {
    Graph G = newGraph(n); // Creating the graph
    if (getOrder(G) != n) // Checking if order is not equal to n
    {
      fprintf(stdout, "***** getOrder Failed *****\n"); // Error Message
      exit(EXIT_FAILURE); // Exiting in failure
    }
    freeGraph(&G); // Freeing the graph
  }
  fprintf(stdout, "============= getOrder Test Passed =============\n");
}

void GraphTest_getSize()
{
  fprintf(stdout, "============= getSize Test =============\n");

  for (int n = 1; n < 100; n++) // running loop 100 times
  {
    Graph UG = newGraph(n); // Creating the graph
    if (getSize(UG) != 0) // Checking if size is not equal to 0
    {
      fprintf(stdout, "***** getSize Failed *****\n"); // Error Message
      exit(EXIT_FAILURE); // Exiting in failure
    }
    for (int k = 1; k <= n; k++) // loop from 1 till n value
    {
      addEdge(UG, k, (k % n) + 1); // adding edge in graph 
      if (getSize(UG) != k) // Checking if size is not equal to k
      {
        fprintf(stdout, "***** getSize Failed *****\n"); // Error Message
        exit(EXIT_FAILURE); // Exiting in failure
      }
    }
    freeGraph(&UG); // Freeing the graph
  }
  fprintf(stdout, "============= getSize Test Passed =============\n");
}

void GraphTest_getSource()
{
  fprintf(stdout, "============= getSource Test =============\n");

  for (int n = 1; n < 100; n++) // running loop 100 times
  {
    Graph G = newGraph(n); // Creating the graph
    if (getSource(G) != NIL) // Checking if the source is Not equal to NIL
    {
      fprintf(stdout, "***** getSource Failed *****\n"); // Error Message
      exit(EXIT_FAILURE); // Exiting in failure
    }
    freeGraph(&G); // Freeing the graph
  }
  fprintf(stdout, "============= getSource Test Passed =============\n");
}

void GraphTest_getParent()
{
  fprintf(stdout, "============= getParent Test =============\n");

  for (int n = 1; n < 100; n++) // running loop 100 times
  {
    Graph G = newGraph(n); // Creating the graph
    for (int u = 1; u <= getOrder(G); u++) // Loop form 1 till order of the Graph
    {
      if (getParent(G, u) != NIL) // checking if the parent is not equal to NULL
      {
        fprintf(stdout, "***** getParent Failed *****\n"); // Error Message
        exit(EXIT_FAILURE); // Exiting in failure
      }
    }
    freeGraph(&G); // Freeing the graph
  }
  fprintf(stdout, "============= getParent Test Passed =============\n");
}

void GraphTest_getDist()
{
  fprintf(stdout, "============= getDist Test =============\n");
  for (int n = 1; n < 100; n++) // running loop 100 times
  {
    Graph G = newGraph(n); // Creating the graph
    for (int u = 1; u <= getOrder(G); u++)
    {
      if (getDist(G, u) != INF) // checking if Distance is not equal to INF
      {
        fprintf(stdout, "***** getDist Failed *****\n"); // Error Message
        exit(EXIT_FAILURE); // Exiting in failure
      }
    }
    freeGraph(&G); // Freeing the graph
  }
  fprintf(stdout, "============= getDist Test Passed =============\n");
}

void GraphTest_makeNull()
{
  fprintf(stdout, "============= makeNull Test =============\n");

  for (int n = 1; n < 100; n++) // running loop 100 times
  {
    Graph G = newGraph(n); // Creating the graph
    makeNull(G); // calling the makeNull function
    if (getSize(G) != 0) // checking if the size of the Graph is not equal to 0
    {
      fprintf(stdout, "***** makeNull Failed *****\n"); // Error Message
      exit(EXIT_FAILURE); // Exiting in failure
    }
    freeGraph(&G); // Freeing the graph
  }
  fprintf(stdout, "============= makeNull Test Passed =============\n");
}

void GraphTest_addArc()
{
  fprintf(stdout, "============= addArc Test =============\n");

  for (int n = 1; n < 100; n++) // running loop 100 times
  {
    Graph G = newGraph(n); // Creating the graph
    for (int i = 0; i < 100; i++) // running loop 100 times
    {
      int u = (rand() % getOrder(G)) + 1; // random number is taken in range of order of graph for vertex u
      int v = (rand() % getOrder(G)) + 1; // random number is taken in range of order of graph for vertex v
      addArc(G, u, v); // Arc is added in the graph
    }
    freeGraph(&G); // Freeing the graph
  }
  fprintf(stdout, "============= addArc Test Passed =============\n");
}

void GraphTest_addEdge()
{
  fprintf(stdout, "============= addEdge Test =============\n");

  for (int n = 1; n < 100; n++) // running loop 100 times
  {
    Graph G = newGraph(n); // Creating the graph
    for (int i = 0; i < 100; i++) // running loop 100 times
    {
      int u = (rand() % getOrder(G)) + 1; // random number is taken in range of order of graph for vertex u
      int v = (rand() % getOrder(G)) + 1; // random number is taken in range of order of graph for vertex v
      addEdge(G, u, v); // Edge is added to the Graph
    }
    freeGraph(&G); // Freeing the graph
  }
  fprintf(stdout, "============= addEdge Test Passed =============\n");
}

void GraphTest_printGraph()
{
  fprintf(stdout, "============= printGraph Test =============\n");

  for (int n = 1; n < 100; n++)  // running loop 100 times
  {
    Graph G = newGraph(n); // Creating the graph
    for (int i = 0; i < 100; i++) // running loop 100 times
    {
      int u = (rand() % getOrder(G)) + 1; // random number is taken in range of order of graph for vertex u
      int v = (rand() % getOrder(G)) + 1; // random number is taken in range of order of graph for vertex v
      addEdge(G, u, v); // adding the edge in the graph
    }
    fprintf(stdout, "Graph of order %d:\n", n); // printing the order of the graph
    printGraph(stdout, G); // printing the grpah
    freeGraph(&G); // Freeing the graph
  }
  fprintf(stdout, "============= printGraph Test Passed =============\n");
}

void GraphTest_BFS()
{
  fprintf(stdout, "============= BFS Test =============\n");

  for (int n = 1; n < 100; n++) // running loop 100 times
  {
    Graph G = newGraph(n); // Creating the graph
    for (int i = 0; i < 100; i++) // running loop 100 times
    {
      int u = (rand() % getOrder(G)) + 1; // random number is taken in range of order of graph for vertex u
      int v = (rand() % getOrder(G)) + 1; // random number is taken in range of order of graph for vertex v
      addEdge(G, u, v); // adding edge in the graph
    }
    for (int s = 1; s <= getOrder(G); s++) // looping from 1 till the order of the Graph
    {
      BFS(G, s); // BFS is called on for the value of S
      if (getSource(G) != s) // Source is checked with value of s
      {
        fprintf(stdout, "BFS failed for order %d\n", n); // Error Message
        printGraph(stdout, G); // printing the grpah
        exit(EXIT_FAILURE); // Exiting in failure
      }
      if (getDist(G, s) != 0) // Distacne is checked if it is not equal to 0
      {
        fprintf(stdout, "BFS failed for order %d\n", n); // Error Message
        printGraph(stdout, G); // printing the grpah
        exit(EXIT_FAILURE); // Exiting in failure
      }
      if (getParent(G, s) != NIL) // checking if the parent if not equal to NIL
      {
        fprintf(stdout, "BFS failed for order %d\n", n); // Error Message
        printGraph(stdout, G); // printing the grpah
        exit(EXIT_FAILURE); // Exiting in failure
      }
    }
    freeGraph(&G); // Freeing the graph
  }
  fprintf(stdout, "============= BFS Test Passed =============\n");
}

void GraphTest_getPath()
{
  fprintf(stdout, "============= getPath Test =============\n");

  for (int n = 1; n < 100; n++)  // loop 100 times
  {
    Graph G = newGraph(n); // Creating the graph
    for (int i = 0; i < 100; i++) // running loop 100 times
    {
      int u = (rand() % getOrder(G)) + 1; // random number is taken in range of order of graph for vertex u
      int v = (rand() % getOrder(G)) + 1; // random number is taken in range of order of graph for vertex v
      addEdge(G, u, v); // adding the edge
    }
    for (int s = 1; s <= getOrder(G); s++) // looping from 1 till order of the graph
    {
      BFS(G, s); // BFS is caled for all values of S which is in bounds of Graph
      for (int u = 1; u <= getOrder(G); u++)
      {
        List L = newList(); // Creating new list
        getPath(L, G, u); // getting the path
        freeList(&L); // freeing the List
      }
    }
    freeGraph(&G); // Freeing the graph
  }
  fprintf(stdout, "============= getPath Test Passed =============\n");
}

int main(int argc, char **argv)
{
  GraphTest_constructorDestructor();
  GraphTest_getOrder();
  GraphTest_getSize();
  GraphTest_getSource();
  GraphTest_getParent();
  GraphTest_getDist();
  GraphTest_makeNull();
  GraphTest_addArc();
  GraphTest_addEdge();
  GraphTest_printGraph();
  GraphTest_BFS();
  GraphTest_getPath();
  return EXIT_SUCCESS;
}