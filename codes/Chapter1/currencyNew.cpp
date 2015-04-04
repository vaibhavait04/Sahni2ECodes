// test currency class with single data member amount

#include <iostream>
#include "currencyNew.h"

using namespace std;

int main()
{
   currency g, h(positive, 3, 50), i, j;

   // try out both forms of setValue
   g.setValue(negative, 2, 25);
   i.setValue(-6.45);

   // do an add and output
   j = h.add(g);
   h.output();
   std::cout << " + ";
   g.output();
   std::cout << " = ";
   j.output(); std::cout << endl;

   // do an increment and output
   i.output();
   std::cout << " incremented by ";
   h.output();
   std::cout << " is ";
   i.increment(h);
   i.output(); std::cout << endl;

   // do two adds in a sequence
   j = i.add(g).add(h);
   i.output();
   std::cout << " + ";
   g.output();
   std::cout << " + ";
   h.output();
   std::cout << " = ";
   j.output(); std::cout << endl;

   // do an increment and add
   std::cout << "Increment ";
   i.output();
   std::cout << " by ";
   g.output();
   std::cout << " and then add ";
   h.output();
   std::cout << endl << "Result is ";
   j = i.increment(g).add(h);
   j.output(); std::cout << endl;
   std::cout << "Incremented object is ";
   i.output(); std::cout << endl;

   // test the exception
   std::cout << "Attempting to initialize with cents = 152" << endl;
   try {i.setValue(positive, 3, 152);}
   catch (illegalParameterValue e)
   {
      std::cout << "Caught thrown exception" << endl;
      e.outputMessage();
   }
   return 0;
}
