// test max height biased leftist tree class

#include <iostream>
#include "maxHblt.h"

using namespace std;

int main(void)
{
   maxHblt<int> h, j;
   int a[6] = {0, 7, 9, 1, 8, 11};
   h.initialize(a,5);
   std::cout << "One tree in postorder is" << endl;
   std::cout << "Tree size is " << h.size() << endl;
   h.output();
   int b[5] = {0, 2, 6, 4, 9};

   j.initialize(b,4);
   std::cout << "Other tree in postorder is" << endl;
   std::cout << "Tree size is " << j.size() << endl;
   j.output();

   h.meld(j);
   std::cout << "After melding, the tree in postorder is" << endl;
   std::cout << "Tree size is " << h.size() << endl;
   h.output();

   int w = h.top();
   h.pop();
   int x = h.top();
   h.pop();
   int y = h.top();
   h.pop();
   int z = h.top();
   h.pop();
   std::cout << "After popping four elements, the tree is" << endl;
   std::cout << "Tree size is " << h.size() << endl;
   h.output();
   std::cout << "The popped elements, in order, are" << endl;
   std::cout << w << "  " << x << "  " << y << "  " << z << endl;

   h.push(10);
   h.push(20);
   h.push(5);
   std::cout << "After pushing 10, 20 & 5, the tree is" << endl;
   std::cout << "Leftist tree in postorder" << endl;
   std::cout << "Tree size is " << h.size() << endl;
   h.output();

   h.push(15);
   h.push(30);
   h.push(2);
   std::cout << "After pushing 15, 30 & 15, the tree is" << endl;
   std::cout << "Leftist tree in postorder" << endl;
   std::cout << "Tree size is " << h.size() << endl;
   h.output();

   std::cout << "The max element is " << h.top() << endl;

   h.pop();
   std::cout << "Popped max element " << endl;
   std::cout << "Leftist tree in postorder" << endl;
   std::cout << "Tree size is " << h.size() << endl;
   h.output();

   x = h.top();
   h.pop();
   std::cout << "Popped max element " << x << endl;
   std::cout << "Tree size is " << h.size() << endl;
   std::cout << "Leftist tree in postorder" << endl;
   h.output();

   while (true)
   {// empty out
      try
      {
         x = h.top();
         h.pop();
         std::cout << "Popped " << x << endl;
         std::cout << "Tree size is " << h.size() << endl;
      }
      catch (queueEmpty) {break;}
   }

   return 0;
}
