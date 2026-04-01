class Solution {
 public:
  bool IsSubStructureFromNewRoot(TreeNode* A, TreeNode* B) {
    if (!B) {
      return true;
    } else if (A && B) {
      if (A->val == B->val) {
        return IsSubStructureFromNewRoot(A->left, B->left) &&
               IsSubStructureFromNewRoot(A->right, B->right);
      } else {
        return false;
      }
    } else {
      return false;
    }
  }

  bool isSubStructure(TreeNode* A, TreeNode* B) {
    if (!A || !B) {
      return false;
    }
    if (IsSubStructureFromNewRoot(A, B)) {
      return true;
    }
    return isSubStructure(A->left, B) || isSubStructure(A->right, B);
  }
};