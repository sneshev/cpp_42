#include <iostream>
#include <vector>
#include <list>
#include "../inc/EasyFind.hpp"
 
template <typename T>
void test(T &container, int value)
{
    typename T::iterator it = easyfind(container, value);
 
    if (it != container.end())
        std::cout << "Found " << *it << std::endl;
    else
        std::cout << value << " not found" << std::endl;
}
 
int main()
{
    std::cout << "--- vector<int> ---" << std::endl;
	{
		std::vector<int> vec;
		for (int i = 1; i <= 5; ++i)
			vec.push_back(i * 2); // 2 4 6 8 10
	
		test(vec, 6);   // found, middle
		test(vec, 2);   // found, first element
		test(vec, 10);  // found, last element
		test(vec, 7);   // not found
		std::cout << std::endl;
	}
 
    std::cout << "--- list<int> ---" << std::endl;
	{
		std::list<int> lst;
		lst.push_back(42);
		lst.push_back(21);
		lst.push_back(84);
	
		test(lst, 21);  // found
		test(lst, 100); // not found
	}
 
    return 0;
}
 