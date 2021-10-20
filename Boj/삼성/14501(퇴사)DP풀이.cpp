#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int total[18];
int n, t, p;
int main() {
	vector<pair<int, int> > v;
	v.push_back({ 0,0 });
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t >> p;
		v.push_back({ t,p });
	}

	int idx, mx;
	for (int i = 1; i <= n; i++) {
		idx = i + v[i].first;
		if (idx > n + 1);
		total[idx] = max(total[idx], total[i] + v[i].second);
		for (int j = idx; j <= n+1; j++) {
			total[j] = max(total[j], total[idx]);
		}
	}
	int answer = 0;
	for (int i = 1; i <= n+1; i++) {
		answer = max(answer, total[i]);
	}
	cout << answer;
}
