#include "gmock/gmock.h"
#include "simchecker.cpp"

using namespace testing;
class LengthFixture : public testing::Test {
public:
	SimChecker sc;
	void check(int expected, string str1, string str2) {
		SimChecker sc;
		int score = sc.checkLength(str1, str2);
		EXPECT_EQ(expected, score);
	}
};

TEST_F(LengthFixture, sameLengthTest) {
	check(60, "asd", "dsa");
}

TEST_F(LengthFixture, zeroScoreTest) {
	check(0, "a", "bb");
}

TEST_F(LengthFixture, subScoreTest1) {
	check(20, "aaabb", "baa");
}

TEST_F(LengthFixture, subScoreTest2) {
	check(30, "aae", "aa");
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}