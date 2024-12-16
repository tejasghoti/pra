#include<bits/stdc++.h>
using namespace std;
#define V 5
class Graph
{
// Array to store parent of V
int parent[V];
int rank[V];
public:
// 2D array to represent adjacency matrix
int adj[V][V];
Graph()
{
for (int i = 0; i < V; i++)
{
for (int j = 0; j < V; j++)
{
adj[i][j] = 0;
}
}
for (int i = 0; i < V; i++)
{
parent[i] = i;
}
}
void primsAlgorithm()
{
// Number of edges in the MST
int edges = 0;
// Array to represent vertices which are in the MST
bool selected[5] = {false, false, false, false, false};
// Setting first V as visited V
selected[0] = true;
cout << "Finding MST using Prim's algorithm" << endl
<< endl;
while (edges < V)
{
int minWeight = INT_MAX;
// Indices for iterating on the adjacency matrix
int x, y = 0;
for (int i = 0; i < V; i++)
{
if (selected[i])
{
for (int j = 0; j < V; j++)
{

if (adj[i][j] < minWeight && !selected[j] && adj[i][j] != 0)

{

minWeight = adj[i][j];
x = i;
y = j;
}
}
}
}
cout << x << " " << y << endl;
selected[y] = true;
edges++;
}
cout << edges;
}
// Function to find parent V of a V
int findParent(int u)
{
while (parent[u] != u)
{
u = parent[u];
}
return u;
}
void UNION(int u, int v)
{
u = findParent(u);
v = findParent(v);
if ((rank[u] > rank[v]))
{
parent[u] = v;
rank[u]++;
}
if (rank[u] < rank[v])
{
parent[v] = u;
rank[v]++;
}
else
{
rank[u]++;
}
}
void makeSet()
{
for (int i = 0; i < V; i++)
{
parent[i] = i;
rank[i] = 0;
}
}
// Function to set parent V of a V
void setUnion(int u, int v)
{
u = findParent(u);
v = findParent(v);
parent[u] = v;

}
// Function to find MST using Kruskal's algorithm
void kruskalsAlgorithm()
{
makeSet();
int minWeight, x, y;
int edges = 0;
while (edges < V - 1)
{
minWeight = INT_MAX;
x, y = 0;
for (int i = 0; i < V; i++)
{
for (int j = 0; j < V; j++)
{
if ((findParent(i) != findParent(j)) && (adj[i][j] < minWeight) &&
(adj[i][j] != 0))
{
minWeight = adj[i][j];

x = i;
y = j;
}
}
}
setUnion(x, y);
edges++;
cout << x << " " << y << " " << minWeight << endl;
}
}
// Function to display adjacency matrix
void displayMatrix()
{
for (int i = 0; i < V; i++)
{
for (int j = 0; j < V; j++)
{
cout << adj[i][j] << " ";
}
cout << endl;
}
}
};
// Function to accept weights of edges
Graph readWeights(Graph graph)
{
int v1, v2, weight, edges;
cout << "Enter number of edges in the graph: ";
cin >> edges;
cout << endl;
for (int i = 0; i < edges; i++)
{
cout << "Enter starting V( 0 to 4 ): ";

cin >> v1;
cout << "Enter ending V( 0 to 4 ): ";
cin >> v2;
cout << "Enter weight of edge( 0 means no edge ): ";
cin >> weight;
cout << endl;
graph.adj[v1][v2] = weight;
graph.adj[v2][v1] = weight;
}
return graph;
}
int main()
{
Graph graph;
graph = readWeights(graph);
graph.displayMatrix();
cout << endl;
graph.primsAlgorithm();
cout<<endl;
graph.kruskalsAlgorithm();
return 0;
}