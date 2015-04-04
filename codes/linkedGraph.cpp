// test linked representation of an unweighted graph

#include <iostream>
#include "linkedGraph.h"
#include "unweightedEdge.h"

using namespace std;

int main(void)
{
   linkedGraph g(4);
   std::cout << "Number of Vertices = " << g.numberOfVertices() << endl;
   std::cout << "Number of Edges = " << g.numberOfEdges() << endl;
   std::cout << endl;

   g.insertEdge(new unweightedEdge(2, 4));
   g.insertEdge(new unweightedEdge(1, 3));
   g.insertEdge(new unweightedEdge(2, 1));
   g.insertEdge(new unweightedEdge(1, 4));
   g.insertEdge(new unweightedEdge(4, 2));
   std::cout << "The graph is" << endl;
   std::cout << "Number of Vertices = " << g.numberOfVertices() << endl;
   std::cout << "Number of Edges = " << g.numberOfEdges() << endl;
   std::cout << g << endl;
   std::cout << endl;

   g.eraseEdge(2,1);
   std::cout << "The graph after deleting (2,1) is" << endl;
   std::cout << "Number of Vertices = " << g.numberOfVertices() << endl;
   std::cout << "Number of Edges = " << g.numberOfEdges() << endl;
   std::cout << g << endl;

   std::cout << "existsEdge(3,1) = " << g.existsEdge(3,1) << endl;
   std::cout << "existsEdge(1,3) = " << g.existsEdge(1,3) << endl;
   std::cout << "inDegree(3) = " << g.inDegree(3) << endl;
   std::cout << "outDegree(1) = " << g.outDegree(1) << endl;
   std::cout << "Number of Vertices = " << g.numberOfVertices() << endl;
   std::cout << "Number of Edges = " << g.numberOfEdges() << endl;
   std::cout << endl;

   // test iterator
   std::cout << "Vertices adjacenct to vertex 4" << endl;
   vertexIterator<bool>* gi = g.iterator(4);
   pair<int,bool>* thePair;
   while((thePair = gi->next()) != NULL)
      std::cout << thePair->first << endl;
}
