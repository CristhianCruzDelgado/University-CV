 /*
 *  GRAFO.CPP - Template for the implementation of the GRAFOS class
 *
 *
 *  Authors : Antonio Sedeno Noda, Sergio Alonso
 *  Years    : 2012-2021
 */

#include "grafo.h"

void GRAFO::destroy()
{
    for (unsigned i = 0; i < n; i++)
    {
        LA[i].clear();
        if (dirigido == 1)
        {
            LS[i].clear();
            LP[i].clear();
        }
    }
    LA.clear();
    LS.clear();
    LP.clear();
}

void GRAFO::build(char nombrefichero[85], int &errorapertura)
{
    ElementoLista     dummy;
    ifstream textfile;
    textfile.open(nombrefichero);
    if (textfile.is_open())
    {
        unsigned i, j, k; // Number of nodes, arcs and whether it is directed
        textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
        // Internally, nodes are numbered from 0 to n-1
        // Create the n successor lists
        LA.resize(n);
        if (dirigido == 1)
        {
            LS.resize(n);
            LP.resize(n);
        }
        // Read the m arcs
        for (k = 0; k < m; k++)
        {
            textfile >> (unsigned &) i  >> (unsigned &) j >> (int &) dummy.c;
            // Assign the values of dummy.j and dummy.c
            // Place dummy at the position of node i with push_back
            // To do: a second push_back if undirected. Or not.
            // To do: build LP, if directed
            // To do: the value to return in errorapertura
            //...
            dummy.j = j - 1;
            LA[i - 1].push_back(dummy);
            if (dirigido == 1)
            {
                LS[i - 1].push_back(dummy);
            }
            dummy.j = i - 1;
            if (i != j)
            {
                LA[j - 1].push_back(dummy);
            }
            if (dirigido == 1)
            {
                LP[j - 1].push_back(dummy);
            }
        }
    }
    textfile.close();
}

GRAFO::~GRAFO()
{
    destroy();
}

GRAFO::GRAFO(char nombrefichero[85], int &errorapertura)
{
    build (nombrefichero, errorapertura);
}

void GRAFO::actualizar(char nombrefichero[85], int &errorapertura)
{
    // Free the dynamic memory taken by the previous load, as the destructor does
    destroy();
    // Read the file and update G with new LS, LA and, if applicable, LP
    build(nombrefichero, errorapertura);
}

unsigned GRAFO::Es_dirigido()
{
    return dirigido;
}

void GRAFO::Info_Grafo()
{
    cout << "Graph information" << endl;
    cout << "Number of nodes: " << n << endl;
    cout << "Number of arcs: " << m << endl;
    cout << "1 means directed. 0 means undirected." << endl
         << "Value: " << dirigido << endl;
}

void Mostrar_Lista(const vector<LA_nodo>& L, unsigned& n)
{
    cout << "Node:" << endl;
    for (unsigned fila = 0; fila < n; fila++)
    {
        cout << "[ " << fila << " ]";
        if (L[fila].size() == 0)
        {
            cout << "  no adjacency";
        }
        for (unsigned columna = 0; columna < L[fila].size(); columna++)
        {
            cout << "  (" << L[fila][columna].j + 1 << " , " << L[fila][columna].c << ")";
        }
        cout << endl;
    }
}

void GRAFO::Mostrar_Listas(int l)
{
    switch (l)
    {
    case -1:
        Mostrar_Lista(LP, n);
        break;
    case 0:
        Mostrar_Lista(LA, n);
        break;
    case 1:
        Mostrar_Lista(LS, n);
        break;
    default:
        break;
    }
}

void GRAFO::Mostrar_Matriz() // Shows the adjacency matrix, with both the adjacent nodes and their costs
{
    for (unsigned fila = 0; fila < n; fila++)
    {
        for (unsigned columna = 0; columna < LA[fila].size(); columna++)
        {
            cout << "(" << 1 << "," << LA[fila][columna].c << ")" << " ";
        }
        cout << endl;
    }
}

unsigned GRAFO::MaximoVector(vector<int>& v)
{
    int max = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] > max && v[i] < maxint)
        {
            max = v[i];
        }
    }
    return max;
}

void GRAFO::MostrarCamino(unsigned s, unsigned i, vector<unsigned> pred)
{
    if (i != s)
    {
        MostrarCamino(s, pred[i], pred);
        cout << " - " << i + 1;
    }
    else
    {
        cout << i + 1;
    }
}

void GRAFO::dfs_num(unsigned i, vector<LA_nodo> L, vector<bool> &visitado, vector<unsigned> &prenum, unsigned &prenum_ind, vector<unsigned> &postnum, unsigned &postnum_ind) // Recursive depth-first traversal with prenum and postnum orders
{
    visitado[i] = true;
    // Assign the prenum visit order of node i
    prenum[prenum_ind++] = i + 1;
    for (unsigned j = 0; j < L[i].size(); j++)
    {
        if (!visitado[L[i][j].j])
        {
            dfs_num(L[i][j].j, L, visitado, prenum, prenum_ind, postnum, postnum_ind);
        }
    }
    // Assign the postnum visit order of node i
    postnum[postnum_ind++] = i + 1;
}

