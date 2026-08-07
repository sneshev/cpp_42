#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <array>
#include <cstdio>

#define EXECUTABLE "./PmergeMe"

std::string runPmergeMe(const std::string& input) {
	std::string execute(EXECUTABLE);
	execute += input;

	std::array<char, 4096> buf;
	std::string result;

	FILE* pipe = popen(execute.c_str(), "r");
	if (!pipe)
		throw (std::runtime_error("popen failed"));

	while(fgets(buf.data(), buf.size(), pipe))
		result += buf.data();

	return (pclose(pipe), result);
}

std::string runStdSort(std::vector<int>& v)  {
	std::sort(v.begin(), v.end());

	std::string result;
	for (size_t i = 0; i < v.size(); ++i) {
		result += std::to_string(v[i]) + " ";
	}
	return result;
}


void test(std::vector<int> v) {
	std::string s;
	for (size_t i = 0; i < v.size(); i++)
		s += " " + std::to_string(v[i]);

	// std::cout << "testing: " << s << "   " /*<< std::endl*/;


	std::string r1 = runPmergeMe(s);
	std::string r2 = runStdSort(v);
	if (r1 == r2) {
		std::cout << "✅ ";
	} else {
		std::cout << "\n" << s << std::endl;
		std::cout << "❌😬😬⚠️⛔💥💣⚠️💥⛔💀⚠️❌⛔🫠🫠🫠😭📉" << std::endl;
		std::cout << "PmergeMe : " << r1 << std::endl;
		std::cout << "std::sort: " << r2 << std::endl;
	}
}

template<typename... Args>
std::vector<int> vec(Args... args)
{
    return std::vector<int>{args...};
}

std::vector<int> randVec(size_t n) {
	std::vector<int> result;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, INT32_MAX);

	for (size_t i = 0; i < n; ++i)
	    result.push_back(dist(gen));

	return result;
}

static void standardTests() {
	test(vec(0, 1));
	test(vec(1, 2));
	test(vec(1, 2, 3));
	test(vec(1, 3, 2));
	test(vec(2, 1, 3));
	test(vec(2, 3, 1));
	test(vec(3, 1, 2));
	test(vec(3, 2, 1));
	test(vec(3, 2, 1, 0));
	test(vec(3, 2, 1, 5));
	std::cout << std::endl;
}

int main() {
	// standardTests();
	for (int i = 2; i < 200; ++i) {
		for (int j = 0; j < 10; j++) {
			test(randVec(i));
		}
		if (i % 3 == 1) {
			std::cout << std::endl;
		}
	}
}
