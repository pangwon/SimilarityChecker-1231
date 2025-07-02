#include <string>

using std::string;

class SimChecker {
public:
	int checkLength(string str1, string str2) {
		if (str1.length() == str2.length())
			return 60;
	}
};