/*
 *  Main program.
 *
 *  Authors : Antonio Sedeno Noda, Sergio Alonso.
 *  Years   : 2012-2021
 */

#include <string.h>
#include "grafo.h"

void menu (unsigned dirigido, char &opcion)
// Menu of options, depending on whether the graph is directed or undirected
{
    cout << endl;
    cout << "Graph Optimisation, 2023-2024 CRISTHIAN ADONEY CRUZ DELGADO" << endl;
    cout << "c. Load a graph from a file" << endl;
    cout << "i. Show basic graph [i]nformation" << endl;
    cout << "a. Show the [a]djacency list of the graph" << endl;
    if (dirigido == 1) // Directed graph
    {
        cout << "e. Show the pr[e]decessor list of the graph" << endl;
        cout << "s. Show the [s]uccessor list of the graph" << endl;
        cout << "y. Show the adjacenc[y] matrix of the graph" << endl;
        cout << "r. Perform a depth-first t[r]aversal of the graph from a node by successors" << endl;
        cout << "m. Perfor[m] a breadth-first traversal of the graph from a node by successors" << endl;
        // cout << "d. Shortest paths: [d]ijkstra" << endl;
        // cout << "v. Shortest paths: compare Dijkstra [v]s BellmanFordEnd" << endl;
        cout << "n. Shortest paths: BellmanFordEnd, Pape and D'sopo modificatio[n]" << endl;
        // cout << "f. Shortest paths: [f]loyd-Warshall" << endl;
    }
    else // Undirected graph
    {
        cout << "y. Show the adjacenc[y] matrix of the graph" << endl;
        cout << "r  Perform a depth-first t[r]aversal of the graph from a node" << endl;
        cout << "m. Perfor[m] a breadth-first traversal of the graph from a node by successors" << endl;
        // cout << "o. Show the c[o]nnected components of the graph" << endl;
        cout << "k. Show the minimum-cost spanning tree, [k]ruskal" << endl;
        // cout << "p. Show the minimum-cost spanning tree, [P]rim" << endl;
    }
    cout << "q. Quit the program" << endl;
    cout << "Enter the letter of the action to run  >  ";
    cin >> opcion;
    cout << endl;
}

// The main function is simply a menu manager, with different actions for directed and undirected graphs, and an initial menu if no graph is loaded
int main(int argc, char *argv[])
{
    int error_apertura;
    char nombrefichero[85], opcion;
// clrscr();
    // Try to load the first file from the arguments
    if (argc > 1)
    {
        cout << "Loading data from the file given as an argument" << endl;
        strcpy(nombrefichero, argv[1]);
    }
    // Otherwise, ask for the file on the keyboard
    else
    {
        cout << "Enter the full name of the data file" << endl;
        cin >> nombrefichero;
    }
    // Constructor of the object G of the graph class
    GRAFO G(nombrefichero, error_apertura);
    if (error_apertura == 1)
    {
        cout << "Error opening the file given as an argument: check its name and format" << endl;
// pressanykey();
// clrscr();
    }
    else
    {
        cout << "Graph loaded from the file " << nombrefichero << endl;
// pressanykey();
// clrscr();
        do
        {
            menu(G.Es_dirigido(), opcion);
            switch (opcion)
            {
// Both
                case 'c' : // load a graph from a file
// clrscr();
                    cout << "Enter the full name of the data file" << endl;
                    cin >> nombrefichero;
                    G.actualizar(nombrefichero, error_apertura);
                    if (error_apertura == 1)
                    {
                        cout << "Error opening the file: check its name and format : you can try again" << endl;
                    }
                    else
                    {
                        cout << "File loaded correctly from " << nombrefichero << endl;
                    }
// pressanykey();
// clrscr();
                    break;
// Both
                case 'i' : // Show basic graph [i]nformation
// clrscr();
                    cout << "Graph loaded from " << nombrefichero << endl;
                    G.Info_Grafo();
// pressanykey();
//clrscr();
                    break;
// Phase I. PR3
// Directed
                case 'e' : // Show the pr[e]decessor list of the graph
// clrscr();
                    G.Mostrar_Listas(-1);
// pressanykey();
// clrscr();
                    break;
// Directed
                case 's' : // Show the [s]uccessor list of the graph
// clrscr();
                    G.Mostrar_Listas(1);
// pressanykey();
// clrscr();
                    break;
// Undirected
                case 'a' : // // Show the [a]djacency list of the graph
// clrscr();
                    G.Mostrar_Listas(0);
// pressanykey();
// clrscr();
                    break;
// Both
                case 'y' : // Show the adjacenc[y] matrix of the graph
// clrscr();
                    G.Mostrar_Matriz();
// pressanykey();
// clrscr();
                    break;
// Phase II. PR3
// Both
                case 'r' : // Perform a depth-first t[r]aversal of the graph from a node by successors
// clrscr();
                    G.RecorridoProfundidad();
// pressanykey();
// clrscr();
                    break;
// Both
                case 'm' : // Perfor[m] a breadth-first traversal of the graph from a node by successors
// clrscr();
                    G.RecorridoAmplitud();
// pressanykey();
// clrscr();
                    break;

// ...
// Directed
                case 'd' :
// clrscr();
// pressanykey();
// clrscr();
                    break;
// Directed
                case 'v' :
// clrscr();
// pressanykey();
// clrscr();
                    break;
// Directed
                case 'n' : // Shortest paths: BellmanFordEnd. Pape and D'sopo modificatio[n]
// clrscr();
                    G.PDM();
// pressanykey();
// clrscr();
                    break;
// Directed
                case 'f' :
// clrscr();
// pressanykey();
// clrscr();
                    break;
// Undirected
                case 'o' :
// clrscr();
// pressanykey();
// clrscr();
                    break;
// PR4
// Undirected
                case 'k' : // Show the minimum-cost spanning tree, [k]ruskal
// clrscr();
                    G.Kruskal();
// pressanykey();
// clrscr();
                    break;
// ...
// Undirected
                case 'p' :
// clrscr();
// pressanykey();
// clrscr();
                    break;
// Both
                default:
// clrscr();
                    cout << "This option does nothing in the program" << endl;
// pressanykey();
// clrscr();
                    break;
            }
        }
        while (opcion != 'q');
    }
    cout << "End of program" << endl;
    return(0);
}
