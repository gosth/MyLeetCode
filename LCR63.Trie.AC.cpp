class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (const auto& item : dictionary) {
            trie.insert(item);
        }
        std::vector<std::string> splited_sentence;
        std::string sentence_2 = sentence;
        auto pos = sentence_2.find(" ");
        while (pos != std::string::npos) {
            splited_sentence.emplace_back(sentence_2.substr(0, pos));
            sentence_2 = sentence_2.substr(pos + 1);
            pos = sentence_2.find(" ");
        }
        splited_sentence.emplace_back(sentence_2);
        std::string result;
        for (const auto& item : splited_sentence) {
            const auto& prefix = trie.FindPrefix(item);
            if (prefix.empty()) {
                result += item + " ";
            } else {
                result += prefix + " ";
            }
        }
        result.pop_back();
        return result;
    }
};