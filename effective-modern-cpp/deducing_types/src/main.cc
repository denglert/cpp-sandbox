#include <iostream>
#include "functions.h"
#include <typeinfo>

//template<typename T>
//void f(ParamType param);

// - Case 1: ParamType is a Reference or Pointer, but not a Universal Reference
template<typename T>
void f1(T& param)
{
	std::cout << "Parameter type: " << typeid(param).name() << std::endl;
}


int main (int argc, const char *argv[])
{
	
	std::cout << "The program " << argv[0] << " has started." << std::endl;
	
	// - Case 1
	int         x = 27;
	const int  cx =  x;
	const int& rx =  x;

	f1(x);  // - T is int,       param's type is       int&
	f1(cx); // - T is const int, param's type is const int&
	f1(rx); // - T is const int, param's type is const int&

	return 0;
}
