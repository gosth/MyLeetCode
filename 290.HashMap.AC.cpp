// ConsoleApplication19.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include<map>
#include<string>

using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		std::vector<std::string> patterns, words;
		std::map<std::string, std::string> word2pattern, pattern2word;
		for (const auto& item : pattern) {
			patterns.emplace_back(std::to_string(item));
		}
		splitString(str, words, " ");
		if (words.empty() || words.size() != patterns.size()) {
			return false;
		}
		size_t index = 0;
		for (const auto& word : words) {
			const auto iter = word2pattern.find(word);
			if (iter != word2pattern.end()) {
				if (iter->second != patterns[index]) {
					return false;
				}
			}
			else {
				const std::string& pattern2 = patterns[index];
				const auto iter2 = pattern2word.find(pattern2);
				if (iter2 != pattern2word.end()) {
					return false;
				}
				else {
					pattern2word[pattern2] = word;
					word2pattern[word] = pattern2;
				}
			}
			index += 1;
		}
		return true;
	}
private:
	void splitString(const std::string& s, std::vector<std::string>& v, const std::string& sep) {
		std::string::size_type pos1, pos2;
		pos2 = s.find(sep);
		pos1 = 0;
		while (std::string::npos != pos2)
		{
			v.push_back(s.substr(pos1, pos2 - pos1));

			pos1 = pos2 + sep.size();
			pos2 = s.find(sep, pos1);
		}
		if (pos1 != s.length())
			v.push_back(s.substr(pos1));
	}
};

int main() {
	Solution a;
	std::string p = "abba";
	std::string s = "dog cat cat dog";
	std::cout << a.wordPattern(p, s);
	getchar();
	return 0;
}

