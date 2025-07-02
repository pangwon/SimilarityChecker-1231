#include <string>

using std::string;

class SimChecker {
public:
	int checkLength(string str1, string str2) {
		// Same length, get max score
		if (str1.length() == str2.length())
			return 60;

		int longer, shorter;
		longer = std::max(str1.length(), str2.length());
		shorter = std::min(str1.length(), str2.length());
		int gap = longer - shorter;
		
		// gap is larger than two times, zero
		if (longer >= shorter * 2)
			return 0;
		double score = 60 * (1 - static_cast<double>(gap) / shorter);
		return score;
	}
};