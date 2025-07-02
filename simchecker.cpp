#include <string>

using std::string;

class SimChecker {
public:

	const int MAX_SCORE_LENGTH = 60;

	int checkLength(string str1, string str2) {
		int longer = std::max(str1.length(), str2.length());
		int shorter = std::min(str1.length(), str2.length());

		if (isSameLength(longer, shorter))
			return MAX_SCORE_LENGTH;
		return getScore(longer, shorter);
	}
private:
	bool isSameLength(int len1, int len2) {
		return len1 == len2;
	}

	double getScore(int longer, int shorter) {
		int gap = longer - shorter;
		double score = 60 * (1 - static_cast<double>(gap) / shorter);
		if (score < 0) score = 0;
		return score;
	}

};