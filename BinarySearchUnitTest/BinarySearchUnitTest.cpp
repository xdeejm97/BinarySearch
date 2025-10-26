#include "gtest/gtest.h"
#include <vector>
#include "../BinarySearchLib/BinarySearch.h"


TEST(binarySearch, binaryFindSize0)
{
	std::vector<unsigned int> v = {};

	ASSERT_TRUE(v.end() == findBinary(v, 1U));
}
TEST(binarySearch, binaryFindSize1)
{
	std::vector<unsigned int> v = { 2U };

	ASSERT_TRUE(v.end() == findBinary(v, 1U));
	ASSERT_TRUE(v.begin() == findBinary(v, 2U));
	ASSERT_TRUE(v.end() == findBinary(v, 3U));
}
TEST(binarySearch, binaryFindSize5)
{
	std::vector<unsigned int> v = { 2U,4U,6U,8U,10U };

	ASSERT_TRUE(v.end() == findBinary(v, 1U));
	ASSERT_TRUE(v.begin() == findBinary(v, 2U));
	ASSERT_TRUE(v.end() == findBinary(v, 3U));
	ASSERT_TRUE(v.begin()+1 == findBinary(v, 4U));
	ASSERT_TRUE(v.end() == findBinary(v, 5U));
	ASSERT_TRUE(v.begin()+2 == findBinary(v, 6U));
	ASSERT_TRUE(v.end() == findBinary(v, 7U));
	ASSERT_TRUE(v.begin()+3 == findBinary(v, 8U));
	ASSERT_TRUE(v.end() == findBinary(v, 9U));
	ASSERT_TRUE(v.begin()+4 == findBinary(v, 10U));
	ASSERT_TRUE(v.end() == findBinary(v, 11U));
}

TEST(binarySearch, binaryFindSize4)
{
	std::vector<unsigned int> v = { 2U,4U,6U,8U };

	ASSERT_TRUE(v.end() == findBinary(v, 1U));
	ASSERT_TRUE(v.begin() == findBinary(v, 2U));
	ASSERT_TRUE(v.end() == findBinary(v, 3U));
	ASSERT_TRUE(v.begin() + 1 == findBinary(v, 4U));
	ASSERT_TRUE(v.end() == findBinary(v, 5U));
	ASSERT_TRUE(v.begin() + 2 == findBinary(v, 6U));
	ASSERT_TRUE(v.end() == findBinary(v, 7U));
	ASSERT_TRUE(v.begin() + 3 == findBinary(v, 8U));
	ASSERT_TRUE(v.end() == findBinary(v, 9U));
}

