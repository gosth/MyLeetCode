
class Solution {
public:
    string simplifyPath(string path) {
        std::deque<std::string> stack;
        std::string file;
        for (int i = 1; i < path.size(); ++i) {
            if (path[i] == '/') {
                if (!file.empty()) {
                    if (file == "..") {
                        if (!stack.empty()) {
                            stack.pop_back();
                        }
                    } else if (file == ".") {
                        // 什么都不做
                    } else {
                        // 正常路径名
                        stack.emplace_back(file);
                    }
                    file.clear();
                    continue;
                } else {
                    continue;
                }
            } else {
                file = file + path[i];
            }
        }
        if (!file.empty()) {
            if (file == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else if (file == ".") {
                // 什么都不做
            } else {
                // 正常路径名
                stack.emplace_back(file);
            }
        }
        std::string result = "/";
        for (const auto& item : stack) {
            result += item + "/";
        }
        if (result.size() >= 2) {
            result.pop_back();
        }
        return result;
    }
};