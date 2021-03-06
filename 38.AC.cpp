class Solution {
public:
	string countAndSay(int n) {
		std::string result = "1";
		while (--n) {
			std::string now;
			for (size_t i = 0; i < result.size(); ++i) {
				size_t count = 1;
				while (i + 1 <result.size() && result[i] == result[i + 1]) {
					++count;
					++i;
				}
				now += std::to_string(count) + result[i];
			}
			result = now;
		}
		return result;
	}
};