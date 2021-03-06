class Solution {
public:
	bool isValid(string s) {
		if (s.empty()) {
			return true;
		}
		stack<char> symbols;
		for (size_t i = 0; i < s.size(); ++i) {
			switch (s[i])
			{
			case '(':
				symbols.push(s[i]);
				break;
			case '[':
				symbols.push(s[i]);
				break;
			case '{':
				symbols.push(s[i]);
				break;
			case ')':
				if (!symbols.empty()) {
					char nowSymbol = symbols.top();
					if (nowSymbol == '(') {
						symbols.pop();
					}
					else {
						return false;
					}
				}
				else {
					return false;
				}
				break;
			case ']':
				if (!symbols.empty()) {
					char nowSymbol = symbols.top();
					if (nowSymbol == '[') {
						symbols.pop();
					}
					else {
						return false;
					}
				}
				else {
					return false;
				}
				break;
			case '}':
				if (!symbols.empty()) {
					char nowSymbol = symbols.top();
					if (nowSymbol == '{') {
						symbols.pop();
					}
					else {
						return false;
					}
				}
				else {
					return false;
				}
				break;
			}
		}
		if (symbols.empty()) {
			return true;
		}
		else {
			return false;
		}
	}
};