// function for Chapter 2 exercise

#include <iostream>
#include <algorithm>
#include <iterator> 

using namespace std;

void d(int x[], int n)
{
   for (int i = 0; i < n; i += 2)
      x[i] += 2;

   int i = 1;
   while (i <= n/2)
   {
      x[i] += x[i+1];
      i++;
   }
}

int main()
{
   int a[15] = {1,2,3,4,5,6,7,8,9,10,0,0,0,0,0};
   int n = 10;

   // output the array elements
   std::cout << "a[0:9] = ";
   copy(a, a+10, ostream_iterator<int>(cout, " "));
   std::cout << endl;
   
   d(a,n);

   std::cout << "Completed function d(y,10)" << endl;

   // output the array elements
   std::cout << "a[0:9] = ";
   copy(a, a+10, ostream_iterator<int>(cout, " "));
   std::cout << endl;

   return 0;
}
