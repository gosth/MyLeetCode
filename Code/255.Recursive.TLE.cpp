
class Solution {
public:
    bool processInteractionNum(std::vector<int>& preorder, int currentIndex, int endIndex) {
        if (currentIndex >= endIndex) {
            return true;
        }
        int index = currentIndex + 1;
        for (; index <= endIndex; ++index) {
            if (preorder[index] > preorder[currentIndex]) {
                break;
            }
        }
        for (int judgeIndex = index; judgeIndex <= endIndex; ++judgeIndex) {
            if (preorder[judgeIndex] < preorder[currentIndex]) {
                return false;
            }
        }
        return processInteractionNum(preorder, currentIndex + 1, index - 1)
                && processInteractionNum(preorder, index, endIndex);
    }

    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.empty()) {
            return true;
        }
        return processInteractionNum(preorder, 0, preorder.size() - 1);
    }
};