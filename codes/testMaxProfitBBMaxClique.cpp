
// test adjacencyGraph::maxProfitBBMaxClique

#include <iostream>
#include <iterator>
#include "adjacencyGraph.h"
#include "unweightedEdge.h"

using namespace std;

int main(void)
{
   // input a test graph
   std::cout << "Enter number of vertices and edges" << endl;
   int n, e;
   std::cin >> n >> e;
   adjacencyGraph g(n);

   for (int i = 1; i <= e; i++)
   {
      std::cout << "Enter edge " << i << endl;
      int u, v;
      std::cin >> u >> v;
      g.insertEdge(new unweightedEdge(u, v));
   }
   std::cout << "The undirected graph is" << endl;
   g.output(cout);

   int *c = new int [n + 1];
   std::cout << "The max clique size is " << g.maxProfitBBMaxClique(c) << endl;
   std::cout << "The vertex selection vector is ";
   copy(c + 1, c + n + 1, ostream_iterator<int>(cout, "  "));
   std::cout << endl;
}
