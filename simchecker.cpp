#include <string>

using std::string;

class SimChecker {
public:
	bool usedStr1[26] = { false };
	bool usedStr2[26] = { false };
	const int MAX_SCORE_LENGTH = 60;
	const int NUM_ALPHA = 26;

	int checkLength(string str1, string str2) {
		int longer = std::max(str1.length(), str2.length());
		int shorter = std::min(str1.length(), str2.length());

		if (isSameLength(longer, shorter))
			return MAX_SCORE_LENGTH;
		return getScore(longer, shorter);
	}

	int checkAlpha(string str1, string str2) {
		int samecnt = 0;
		int totalcnt = 0;
		int str1cnt = 0;
		int str2cnt = 0;

		markUsedChars(str1, str1cnt, usedStr1);
		markUsedChars(str2, str2cnt, usedStr2);

		for (int i = 0; i < NUM_ALPHA; i++) {
			if (usedStr1[i] && usedStr2[i])
				samecnt++;
		}

		totalcnt = str1cnt + str2cnt - samecnt;
		double score = 40 * (static_cast<double>(samecnt) / totalcnt);

		return score;
	}

	void markUsedChars(std::string& str, int& strcnt, bool arr[])
	{
		for (int i = 0; i < str.length(); i++) {
			if (arr[str[i] - 'A'] == false) {
				arr[str[i] - 'A'] = true;
				strcnt++;
			}
		}
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