#include "gmock/gmock.h"
#include "simchecker.cpp"

TEST(Simchecker, tc1) {
	SimChecker sc;
	int score = sc.checkLength("asd", "dsa");
	EXPECT_EQ(60, score);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}