void GRAFO::RecorridoProfundidad() // Builds a depth-first traversal from a start node
{
    // Create and initialise variables and vectors
    bool primero; // print
    unsigned i = 0;
    unsigned prenum_ind = 0;
    unsigned postnum_ind = 0;
    vector<bool> visitado(n, false);
    vector<unsigned> prenum(n, UERROR);
    vector<unsigned> postnum(n, UERROR);
    // Ask the user for the start node of the depth-first traversal
    cout << "Building a depth-first traversal" << endl;
    while (i < 1 || n < i)
    {
        cout << "Choose the start node [1 - " << n << "] : ";
        cin >> i;
        cout << endl;
    }
    dfs_num(i - 1, LA, visitado, prenum, prenum_ind, postnum, postnum_ind);
    // Print the preorder
    cout << "Visit order of the nodes in preorder" << endl;
    primero = true;
    for (unsigned j = 0; j < prenum.size(); j++)
    {
        if (prenum[j] != 0 && prenum[j] != UERROR)
        {
            if (primero == true)
            {
                cout << "[" << prenum[j] << "]";
                primero = false;
            }
            else
            {
                cout << " -> [" << prenum[j] << "]";
            }
        }
    }
    cout << endl;
    // Print the postorder
    cout << "Visit order of the nodes in postorder" << endl;
    primero = true;
    for (unsigned j = 0; j < postnum.size(); j++)
    {
        if (postnum[j] != 0 && postnum[j] != UERROR)
        {
            if (primero == true)
            {
                cout << "[" << postnum[j] << "]";
                primero = false;
            }
            else
            {
            cout << " -> [" << postnum[j] << "]";
            }
        }
    }
    cout << endl;
}

void GRAFO::bfs_num(unsigned i, vector<LA_nodo>  L, vector<unsigned> &pred, vector<int> &d) // Breadth-first traversal computing predecessor and distance
{
    vector<bool> visitado; // Create and initialise the visited vector
    visitado.resize(n, false);
    visitado[i] = true;

    pred.resize(n, UERROR); // Create and initialise pred and d
    d.resize(n, maxint);
    pred[i] = i;
    d[i] = 0;

    queue<unsigned> cola; // Create and initialise the queue
    cola.push(i); // Start the traversal from node i+1

    while (!cola.empty()) // Runs at least once when visiting node i+1 and continues until the queue is empty
    {
        unsigned k = cola.front(); // Take node k+1 from the queue
        cola.pop(); // Remove it from the queue
        // Traverse L from node k+1
        for (unsigned j = 0; j < L[k].size(); j++)
        {
            // Go through every node u adjacent to node k+1
            // If node u has not been visited
            if (!visitado[L[k][j].j])
            {
                // Visit it
                visitado[L[k][j].j] = true;
                // Push it onto the queue
                cola.push(L[k][j].j);
                // Assign its predecessor
                pred[L[k][j].j] = k;
                // Compute its distance label
                d[L[k][j].j] = d[k] + 1;
            }
        }
        // Finished, since the queue is empty
    }
}

void GRAFO::RecorridoAmplitud() // Builds a breadth-first traversal from a start node
{
    // Create and initialise variables and vectors
    unsigned i = 0;
    vector<unsigned> pred;
    vector<int> d;
    // Ask the user for the start node of the breadth-first traversal
    cout << "Building a breadth-first traversal" << endl;
    while (i < 1 || n < i)
    {
        cout << "Choose the start node [1 - " << n << "] : ";
        cin >> i;
        cout << endl;
    }
    bfs_num(i - 1, LA, pred, d);
    // Print the distance label
    cout << "Nodes by distance to the start node, in number of edges" << endl;
    for (int j = 0; j <= MaximoVector(d); j++)
    {
        cout << "Distance " << j << " edges";
        for (int k = 0; k < d.size(); k++)
        {
            if (j == d[k])
            {
                cout << " : " << k + 1;
            }
        }
        cout << endl;
    }
    cout << endl;
    // Print the predecessors
    cout << "Connecting branches in the traversal" << endl;
    for (unsigned j = 0; j < n; j++)
    {
        if ((j != i - 1) && (pred[j] != UERROR))
        {
            MostrarCamino(i - 1, j, pred);
            cout << endl;
        }
    }
}

