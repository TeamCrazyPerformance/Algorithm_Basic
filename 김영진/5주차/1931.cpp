#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> meeting;
	int start, end;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		meeting.push_back(make_pair(start, end));
	}
	sort(meeting.begin(), meeting.end(), compare);
	int last, ans = 0;
	for (int i = 0; i < meeting.size(); i++) {
		if (i == 0) {
			last = meeting[i].second;
			ans++;
			continue;
		}
		if (meeting[i].first >= last) {
			last = meeting[i].second;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
