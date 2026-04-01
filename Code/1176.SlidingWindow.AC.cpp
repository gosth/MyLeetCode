class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int result = 0, tempSum = 0;
        for (int index = 0; index < k; ++index) {
            tempSum += calories[index];
        }
        if (tempSum < lower) {
            result -= 1;
        }
        if (tempSum > upper) {
            result += 1;
        }
        for (int index = k; index < calories.size(); ++index) {
            tempSum = tempSum - calories[index - k] + calories[index];
            if (tempSum < lower) {
                result -= 1;
            }
            if (tempSum > upper) {
                result += 1;
            }
        }
        return result;
    }
};