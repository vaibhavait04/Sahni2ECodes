#include <iostream> 

template <class T> class Testing ;

template<>
class Testing<int> 
{

};

int main()
{
Testing<int> var; 


}
