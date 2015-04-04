// test max heap

#include <iostream>
#include "maxHeap.h"

using namespace std;

int main(void)
{
   // test constructor and push
   maxHeap<int> h(4);
   h.push(10);
   h.push(20);
   h.push(5);

   std::cout << "Heap size is " << h.size() << endl;
   std::cout << "Elements in array order are" << endl;
   std::cout << h << endl;

   h.push(15);
   h.push(30);

   std::cout << "Heap size is " << h.size() << endl;
   std::cout << "Elements in array order are" << endl;
   std::cout << h << endl;

   // test top and pop
   std::cout << "The max element is " << h.top() << endl;
   h.pop();
   std::cout << "The max element is " << h.top() << endl;
   h.pop();
   std::cout << "The max element is " << h.top() << endl;
   h.pop();
   std::cout << "Heap size is " << h.size() << endl;
   std::cout << "Elements in array order are" << endl;
   std::cout << h << endl;

   // test initialize
   int z[10];
   for (int i = 1; i < 10; i++)
      z[i] = i;
   h.initialize(z, 9);
   std::cout << "Elements in array order are" << endl;
   std::cout << h << endl;
   return 0;
}
