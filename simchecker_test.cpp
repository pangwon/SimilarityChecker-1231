#include "gmock/gmock.h"
#include "simchecker.cpp"

TEST(Simchecker, tc1) {
	EXPECT_EQ(1, 1);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}