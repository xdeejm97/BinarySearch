#include <vector>

std::vector<unsigned int>::iterator findTrivial(std::vector<unsigned int> & v, unsigned int key)
{
	for (auto i = v.begin(); i != v.end(); ++i)
		if (*i == key)
		{
			//TODO insert the missing statement
		}
	return v.end();
}

std::vector<unsigned int>::iterator findBinary(std::vector<unsigned int>& v, unsigned int key)
{
	auto from = v.begin();
	auto to = v.end();
	while (from != to)
	{
		auto middle = from + std::distance(from, to) / 2;
		if (key == *middle)
		{
			//TODO insert the missing statement
		}
		else
		{
			if (key < *middle)
			{
				//TODO insert the missing statement
			}
			else
			{
				//TODO insert the missing statement
			}
		}
	}
	return v.end();
}