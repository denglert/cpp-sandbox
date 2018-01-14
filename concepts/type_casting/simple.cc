#include <iostream>
#include <typeinfo>

int main (int argc, const char *argv[])
{
	
	std::cout << "The program " << argv[0] << " has started." << std::endl;


	// - Automatic type casting.
	// - Example:
	// - Casting integer to float
	
	int y1 = 2;
	int y2 = 3;

	float x1 = 2/3;
	float x2 = y1/y2;
	float x3 = float(y1)/y2;
	float x4 = (float)y1/y2;
	float x5 = static_cast<float>(y1) / y2;

	std::cout << "x1 =                       2/3: " << x1 << std::endl;
	std::cout << "x2 =                     y1/y2: " << x2 << std::endl;
	std::cout << "x3 =              float(y1)/y2: " << x3 << std::endl;
	std::cout << "x4 =              (float)y1/y2: " << x4 << std::endl;
	std::cout << "x5 = static_cast<float>(y1)/y2: " << x5 << std::endl;


	// 
	int c1 =  82;
	int c2 = 105;
	int c3 = 110;
	int c4 =  97;

	std::cout << "static_cast<char>(c1): " << static_cast<char>(c1) << std::endl;
	std::cout << "static_cast<char>(c2): " << static_cast<char>(c2) << std::endl;
	std::cout << "static_cast<char>(c3): " << static_cast<char>(c3) << std::endl;
	std::cout << "static_cast<char>(c4): " << static_cast<char>(c4) << std::endl;

	// 
	std::cout << "typeid(x1): " << typeid(x1).name() << std::endl;

	return 0;
}
