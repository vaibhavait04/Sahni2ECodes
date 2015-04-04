// test stack derived from chain

#include <iostream>
#include "derivedLinkedStack.h"
#include "myExceptions.h"

using namespace std;

int main(void)
{
   derivedLinkedStack<int> s;

   // add a few elements
   s.push(1);
   s.push(2);
   s.push(3);
   s.push(4);

   std::cout << "Stack should be 1234, bottom to top" << endl;

   // test empty and size
   if (s.empty())
      std::cout << "The stack is empty" << endl;
   else
      std::cout << "The stack is not empty" << endl;

   std::cout << "The stack size is " << s.size() << endl;

   while (!s.empty())
   {
      std::cout << "Stack top is " << s.top() << endl;
      s.pop();
      std::cout << "Popped top element" << endl;
   }

   try {s.pop();}
   catch (stackEmpty message)
   {
      std::cout << "Last pop failed " << endl;
      message.outputMessage();
   }

   return 0;
}
