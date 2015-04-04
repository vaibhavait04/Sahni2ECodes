// test adjacencyGraph::btMaxClique

#include <iostream>
#include <iterator>
#include "adjacencyGraph.h"

using namespace std;

int main(void)
{
   const int n = 7;
   adjacencyGraph g(n);

   // input a test graph
   std::cout << "Enter number of edges in 7 vertex graph"<< endl;
   int e;
   std::cin >> e;
   for (int i = 1; i <= e; i++)
   {
      std::cout << "Enter unweighted edge " << i << endl;
      int u, v;
      std::cin >> u >> v;
      g.insertEdge(new unweightedEdge(u, v));
   }

   std::cout << "The undirected graph is" << endl;
   g.output(cout);

   // test btMaxClique
   int *v = new int [n + 1];
   std::cout << "\nMax Clique size is " << g.btMaxClique(v) << endl;
   std::cout << "\nSolution vector is ";
   copy(v + 1, v + n + 1, ostream_iterator<int>(cout, "  "));
   std::cout << endl;
}
