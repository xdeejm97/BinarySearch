#include "gtest/gtest.h"
#include <vector>
#include "../BinarySearchLib/BinarySearch.h"

TEST(trivialSearch, trivialFindSize0)
{
	std::vector<unsigned int> v = {};

	ASSERT_TRUE(v.end() == findTrivial(v, 1U));
}
TEST(trivialSearch, trivialFindSize1)
{
	std::vector<unsigned int> v = { 2U };

	ASSERT_TRUE(v.end() == findTrivial(v, 1U));
	ASSERT_TRUE(v.begin() == findTrivial(v, 2U));
	ASSERT_TRUE(v.end() == findTrivial(v, 3U));
}
TEST(trivialSearch, trivialFindSize5)
{
	std::vector<unsigned int> v = { 2U,4U,6U,8U,10U };

	ASSERT_TRUE(v.end() == findTrivial(v, 1U));
	ASSERT_TRUE(v.begin() == findTrivial(v, 2U));
	ASSERT_TRUE(v.end() == findTrivial(v, 3U));
	ASSERT_TRUE(v.begin() + 1 == findTrivial(v, 4U));
	ASSERT_TRUE(v.end() == findTrivial(v, 5));
	ASSERT_TRUE(v.begin() + 2 == findTrivial(v, 6U));
	ASSERT_TRUE(v.end() == findTrivial(v, 7U));
	ASSERT_TRUE(v.begin() + 3 == findTrivial(v, 8U));
	ASSERT_TRUE(v.end() == findTrivial(v, 9U));
	ASSERT_TRUE(v.begin() + 4 == findTrivial(v, 10U));
	ASSERT_TRUE(v.end() == findTrivial(v, 11U));
}

TEST(trivialSearch, trivialFindSize4)
{
	std::vector<unsigned int> v = { 2U,4U,6U,8U };

	ASSERT_TRUE(v.end() == findTrivial(v, 1U));
	ASSERT_TRUE(v.begin() == findTrivial(v, 2U));
	ASSERT_TRUE(v.end() == findTrivial(v, 3U));
	ASSERT_TRUE(v.begin() + 1 == findTrivial(v, 4U));
	ASSERT_TRUE(v.end() == findTrivial(v, 5U));
	ASSERT_TRUE(v.begin() + 2 == findTrivial(v, 6U));
	ASSERT_TRUE(v.end() == findTrivial(v, 7U));
	ASSERT_TRUE(v.begin() + 3 == findTrivial(v, 8U));
	ASSERT_TRUE(v.end() == findTrivial(v, 9U));
}
