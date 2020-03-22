class Solution {
public:
	int sumFourDivisors(vector<int>& nums) {
		int result = 0;
		for (const auto& item : nums) {
			const auto maxDivisor = std::sqrt(item);
			std::vector<int> temp;
			temp.emplace_back(1);
			temp.emplace_back(item);
			for (int i = 2; i <= maxDivisor; ++i) {
				const auto divisor = item / i;
				if (i * divisor == item) {
					if (i == divisor) {
						temp.emplace_back(i);
					}
					else {
						temp.emplace_back(i);
						temp.emplace_back(divisor);
					}
				}
				if (temp.size() > 4) {
					break;
				}
			}
			if (4 == temp.size()) {

				for (const auto& item : temp) {
					result += item;
				}
			}
		}
		return result;
	}
};