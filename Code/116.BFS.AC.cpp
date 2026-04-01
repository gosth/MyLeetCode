class Solution {
public:
    void buildTree(std::deque<Node*>* collection) {
        while (!collection->empty()) {
            int featureCount = collection->size();
            Node* dummy = new Node(-1);
            bool markNextPointer = false;
            for (int index = 0; index < featureCount; ++index) {
                auto& currentNode = collection->front();
                if (currentNode->left) {
                    dummy->next = currentNode->left;
                    dummy = dummy->next;
                    dummy->next = currentNode->right;
                    dummy = dummy->next;
                    collection->push_back(currentNode->left);
                    collection->push_back(currentNode->right);
                } else {
                    return;
                }
                collection->pop_front();
            }
        }
    }

    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }
        std::deque<Node*> q;
        q.push_back(root);
        buildTree(&q);
        return root;
    }
};