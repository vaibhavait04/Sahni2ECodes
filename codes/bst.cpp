// test binary search tree class

#include <iostream.h>
#include "datatype.h"
#include "bst.h"

BSTree<DataType,int> y;

int main(void)
{
   DataType q;
   q.key = 1; q.ID = 'a';
   y.Insert(q);
   q.key = 6; q.ID = 'b';
   y.Insert(q);
   q.key = 4; q.ID = 'c';
   y.Insert(q);
   q.key = 8; q.ID = 'd';
   y.Insert(q);
   std::cout << "Elements in ascending order are" << endl;
   y.Ascend();
   DataType s;
   y.Delete(4,s);
   std::cout << "Delete of 4 succeeds " << endl;
   std::cout << s.key << ' ' << s.ID << endl;
   std::cout << "Elements in ascending order are" << endl;
   y.Ascend();
   y.Delete(8,s);
   std::cout << "Delete of 8 succeeds " << endl;
   std::cout << s.key << ' ' << s.ID << endl;
   std::cout << "Elements in ascending order are" << endl;
   y.Ascend();
   y.Delete(6,s);
   std::cout << "Delete of 6 succeeds " << endl;
   std::cout << s.key << ' ' << s.ID << endl;
   std::cout << "Elements in ascending order are" << endl;
   y.Ascend();
   try {y.Delete(6,s);}
   catch (BadInput)
      {cout << "Delete of 6 fails " << endl;}
   std::cout << "Elements in ascending order are" << endl;
   y.Ascend();
}
