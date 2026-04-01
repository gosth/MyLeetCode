
class Solution {
public:
bool IsPalindrome(const std::string& target_string) {
  if (auto iter = mapping.find(target_string); iter != mapping.end()) {
      return iter->second;
    }
  for (int index = 0; index < target_string.size() / 2; ++index) {
    if (target_string[index] != target_string[target_string.size() - 1 - index]) {
      mapping[target_string] = false;
      return false;
    }
  }
  mapping[target_string] = true;
  return true;
}

void DFS(
    const std::string& s,
    int start_position,
    int data_length,
    std::vector<std::string>* temp_result,
    std::vector<std::vector<std::string>>* results) {
  const auto& target_string = s.substr(start_position, data_length);
  const auto is_end_status = IsPalindrome(target_string);
  if (!is_end_status) {
    return;
  }
  temp_result->emplace_back(target_string);
  auto new_start_position = start_position + data_length;
  if (new_start_position == s.size()) {
    results->emplace_back(*temp_result);
  } else {
    for (int new_data_length = 1; new_data_length + new_start_position <= s.length();
         ++new_data_length) {
      DFS(
          s, new_start_position, new_data_length, temp_result, results);
    }
  }
  temp_result->pop_back();
}


    vector<vector<string>> partition(string s) {
 if (s.empty()) {
    return {};
  }
  std::vector<std::vector<std::string>> results;
  std::vector<std::string> temp_result;
  for (int data_length = 1; data_length <= s.length(); ++data_length) {
    DFS(
        s, 0 /*数据起始下标*/, data_length, &temp_result, &results);
  }
  return results;
    }
    private:
      std::unordered_map<std::string, bool> mapping;
};