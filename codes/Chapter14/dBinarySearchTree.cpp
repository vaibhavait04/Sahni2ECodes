// test binary search tree with duplicates class

#include <iostream>
#include "dBinarySearchTree.h"

using namespace std;


int main(void)
{
   dBinarySearchTree<int, char> y;
   y.insert(pair<int, char>(1, 'a'));
   y.insert(pair<int, char>(6, 'f'));
   y.insert(pair<int, char>(3, 'c'));
   y.insert(pair<int, char>(4, 'e'));
   y.insert(pair<int, char>(1, 'b'));
   y.insert(pair<int, char>(6, 'g'));
   y.insert(pair<int, char>(3, 'd'));
   std::cout << "Tree size is " << y.size() << endl;
   std::cout << "Elements in ascending order are" << endl;
   y.ascend();

   pair<const int, char> *s = y.find(3);
   std::cout << "Search for 3 succeeds " << endl;
   std::cout << s->first << ' ' << s->second << endl;
   y.erase(3);
   std::cout << "3 deleted " << endl;
   std::cout << "Tree size is " << y.size() << endl;
   std::cout << "Elements in ascending order are" << endl;
   y.ascend();

   s = y.find(3);
   std::cout << "Search for 3 succeeds " << endl;
   std::cout << s->first << ' ' << s->second << endl;
   y.erase(3);
   std::cout << "3 deleted " << endl;
   std::cout << "Tree size is " << y.size() << endl;
   std::cout << "Elements in ascending order are" << endl;
   y.ascend();

   s = y.find(1);
   std::cout << "Search for 1 succeeds " << endl;
   std::cout << s->first << ' ' << s->second << endl;
   y.erase(1);
   std::cout << "1 deleted " << endl;
   std::cout << "Tree size is " << y.size() << endl;
   std::cout << "Elements in ascending order are" << endl;
   y.ascend();

   s = y.find(8);
   if (s == NULL)
      std::cout << "Search for 8 fails " << endl;
   std::cout << "Tree size is " << y.size() << endl;
   std::cout << "Elements in ascending order are" << endl;
   y.ascend();

   s = y.find(6);
   std::cout << "Search for 6 succeeds " << endl;
   std::cout << s->first << ' ' << s->second << endl;
   y.erase(6);
   std::cout << "6 deleted " << endl;
   std::cout << "Tree size is " << y.size() << endl;
   std::cout << "Elements in ascending order are" << endl;
   y.ascend();

   y.insert(pair<int, char>(1, 'a'));
   y.insert(pair<int, char>(6, 'f'));
   y.insert(pair<int, char>(3, 'c'));
   y.insert(pair<int, char>(4, 'e'));
   y.insert(pair<int, char>(1, 'b'));
   y.insert(pair<int, char>(6, 'g'));
   y.insert(pair<int, char>(3, 'd'));
   std::cout << "Tree size is " << y.size() << endl;
   std::cout << "Elements in ascending order are" << endl;
   y.ascend();
}
