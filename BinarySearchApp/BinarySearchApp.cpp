#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include "benchmark.h"
#include "../BinarySearchLib/BinarySearch.h"

int main()
{
	size_t n;
	do
	{
		size_t findCount;
		std::cout << "Collection size:";
		std::cin >> n;
		std::cout << "Number of searches:";
		std::cin >> findCount;

		std::vector<unsigned int> v;

		auto seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::mt19937 generator((unsigned int)seed);

		for (size_t i = 0; i < n; i++)
		{
			v.push_back(generator());
		}

		std::sort(v.begin(), v.end());

		long long tBinary = 0LL;
		long long tTrivial = 0LL;

		for (size_t i = 0; i < findCount; ++i)
		{
			auto key = generator();
			{
				Benchmark<std::chrono::nanoseconds> b;
				findBinary(v, key);
				auto t = b.elapsed();
				tBinary += t;
				std::cout << "findBinary: " << t << std::endl;
			}
			{
				Benchmark<std::chrono::nanoseconds> b;
				findTrivial(v, key);
				auto t = b.elapsed();
				tTrivial += t;
				std::cout << "findTrivial: " << t << std::endl;
			}
		}
		if (findCount > 0)
		{
			std::cout << "Average search time (collection size: " << n << ")" << std::endl;
			std::cout << "\t findBinary: " << tBinary / findCount << " ns" << std::endl;
			std::cout << "\tfindTrivial: " << tTrivial / findCount << " ns" << std::endl;
		}
	} while (n > 0);
}