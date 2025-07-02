#include "gmock/gmock.h"
#include "simchecker.cpp"

TEST(Simchecker, sameLengthTest) {
	SimChecker sc;
	int score = sc.checkLength("asd", "dsa");
	EXPECT_EQ(60, score);
}

TEST(Simchecker, zeroScoreTest) {
	SimChecker sc;
	int score = sc.checkLength("a", "bb");
	EXPECT_EQ(0, score);
}

TEST(Simchecker, subScoreTest1) {
	SimChecker sc;
	int score = sc.checkLength("aaabb", "baa");
	EXPECT_EQ(20, score);
}

TEST(Simchecker, subScoreTest2) {
	SimChecker sc;
	int score = sc.checkLength("aae", "aa");
	EXPECT_EQ(30, score);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}