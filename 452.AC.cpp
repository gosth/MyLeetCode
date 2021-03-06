bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
	return p1.first < p2.first;
}
class Solution {
public:

	int findMinArrowShots(vector <pair<int, int>>& points) {
		int arrows = 0;
		if (points.empty()) {
			return arrows;
		}
		arrows = 1;
		sort(points.begin(), points.end(), cmp);
		int start = points.front().first, end = points.front().second;
		for (size_t i = 1; i < points.size(); ++i) {
			const pair<int, int>& point = points[i];
			if (point.first <= end) {
				start = point.first;
				if (point.second < end) {
					end = point.second;
				}
			}
			else {
				++arrows;
				start = point.first;
				end = point.second;
			}
		}
		return arrows;
	}
};