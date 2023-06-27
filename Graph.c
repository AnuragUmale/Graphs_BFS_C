/*
=============================================
Name: Anurag Prashant Umale                 =   
Student Id: 1887255                         =
E-mail: aumale@ucsc.edu                     =
File: Graph.c (Implementation of Graph ADT) =
Class: CSE 101 Spring 2023                  =
=============================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Graph.h"

typedef struct GraphObj // structure for the graph
{
    List *neighbour; // List for the neighnbour nodes
    int *color; // array for the color
    int *parent; // array for the parent
    int *distance; // array for the distane
    int order; // number of nodes in the graph
    int size; // size of the graph
    int BFS; // variable for the BFS (soruce) value
} GraphObj; // GraphObj is type casted

// ===================== Constructor & Destructor =====================

Graph newGraph(int n)
{
    Graph new_graph = (Graph)malloc(sizeof(GraphObj)); // dynamically allocating memory
    if(new_graph){ // chceking if pointer is not equal to null
        new_graph->order = n; // setting the order of graph to n
        new_graph->size = 0; // setting the size of the graph to 0
        new_graph->BFS = NIL; // setting the source or BFS value to NIL (0)
        new_graph->neighbour = (List *)calloc(n + 1, sizeof(List)); // dynamically allocating memory
        if(!new_graph->neighbour){ // Checking if pointer is null
            fprintf(stderr,"1.Graph Error.\n2.Error: newGraph(int n).\n3.Error in memory allocation.\n"); // Error Message
            exit(EXIT_FAILURE); // exiting in failure
        }
        new_graph->color = (int *)calloc(n + 1, sizeof(int)); // dynamically allocating memory
        if(!new_graph->color){ // Checking if pointer is null
            fprintf(stderr,"1.Graph Error.\n2.Error: newGraph(int n).\n3.Error in memory allocation.\n"); // Error Message
            exit(EXIT_FAILURE); // exiting in failure
        }
        new_graph->parent = (int *)calloc(n + 1, sizeof(int)); // dynamically allocating memory
        if(!new_graph->parent){ // Checking if pointer is null
            fprintf(stderr,"1.Graph Error.\n2.Error: newGraph(int n).\n3.Error in memory allocation.\n"); // Error Message
            exit(EXIT_FAILURE); // exiting in failure
        }
        new_graph->distance = (int *)calloc(n + 1, sizeof(int)); // dynamically allocating memory
        if(!new_graph->distance){ // Checking if pointer is null
            fprintf(stderr,"1.Graph Error.\n2.Error: newGraph(int n).\n3.Error in memory allocation.\n"); // Error Message
            exit(EXIT_FAILURE); // exiting in failure
        }
        for (int i = 0; i <= n; i++) // loop starting from
        {
            new_graph->neighbour[i] = newList(); // creating new list for each index
            new_graph->color[i] = WHITE; // assigning 0 (WHITE) to all color
            new_graph->parent[i] = NIL; // assigning 0 (NIL) to all parent value
            new_graph->distance[i] = INF; // assigning -1 (INF) to all distance value
        }
        return new_graph; // returning the graph
    }
    else{
        fprintf(stderr,"1.Graph Error.\n2.Error: newGraph(int n).\n3.Error in memory allocation.\n"); // Error message
        exit(EXIT_FAILURE); // exiting in failure
    }
}

void freeGraph(Graph *pG)
{
    if (pG != NULL && *pG != NULL) // Checking if pointer and pointer to pointer is not equal to NULL
    {
        for (int i = 0; i <= (*pG)->order; i++) // starting the loop from 0 to order 
        {
            freeList(&(*pG)->neighbour[i]); // freeing the list at each index
        }
        free((*pG)->parent); // freeing the parent pointer
        free((*pG)->color); // freeing the color pointer
        free((*pG)->distance); // freeing the distance pointer
        free((*pG)->neighbour); // freeing the neighbour pointer
        (*pG)->parent = NULL; // setting the parent pointer to NULL
        (*pG)->color = NULL; // setting the color pointer to NULL
        (*pG)->distance = NULL; // setting the distance pointer to NULL
        (*pG)->neighbour = NULL; // setting the neighbour pointer to NULL
        free(*pG); // freeing the Graph pointer to pointer
        (*pG) = NULL; // Setting the pointer to pointer to NULL
    }
}

// ===================== Access Function =====================

int getOrder(Graph G)
{
    if(G){ // Checking if the pointer is not equal to NULL
        return G->order; // returning the order of the graph
    }
    else{
        fprintf(stderr,"1.Graph Error.\n2.Error: getOrder(Graph G).\n3.Calling function on NULL pointer.\n"); // Error message
        exit(EXIT_FAILURE); // exiting in failure
    }
    
}

int getSize(Graph G)
{
    if(G){ // Checking if the pointer is not equal to NULL
        return G->size; // returning the size of the graph
    }
    else{
        fprintf(stderr,"1.Graph Error.\n2.Error: getSize(Graph G).\n3.Calling function on NULL pointer.\n"); // Error message
        exit(EXIT_FAILURE); // exiting in failure
    }
}
int getSource(Graph G)
{
    if(G){ // Checking if the pointer is not equal to NULL
        return G->BFS; // returning the source value of the Graph
    }
    else{
        fprintf(stderr,"1.Graph Error.\n2.Error: getSource(Graph G).\n3.Calling function on NULL pointer.\n"); // Error message
        exit(EXIT_FAILURE); // exiting in failure
    }
}

int getParent(Graph G, int u)
{
    if(G){ // Checking if the pointer is not equal to NULL
        if (u < 1 || u > getOrder(G)) // Checking if u is in bounds
        {
            fprintf(stderr,"1.Graph Error.\n2.Error: int getParent(Graph G, int u).\n3.The value is out of bounds.\n"); // Error message
            exit(EXIT_FAILURE); // exiting in failure
        }
        if (G->BFS == NIL) // Checking if BFS is called or not
        {
            return NIL; // returning NIL (0) value
        }
        return G->parent[u]; // returning the parent value at u index
    }
    else{
        fprintf(stderr,"1.Graph Error.\n2.Error: int getParent(Graph G, int u).\n3.Calling function on NULL pointer.\n"); // Error message
        exit(EXIT_FAILURE); // exiting in failure
    }
}

int getDist(Graph G, int u)
{
    if(G){ // Checking if the pointer is not equal to NULL
        if (u < 1 || u > getOrder(G)) // Checking if u is in bounds
        {
            fprintf(stderr,"1.Graph Error.\n2.Error: int getDist(Graph G, int u).\n3.The value is out of bounds.\n"); // Error message
            exit(EXIT_FAILURE); // exiting in failure
        }
        if (G->BFS == NIL) // Checking if BFS fucntion is called or not
        {
            return INF; // returning the INF(-1) value
        }
        return G->distance[u]; // returning the distance at u index
    }
    else{
        fprintf(stderr,"1.Graph Error.\n2.Error: int getDist(Graph G, int u).\n3.Calling function on NULL pointer.\n"); // Error message
        exit(EXIT_FAILURE); // exiting in failure
    }
}

void getPath(List L, Graph G, int u)
{
    if(L == NULL){ // Checking if List is NULL 
        fprintf(stderr,"1.List Error.\n2.Error: void getPath(List L, Graph G, int u).\n3.Calling function on NULL pointer.\n"); // Error message
        exit(EXIT_FAILURE); // exiting in failure
    }
    if(G){ // Checking if the pointer is not equal to NULL
        if (u < 1 || u > getOrder(G)) // Checking if u is in bounds
        {
            fprintf(stderr,"1.Graph Error.\n2.Error: void getPath(List L, Graph G, int u).\n3.The value is out of bounds.\n"); // Error message
            exit(EXIT_FAILURE); // exiting in failure
        }
        if (G->BFS == NIL) // Cheking if BFS is called or not
        {
            fprintf(stderr,"1.Graph Error.\n2.Error: void getPath(List L, Graph G, int u).\n3.getPath() can be called only if BFS is called at least once.\n"); // Error message
            exit(EXIT_FAILURE); // exiting in failure
        }
        if(u == getSource(G)){ // checking if u is equal to the source value
            append(L, u); // appending the u value to the List
        }else if(getParent(G,u) == NIL){ // checking if parent is NULL
            append(L, NIL); // appendind NIL(0) to the List
        }else{ // else
            getPath(L, G, getParent(G,u)); // recursive call of the function the List L, Graph G and the parent value of that graph is passed
            append(L, u);// append the u value to the List
        }
    }
    else{ // else
        fprintf(stderr,"1.Graph Error.\n2.Error: void getPath(List L, Graph G, int u).\n3.Calling function on NULL pointer.\n"); // Error message
        exit(EXIT_FAILURE); // exiting in failure
    }
}

// ===================== Malipulation Function =====================

void makeNull(Graph G)
{
    if (G) // Checking if the pointer is not equal to NULL
    {
        for (int i = 0; i <= getOrder(G) ; i++) // starting for a loop form 0 till order of Graph
        {
            clear(G->neighbour[i]); // clearing the neighbour values
            G->color[i] = WHITE; // colour values are changed to WHITE
            G->parent[i] = NIL; // parent values are changed to NIL
            G->distance[i] = INF; // distance is changed to INF
        }
        G->size = 0; // setting the size to 0
        G->BFS = NIL; // setting the BFS(source) value NIL
    }
    else
    {
        fprintf(stderr,"1.Graph Error.\n2.Error: void makeNull(Graph G).\n3.Calling function on NULL pointer.\n"); // Error message
        exit(EXIT_FAILURE); // exiting in failure
    }
}

void addEdge(Graph G, int u, int v)
{
    if (G){ // Checking if the pointer is not equal to NULL
        if (u < 1 || v < 1) // Checking if u is in boundss
        {
            fprintf(stderr,"1.Graph Error.\n2.Error: void getPath(List L, Graph G, int u).\n3.The value is out of bounds.\n"); // Error message
            exit(EXIT_FAILURE); // exiting in failure
        }

        if (u > getOrder(G) || v > getOrder(G)) // Checking if v is in bounds
        {
            fprintf(stderr,"1.Graph Error.\n2.Error: void getPath(List L, Graph G, int u).\n3.The value is out of bounds.\n"); // Error message
            exit(EXIT_FAILURE); // exiting in failure
        }

        if (length(G->neighbour[v]) == 0) // Checking if length of neignbour list is equal to 0
        {
            append(G->neighbour[v], u); // appending u to the 
            G->size++; // increment the size of the graph
        }
        else // else
        {
            moveFront(G->neighbour[v]); // moving front the index element

            for (int i = 1; i <= length(G->neighbour[v]); i++) // starting a loop from 1 till the length of the list
            {
                if (get(G->neighbour[v]) > u) // checking if the value at that index is greater than u
                {
                    insertBefore(G->neighbour[v], u); // inseting u value before the index value in the list
                    G->size++; // incrementing the size

                    break; // breaking through the loop
                }
                else // else
                {
                    moveNext(G->neighbour[v]); // moving next the element at the index v
                    if (index(G->neighbour[v]) == -1) // checking the index of the list is -1
                    {
                        append(G->neighbour[v], u); // appending u at the index v

                        G->size++; // increment the size

                        break; // breaking through the loop
                    }
                }
            }
        }

        if (length(G->neighbour[u]) == 0) // Checking if length of neignbour list is equal to 0
        {
            append(G->neighbour[u], v); // appending the v value at the index of u
        }
        else // else
        {
            moveFront(G->neighbour[u]); // moving front the element at the index u of the list
            for (int i = 1; i <= length(G->neighbour[u]); i++) // starting a loop from 1 till the length of the list
            {
                if (get(G->neighbour[u]) > v) // checking if the value at that index is greater than v
                {
                    insertBefore(G->neighbour[u], v); // inseting u value before the index value in the list

                    break; // breaking through the loop
                }
                else // else
                {
                    moveNext(G->neighbour[u]); // moving next the element at the index u
                    if (index(G->neighbour[u]) == -1)
                    {
                        append(G->neighbour[u], v); // appending v at the index u

                        break; // breaking through the loop
                    }
                }
            }
        }
    }
    else{ // else
        fprintf(stderr,"1.Graph Error.\n2.Error: void addEdge(Graph G, int u, int v).\n3.Calling function on NULL pointer.\n"); // Error message
        exit(EXIT_FAILURE); // exiting in failure
    }
}
void addArc(Graph G, int u, int v)
{
    if (G){ // Checking if the pointer is not equal to NULL
        if (u < 1 || v < 1) // Checking if u and v are in bounds
        {
            fprintf(stderr,"1.Graph Error.\n2.Error: void getPath(List L, Graph G, int u).\n3.The value is out of bounds.\n"); // Error message
            exit(EXIT_FAILURE); // exiting in failure
        }

        if (u > getOrder(G) || v > getOrder(G))  // Checking if u and v are in bounds
        {
            fprintf(stderr,"1.Graph Error.\n2.Error: void getPath(List L, Graph G, int u).\n3.The value is out of bounds.\n"); // Error message
            exit(EXIT_FAILURE); // exiting in failure
        }

        if (length(G->neighbour[u]) == 0) // Checking if length of neignbour list is equal to 0
        {
            append(G->neighbour[u], v); // appending v at the index u

            G->size++; // increment the size
        }
        else // else
        {
            moveFront(G->neighbour[u]); // moving front the index element
            for (int i = 1; i <= length(G->neighbour[u]); i++) // starting a loop from 1 till the length of the list
            {
                if (get(G->neighbour[u]) > v) // checking if the value at that index is greater than v
                {
                    insertBefore(G->neighbour[u], v); // inseting u value before the index value in the list

                    G->size++; // increment the size

                    break; // breaking through the loop
                }
                else // else
                {
                    moveNext(G->neighbour[u]); // moving next the element at the index u
                    if (index(G->neighbour[u]) == -1)
                    {
                        append(G->neighbour[u], v); // appending v at the index u

                        G->size++; // increment the size

                        break; // breaking through the loop
                    }
                }
            }
        }
    }
    else{ // else
        fprintf(stderr,"1.Graph Error.\n2.void addArc(Graph G, int u, int v).\n3.Calling Function on NULL pointer."); // Error message
        exit(EXIT_FAILURE); // exiting in failure
    }
}

void BFS(Graph G, int s)
{
    if(G){ // Checking if the pointer is not equal to NULL
        if (s < 1) // checking if s is in bounds
        {
            fprintf(stderr,"1.Graph Error.\n2.void BFS(Graph G, int s).\n3.Input is less than 1\n"); // Error message
            exit(EXIT_FAILURE); // exiting in failure
        }

        if (s > getOrder(G)) // checking if s is in bounds
        {
            fprintf(stderr,"1.Graph Error.\n2.void BFS(Graph G, int s).\n3.Input is greater than order of graph.\n"); // Error message
            exit(EXIT_FAILURE); // exiting in failure
        }
        G->BFS = s; // setting the sourse(BFS) value to s
        for (int x = 1; x < s; x++) // for loop from 1 to value of s
        {
            G->color[x] = WHITE; // setting the value at that index to WHITE
            G->distance[x] = INF; // setting the value at the index to INF
            G->parent[x] = NIL; // setting the value at the index to NIL
        }
        for (int x = s + 1; x <= getOrder(G); x++) // for loop from s + 1 till the order of the graph
        {
            G->color[x] = WHITE; // setting the value at that index to WHITE
            G->distance[x] = INF; // setting the value at the index to INF
            G->parent[x] = NIL; // setting the value at the index to NIL
        }

        G->color[s] = GRAY; // setting the value at s index to GRAY
        G->distance[s] = 0; // setting the distance at s index to 0
        G->parent[s] = NIL; // setting the parent at s index to NIL
        List Q = newList(); // creating a new list
        int x = 0; // creating a temp variable x
        append(Q, s); // appending the s value to the list
        while (length(Q) != 0) // checking if the length of the list is not equal to NULL
        {
            moveFront(Q); // moving front the element in the list
            x = get(Q); // getting the element of at the index from the list

            deleteFront(Q); // deleting the front element
            int y = 0; // creating a temp varianle y
            if (length(G->neighbour[x]) != 0) // checking the length of the neighour list is not equal to 0
            {
                moveFront(G->neighbour[x]); // moving front the element at the index x
            }
            while (index(G->neighbour[x]) != -1) // loop runnning while the index of the list is not equal to -1
            {
                y = get(G->neighbour[x]); // getting the value of the neighbour
                if (G->color[y] == 0) // checking the color at index y is euqal to 0
                {
                    G->color[y] = GRAY; // chaing the color to GRAY
                    G->distance[y] = G->distance[x] + 1; // incrementing the distance
                    G->parent[y] = x; // parent is set to value of x
                    append(Q, y); // appending y to the list
                }

                moveNext(G->neighbour[x]); // moving next in the list
            }

            G->color[x] = BLACK; // color at index x is set to BLACK
        }
        clear(Q); // clearing the list
        freeList(&Q); // freeing the list
        Q = NULL; // Making the pointer NULL
    }
    else{
        fprintf(stderr,"1.Graph Error.\n2.void addArc(Graph G, int u, int v).\n3.Calling Function on NULL pointer."); // Error message
        exit(EXIT_FAILURE); // exiting in failure
    }
}

// ===================== Other Function =====================

void printGraph(FILE *out, Graph G)
{
    if(G){ // Checking if the pointer is not equal to NULL
        for (int i = 1; i <= getOrder(G); i++) // starting the loop from 1 to the order of the graph
        {
            fprintf(out, "%d:", i); // printing the i valur in out
            if (length(G->neighbour[i]) != 0) // checking if the length is not equal to 0
            {
                fprintf(out, " ");// printing the space
                moveFront(G->neighbour[i]); // moving front in the list
                while (index(G->neighbour[i]) != -1) // running the loop while the index is not equal to -1
                {
                    fprintf(out, "%d", get(G->neighbour[i])); // print the list elemnt
                    moveNext(G->neighbour[i]); // move next in the list
                    if (index(G->neighbour[i]) != -1) // checking if the index is not equal to -1
                    {
                        fprintf(out, " "); // printing the space in out
                    }
                    else // else
                    {
                        if (i != getOrder(G)){ // checking if i is not equal to order of Graph
                            fprintf(out, "\n"); // printing the newline
                        }
                    }
                }
            }
            else // else
            {
                fprintf(out, "\n"); // printing newline
            }
        }
        fprintf(out, "\n"); // printing new line
    }
    else{ // priting newline
        fprintf(stderr,"1.Graph Error.\n2.void printGraph(FILE *out, Graph G).\n3.Calling Function on NULL pointer."); // Error message
        exit(EXIT_FAILURE); // exiting in failure
    }
}