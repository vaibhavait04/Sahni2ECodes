#include <iostream> 

template <class T> 
class Testing001{
int variable; 
public: 
	Testing001(int x):variable(x) {std::cout << " calling template with value " << x << std::endl; }
	Testing001<T>& getValue() {
		Testing001<T> variables(this->variable); 
		return variables; 
	}
};

int main()
{

Testing001<int> variables(1); 
variables.getValue();
}
