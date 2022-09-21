class MyCalendar {
 public:
  MyCalendar() {

  }

  bool book(int start, int end) {
    if (date_records_.empty()) {
      date_records_.emplace(start, end);
      return true;
    }
    auto iter = date_records_.lower_bound(start);
    if (iter != date_records_.end()) {
      if (iter->first == start) {
        return false;
      } else {
        if (end <= iter->first && (iter == date_records_.begin() || start >= (--iter)->second)) {
          date_records_.emplace(start, end);
          return true;
        } else {
          return false;
        }
      }
    } else {
      if (start >= (--date_records_.end())->second) {
        date_records_.emplace(start, end);
        return true;
      } else {
        return false;
      }
    }
  }

  std::map<int, int> date_records_;
};