void GRAFO::Kruskal() // Builds a minimum-cost spanning tree
{
    vector<AristaPesada> Aristas;

    // Load every edge from the adjacency list
    Aristas.resize(m);
    unsigned k = 0;
    for (unsigned i = 0; i < n; i++)
    {
        for (unsigned j = 0 ; j < LA[i].size(); j++)
        {
            if (i < LA[i][j].j)
            {
                Aristas[k].extremo1 = i;
                Aristas[k].extremo2 = LA[i][j].j;
                Aristas[k++].peso = LA[i][j].c;
            }
        }
    }

    // Initialise variables
    unsigned head = 0;

    int kill = 0;

    unsigned count = 0;

    int pesoMST = 0;

    // Initialise the record of connected components: each node is in its own component
    vector<unsigned> Raiz;
    Raiz.resize(n);
    for (unsigned q = 0; q < n; q++)
    {
        Raiz[q] = q;
    }

    // Main loop of Kruskal's algorithm
    do
    {
        // Sort the edge vector by minimum cost
        if (head < m - 1)
        {
            for (unsigned i = head + 1; i < m; i++)
            {
                if (Aristas[head].peso > Aristas[i].peso)
                {
                    swap(Aristas[i], Aristas[head]);
                }
            }
        }
        // If the endpoints are in different connected components, merge them
        if (Raiz[Aristas[head].extremo1] != Raiz[Aristas[head].extremo2])
        {
            kill = Raiz[Aristas[head].extremo1];
            for (unsigned k = 0; k < n; k++)
            {
                if (Raiz[k] == kill)
                {
                    Raiz[k] = Raiz[Aristas[head].extremo2];
                }
            }
            // Increase the counter
            count++;

            cout << "Edge number " << count << " added (" << Aristas[head].extremo1 + 1 << ", "
                    << Aristas[head].extremo2 + 1 << ") with weight " << Aristas[head].peso << endl;
            pesoMST = pesoMST + Aristas[head].peso;
        }
        // Move on to the next edge
        head++;

    } while ((count < (n - 1)) && (head < m));

    if (count == (n - 1))
    {
        cout << "The weight of the minimum-cost spanning tree is: " << pesoMST << endl;
    }
    else
    {
        cout << "There is no minimum-cost spanning tree" << endl;
    }
}

void GRAFO::PDM() // Builds a shortest path
{
    unsigned s;
    // Ask for the start node s
    cout << "Building a shortest path" << endl;
    while (s < 1 || n < s)
    {
        cout << "Choose the start node [1 - " << n << "] : ";
        cin >> s;
        cout << endl;
    }
    // Create and initialise the visited vector
    vector<bool> Encola;
    // Initially, no node is permanently labelled
    Encola.resize(n, false);

    // Create and initialise pred and d
    vector<unsigned> pred;
    // Initially, pred is null
    pred.resize(n, UERROR);
    // The pred label of s is s itself
    pred[s] = s;
    vector<int> d;
    // Initially, every distance label is infinity
    d.resize(n, maxint);
    // The distance label of node s is 0
    d[s] = 0;

    // Create and initialise dcola
    deque<unsigned> dcola;
    // Add s to dcola and update Encola
    dcola.push_back(s);
    Encola[s] = true;

    while (!dcola.empty())
    {
        // Take the first node, k, from dcola and remove it. Encola must be updated too
        unsigned k = dcola.front();
        dcola.pop_front();
        // Go through the successor list, which identifies the arcs (k, j)
        // For every node j that is a successor of node k, do
        for (unsigned j = 0; j < LA[k].size(); j++)
        {
            // If d[j] > d[k] + ckj for the arc (k, j), the current path to node j can be improved by going through k
            // If (dj > dk + ckj) then
            if (d[j] > d[k] + LA[k][j].c)
            {
                // If node j has never been in the queue
                // If (predj == 0) then
                if (pred[j] == 0)
                {
                    // Insert at the end of the queue (j, dcola)
                    dcola.push_back(LA[k][j].j);
                }
                // Otherwise, it has already been in the queue
                else
                {
                    // If it is not in the queue (j, dcola) then
                    if (!Encola[LA[k][j].j])
                    {
                        // Update d and pred, and add node j to the queue whenever it is not in it
                        // Insert at the front of the queue (j, dcola)
                        dcola.push_front(LA[k][j].j);
                        // dj = dk + ckj;
                        d[LA[k][j].j] = (d[k] + 1) + LA[k][j].c;
                        // predj = k;
                        pred[LA[k][j].j] = k;
                        // Update Encola;
                        Encola[LA[k][j].j] = true;
                    }
                }
            }
        }
    }
    cout << "Solutions:" << endl;
    // This part of the code shows the shortest paths to each node, if any, as long as there are no negative-cost cycles.
    // Print the distance label
    cout << "Cost by distance to the start node, in number of edges" << endl;
    cout << "Distance " << j << " edges";
    for (int k = 0; k < d.size(); k++)
    {
        if (j == d[k])
        {
            cout << " : " << k + 1;
        }
    }
    cout << endl;
    // Print the predecessors
    cout << "Minimum-cost path" << endl;
    if ((j != s - 1) && (pred[j] != UERROR))
    {
        MostrarCamino(s - 1, j, pred);
        cout << endl;
    }
}
