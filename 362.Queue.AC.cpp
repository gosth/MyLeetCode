class HitCounter {
public:
	/** Initialize your data structure here. */
	HitCounter() {

	}

	/** Record a hit.
	@param timestamp - The current timestamp (in seconds granularity). */
	void hit(int timestamp) {
		if (m_sequence.empty()) {
			m_beginTimeStamp = timestamp;
		}
		m_sequence.push_back(timestamp);
		while (m_beginTimeStamp < timestamp - 300 + 1) {
			cout << "size|" << m_sequence.size() << endl;
			m_sequence.pop_front();
			m_beginTimeStamp = m_sequence.front();
		}
	}

	/** Return the number of hits in the past 5 minutes.
	@param timestamp - The current timestamp (in seconds granularity). */
	int getHits(int timestamp) {
		int result = 0;
		//cout << "size|" << m_sequence.size() << endl;
		while (m_beginTimeStamp < timestamp - 300 + 1) {
			if (!m_sequence.empty()) {
				m_sequence.pop_front();
				if (!m_sequence.empty()) {
					m_beginTimeStamp = m_sequence.front();
				} else {
					m_beginTimeStamp = timestamp;
				}
			} else {
				m_beginTimeStamp = timestamp;
			}
		}
		result = m_sequence.size();
		return result;
	}

private:
	std::deque<int> m_sequence;
	int m_beginTimeStamp;
};


/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */