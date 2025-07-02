#include "gmock/gmock.h"
#include "simchecker.cpp"

using namespace testing;
class SimcheckerFixture : public testing::Test {
public:
	SimChecker sc;
	void checklen(int expected, string str1, string str2) {
		SimChecker sc;
		int score = sc.checkLength(str1, str2);
		EXPECT_EQ(expected, score);
	}
	void checkalpha(int expected, string str1, string str2) {
		SimChecker sc;
		int score = sc.checkAlpha(str1, str2);
		EXPECT_EQ(expected, score);
	}
};

TEST_F(SimcheckerFixture, sameLengthTest) {
	checklen(60, "asd", "dsa");
}

TEST_F(SimcheckerFixture, zeroScoreTest) {
	checklen(0, "a", "bb");
}

TEST_F(SimcheckerFixture, subScoreTest1) {
	checklen(20, "aaabb", "baa");
}

TEST_F(SimcheckerFixture, subScoreTest2) {
	checklen(30, "aae", "aa");
}

TEST_F(SimcheckerFixture, sameAlphaTest) {
	checkalpha(40, "ASD", "DSA");
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}