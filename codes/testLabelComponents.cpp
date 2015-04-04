// test graph::labelComponents

#include <iostream>
#include "graph.h"
#include "adjacencyWDigraph.h"
#include "adjacencyDigraph.h"
#include "adjacencyWGraph.h"
#include "adjacencyGraph.h"
#include "linkedWDigraph.h"
#include "linkedDigraph.h"
#include "linkedWGraph.h"
#include "linkedGraph.h"
#include "weightedEdge.h"
#include "unweightedEdge.h"
#include "myExceptions.h"

using namespace std;

int main(void)
{
   int numberOfTypes = 4;
   // create a graph of each type
   graph<bool>* g[4];
   graph<int>* h[4];
   g[0] = new adjacencyGraph(7);
   g[1] = new adjacencyDigraph(7);
   g[2] = new linkedGraph(7);
   g[3] = new linkedDigraph(7);
   h[0] = new adjacencyWGraph<int>(7);
   h[1] = new adjacencyWDigraph<int>(7);
   h[2] = new linkedWGraph<int>(7);
   h[3] = new linkedWDigraph<int>(7);
   int n = 7;

   // try 2 test graphs
   for (int q = 1; q <= 2; q++)
   {
      // input a test graph
      std::cout << "Enter number of edges in graph" << endl;
      int e, u, v, w;
      std::cin >> e;
      for (int i = 1; i <= e; i++)
      {
         std::cout << "Enter weighted edge " << i << endl;
         std::cin >> u >> v >> w;
         for (int j = 0; j < numberOfTypes; j++)
         {
            g[j]->insertEdge(new unweightedEdge(u, v));
            h[j]->insertEdge(new weightedEdge<int>(u, v, w));
         }
      }
   
      // output the test graph .. undirected and directed version
      for (int i = 0; i < 2; i++)
      {
         std::cout << "Graph " << i << " is" << endl;
         std::cout << "Number of Vertices = " << g[i]->numberOfVertices() << endl;
         std::cout << "Number of Edges = " << g[i]->numberOfEdges() << endl;
         g[i]->output(cout);
         std::cout << endl << endl;
      }
      int *theC = new int [n + 1];
      // test connected on all graph types
      for (int i = 0; i < numberOfTypes; i++)
      {
         try
         {
            std::cout << "Number of components = " 
                 << g[i]->labelComponents(theC) << endl;
            std::cout << "The component labels are ";
            copy(theC + 1, theC + n + 1, ostream_iterator<int>(cout, "  "));
            std::cout << endl;
         }
         catch (undefinedMethod e)
            {e.outputMessage();}
      }
      for (int i = 0; i < numberOfTypes; i++)
      {
         try
         {
            std::cout << "Number of components = " 
                 << h[i]->labelComponents(theC) << endl;
            std::cout << "The component labels are ";
            copy(theC + 1, theC + n + 1, ostream_iterator<int>(cout, "  "));
            std::cout << endl;
         }
         catch (undefinedMethod e)
            {e.outputMessage();}
      }
   }
}
