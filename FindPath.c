/*
=====================================================
Name: Anurag Prashant Umale                         =   
Student Id: 1887255                                 =
E-mail: aumale@ucsc.edu                             =
File: FindPath.c (Find the shortest path using BFS) =
Class: CSE 101 Spring 2023                          =
=====================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Graph.h"

int main(int argc, char *argv[])
{

    FILE *in = stdin; // File pointer set to stdin 
    FILE *out = stdout; // File pointer set to stdout

    if (argc != 3) // checking if the arguments are not equal to 3
    {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]); // Error Message (Usage)
        exit(EXIT_FAILURE); // Exiting in failure
    }

    in = fopen(argv[1], "r"); // opening the in file for reading
    if (in == NULL) // checking if in file is equal to NULL
    {
        fprintf(stderr, "Unable to open file %s for reading\n", argv[1]); // Error Message
        exit(EXIT_FAILURE); // Exiting in failure
    }

    out = fopen(argv[2], "w"); // opening the outfile for writing
    if (out == NULL) // checking if the out file is equal to NULL
    {
        fprintf(stderr, "Unable to open file %s for writing\n", argv[2]); // Error message
        exit(EXIT_FAILURE); // Exiting in failure
    }

    int n; // Decalring n for geting the order of the graph
    fscanf(in, "%d", &n); // scanning the values for order of the graph from the infile and store in n
    Graph G = newGraph(n); // creating new graph of that order

    int vertexU, vertexV; // getting vertex v and vertex u
    fscanf(in, "%d %d\n", &vertexU, &vertexV); // scanning the values of u and v vertices 
    while (vertexU != 0 || vertexV != 0) // checking if the vertices are not equal to 0
    {
        addEdge(G, vertexU, vertexV); // adding the edge in the graph
        fscanf(in, "%d %d\n", &vertexU, &vertexV); // scanning the values of u and v vertices 
    }

    printGraph(out, G); // printing the graph

    int source, destination; // declaring the source (BFS) value and destination variable
    fscanf(in, "%d %d\n", &source, &destination); // scanning the in file for source and destination

    while (source != 0 || destination != 0) // checking if source and destination is not equal to 0
    {

        if (source == destination) // checking if soruce equal to destination
        {
            fprintf(out, "\nThe distance from %d to %d is 0\n", source, destination); // printing the distace in the out
            fprintf(out, "A shortest %d-%d path is: %d\n", source, destination, source); // printing the shortest parth
            fscanf(in, "%d %d\n", &source, &destination); // scan the source and destination from in file
            continue; // continue from the loop
        }

        BFS(G, source); // calling the BFS on the source

        int dist = getDist(G, destination); // temp dist valriable and get the from source to destination 
        if (dist == INF) // checking if the Distance is INF
        {
            fprintf(out, "\nThe distance from %d to %d is infinity\n", source, destination); // distacne from source and destination is printed as infinty
        }
        else // else
        {
            fprintf(out, "\nThe distance from %d to %d is %d\n", source, destination, dist); // print out the distance from source and destination
        }

        List path = newList(); // creating the list for the path
        getPath(path, G, destination); // getting the paths in the list
        if (front(path) == NIL) // getting the front value and checks if it is equal to NIL
        {
            fprintf(out, "No %d-%d path exists\n", source, destination); // printing no path exist from source and destination
        }
        else // else
        {
            fprintf(out, "A shortest %d-%d path is: ", source, destination); // printing the shortest path from the source and destination
            printList(out, path); // parint the list of the path at that index
        }
        freeList(&path); // free the list
        fscanf(in, "%d %d\n", &source, &destination); // scan for the source and destination
    }

    fclose(in); // closing the infile
    fclose(out); // closing the outfile

    freeGraph(&G); // freeing the graph
    return EXIT_SUCCESS; // retuning success
}