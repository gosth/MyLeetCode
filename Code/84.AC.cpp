#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {

        int result = 0;
        height.push_back(0);
        vector<int> index;
        for (size_t i = 0; i < height.size(); ++i) {
            while (!index.empty() && height[index.back()] >= height[i]) {
                int width = height[index.back()];
                index.pop_back();
                int length = !index.empty() ? i - index.back() -1 : i;
                if (width * length > result) {
                    result = width * length;
                }
            }
            index.push_back(i);
        }
        return result;
    }
};

int main() {
    vector<int> a = {2,1,5,6,2,3};
    Solution b;
    cout << b.largestRectangleArea(a) << endl;
}