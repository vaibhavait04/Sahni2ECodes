// test graph::bipartiteCover

#include <iostream>
#include <iterator>
#include "linkedGraph.h"
#include "graph.h"

using namespace std;

int main(void)
{
   int n = 17;
   int e = 25;
   linkedGraph g(n);

   // input a test graph
   std::cout << "Enter a 25 edge 17 vertex bipartite graph" << endl;
   for (int i = 1; i <= e; i++)
   {
      std::cout << "enter edge " << i << endl;
      int u, v;
      std::cin >> u >> v;
      g.insertEdge(new unweightedEdge(u, v));
   }
   std::cout << "The undirected graph is" << endl;
   g.output(cout);

   int *l = new int [n + 1];
   std::cout << "\nEnter vertex labels" << endl;
   for (int i = 1; i <= n; i++)
      std::cin >> l[i];

   std::cout << "\nThe vertex labels are ";
   copy(l + 1, l + n + 1, ostream_iterator<int>(cout, "  "));
   std::cout << endl;

   int *c = new int [n];
   int size = g.bipartiteCover(l, c);
   if (size == -1) // no cover
      std::cout << "Did not find a cover" << endl;
   else
   {
      std::cout << "The cover is ";
      copy(c, c + size, ostream_iterator<int>(cout, "  "));
      std::cout << endl;
   }
}
