class Solution {
public:
	int numSteps(string s) {
		unsigned long num = 0;
		for (const auto& item : s) {
			num = num * 10 + item - '0';
		}
		int step = 0;
		while (num != 1) {
			if (num % 2 == 0) {
				s = s.substr(0, s.size()-1);
				num = 0;
				for (const auto& item : s) {
					num = num * 10 + item - '0';
				}
			}
			else {
				bool carryBit = true;
				int zeroCnt = 0;
				for (auto iter = s.rbegin(); iter != s.rend(); ++iter) {
					if (carryBit) {
						if (*iter == '0') {
							*iter = '1';
							carryBit = false;
							break;
						}
						else {
							++zeroCnt;
							*iter = '0';
							carryBit = true;
						}

					}
				}
				if (zeroCnt == s.size()) {
					s = "1" + s;
				}
				num = 0;
				for (const auto& item : s) {
					num = num * 10 + item - '0';
				}
			}

			++step;

		}
		return step;
	}
};