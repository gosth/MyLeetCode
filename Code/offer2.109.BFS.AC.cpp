class Solution {
 public:
  char GetPrevCharacter(const char character) {
    if (character == '0') {
      return '9';
    } else {
      return character - 1;
    }
  }

  char GetNextCharacter(const char character) {
    if (character == '9') {
      return '0';
    } else {
      return character + 1;
    }
  }

  std::vector<std::string> GetNextLevelStates(
      const std::string& current_state,
      const std::unordered_set<std::string>& deadends,
      const std::unordered_map<std::string, int>& state_to_step) {
    std::vector<std::string> next_level_states;
    std::string current_state_2 = current_state;
    for (int index = 0; index < current_state.size(); ++index) {
      const auto& character = current_state[index];
      auto prev_character = GetPrevCharacter(character);
      current_state_2[index] = prev_character;
      if (deadends.find(current_state_2) == deadends.end() &&
          state_to_step.find(current_state_2) == state_to_step.end()) {
        next_level_states.emplace_back(current_state_2);
      }
      auto next_character = GetNextCharacter(character);
      current_state_2[index] = next_character;
      if (deadends.find(current_state_2) == deadends.end() &&
          state_to_step.find(current_state_2) == state_to_step.end()) {
        next_level_states.emplace_back(current_state_2);
      }
      current_state_2 = current_state;
    }
    return next_level_states;
  }

  int BFS(const std::unordered_set<std::string>& deadends,
          const std::unordered_map<std::string, int>& other_state_to_step,
          std::deque<std::string>* queue,
          std::unordered_map<std::string, int>* state_to_step) {
    std::string current = queue->front();
    int step = state_to_step->operator[](current);
    queue->pop_front();
    const std::vector<std::string>& next_level_states =
        GetNextLevelStates(current, deadends, *state_to_step);
    for (const auto& next_level_state : next_level_states) {
      if (auto iter = other_state_to_step.find(next_level_state);
          iter != other_state_to_step.end()) {
        return step + 1 + iter->second;
      } else {
        queue->push_back(next_level_state);
        (*state_to_step)[next_level_state] = step + 1;
      }
    }
    return -1;
  }

  int openLock(vector<string>& deadends, string target) {
    if (target == "0000") {
      return 0;
    }
    std::unordered_set<std::string> deadends_2(deadends.begin(), deadends.end());
    if (deadends_2.find("0000") != deadends_2.end()) {
      return -1;
    }
    std::unordered_map<std::string, int> state_to_step, reverse_state_to_step;
    std::deque<std::string> queue, reverse_queue;
    queue.emplace_back("0000");
    reverse_queue.emplace_back(target);
    state_to_step["0000"] = 0;
    reverse_state_to_step[target] = 0;
    int step = -1;
    while (!queue.empty() && !reverse_queue.empty()) {
      if (queue.size() < reverse_queue.size()) {
        step = BFS(deadends_2, reverse_state_to_step, &queue, &state_to_step);
      } else {
        step = BFS(deadends_2, state_to_step, &reverse_queue, &reverse_state_to_step);
      }
      if (step != -1) {
        return step;
      }
    }
    return -1;
  }
};