// test linked queue

#include <iostream>
#include "linkedQueue.h"
#include "myExceptions.h"

using namespace std;

int main(void)
{
   linkedQueue<int> q;

   // add a few elements
   q.push(1);
   std::cout << "Queue back is " << q.back() << endl;
   q.push(2);
   std::cout << "Queue back is " << q.back() << endl;
   q.push(3);
   std::cout << "Queue back is " << q.back() << endl;
   q.push(4);
   std::cout << "Queue back is " << q.back() << endl;

   std::cout << "Queue should be 1234, front to back" << endl;

   // test empty and size
   if (q.empty())
      std::cout << "The queue is empty" << endl;
   else
      std::cout << "The queue is not empty" << endl;

   std::cout << "The queue size is " << q.size() << endl;

   while (!q.empty())
   {
      std::cout << "Queue front is " << q.front() << endl;
      q.pop();
      std::cout << "Popped front element" << endl;
   }

   try {q.pop();}
   catch (queueEmpty message)
   {
      std::cout << "Last pop failed " << endl;
      message.outputMessage();
   }

   return 0;
}
