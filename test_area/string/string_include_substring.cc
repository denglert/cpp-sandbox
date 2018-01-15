#include <string>
#include <iostream>


void check_if_included(const char parent[], const char search[])
{
	std::size_t index;
	std::string parent_string = parent;
	std::string search_string = search;

   index	= parent_string.find(search_string);

	std::cout << "parent: " << parent << std::endl;
  	std::cout << "search: " << search << std::endl;

	if(index)
	{
		std::cout << "index regarded as true." << std::endl;
	}

	if(index != std::string::npos)
	{
		std::cout << "(index != std::string::npos) is true." << std::endl;
	}

	std::cout << "index: " << index << std::endl;
	std::cout << "-----------" << std::endl;
}


int main (int argc, const char *argv[])
{
	
	std::cout << "The program " << argv[0] << " has started." << std::endl;
	
	check_if_included("This is a long sentence containing the word dog in it.", "dog");
	check_if_included("This is a long sentence containing the word dog in it.", "cat");
	
	return 0;
}
