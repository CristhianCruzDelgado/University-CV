/*
 *  GRAFO.h - template for students with the definition of the GRAFO class
 *
 *  Authors : Antonio Sedeno Noda, Sergio Alonso
 *  Years   : 2012-2021
 */

#ifndef _GRAFO_H
#define _GRAFO_H

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

const unsigned UERROR = 65000; // Some algorithms need this error value encoded
const int maxint = 1000000; // Some algorithms need this maximum value encoded

// Definition of an element of the adjacency list

typedef struct
{
    unsigned j; // Node (predecessor, successor / adjacent)
    int      c; // Cost
} ElementoLista;

// Definition of an element of the spanning tree

typedef struct
{
    unsigned extremo1, extremo2;
    int peso;
} AristaPesada;

// Definition of the type of the adjacency list of a node

typedef vector<ElementoLista> LA_nodo;

// Definition of the type of a list of edges

typedef vector<AristaPesada> Aristas;

// Definition of the Grafo class

class GRAFO
{
    unsigned            n;         // Number of NODES
    unsigned            m;         // Number of ARCS or EDGES
    unsigned            dirigido;  // 0 if the graph is undirected and 1 if it is directed
    vector<LA_nodo>     LS;        // Successor adjacency list (node, successor, cost)                    | directed    |
    vector<LA_nodo>     LP;        // Predecessor adjacency list (node, predecessor, cost)                | directed    |
    vector<LA_nodo>     LA;        // Adjacency list (node, adjacent, cost)                               | undirected  |
    void destroy();                // Destroys LS, LP and LA, where applicable
    void build (char nombrefichero[85], int &errorapertura); // Builds LS, LP and LA, where applicable, by reading the file
    void dfs_num(unsigned i, vector<LA_nodo> L, vector<bool> &visitado, vector<unsigned> &prenum, unsigned &prenum_ind, vector<unsigned> &postnum, unsigned &postnum_ind); // Recursive depth-first traversal with prenum and postnum orders
    void bfs_num(unsigned i, vector<LA_nodo> L, vector<unsigned> &pred, vector<int> &d); // Breadth-first traversal computing predecessor and distance
    // Additions
    unsigned MaximoVector(vector<int>& v);
    void MostrarCamino(unsigned s, unsigned i, vector<unsigned> pred);
public:
    GRAFO(char nombrefichero[], int &errorapertura); // constructor of the graph object
    void actualizar(char nombrefichero[], int &errorapertura); // Updates the file in use
    unsigned Es_dirigido(); // Returns 0 if the graph is undirected and 1 if it is directed
    void Info_Grafo(); // Returns basic information about the graph
    void Mostrar_Listas(int l); // Shows the adjacency list
    void Mostrar_Matriz(); // Shows the adjacency matrix: nodes and costs
    void RecorridoProfundidad(); // Builds a depth-first traversal from a start node
    void RecorridoAmplitud(); // Builds a breadth-first traversal from a start node
    void Kruskal(); // Builds a minimum-cost spanning tree
    void PDM();
    ~GRAFO(); // Destructor of the graph object
};

#endif
