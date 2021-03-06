// dynamic programming recursive knapsack

#include <iostream>
#include <math.h>

using namespace std;

// global variables
int *profit;
int *weight;
int numberOfObjects;

int f(int i, int theCapacity)
{// Return f(i,theCapacity).
   if (i == numberOfObjects)
      return (theCapacity < weight[numberOfObjects])
              ? 0 : profit[numberOfObjects];
   if (theCapacity < weight[i])
      return f(i + 1, theCapacity); 
   return max(f(i + 1, theCapacity),
               f(i + 1, theCapacity - weight[i]) + profit[i]);
}

int main(void)
{
   std::cout << "Enter number of objects and knapsack capacity" << endl;
   int knapsackCapacity;
   std::cin >> numberOfObjects >> knapsackCapacity;
   profit = new int [numberOfObjects + 1];
   weight = new int [numberOfObjects + 1];

   for (int i = 1; i <= numberOfObjects; i++)
   {
      std::cout << "Enter profit and weight of object " << i << endl;
      std::cin >> profit[i] >> weight[i];
   }

   std::cout << "Optimal value is " << f(1, knapsackCapacity) << endl;
}
