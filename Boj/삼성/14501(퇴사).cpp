#include<iostream>
using namespace std;
#include<vector>
int n;
bool visit[16];
pair<int, int> day[16];
int answer;

void dfs(int d, int end, int total) {
	if (end > n) return;
	if (answer < total ) {
		answer = total;
	}
	for (int j = d; j <= d + day[d].first - 1; j++) {
		visit[j] = true;
	}
	for (int i = d+1; i <= n; i++) {
		if (!visit[i] && day[i].first+i-1<=n) {
			for (int j = i; j <= i + day[i].first - 1; j++) {
				visit[j] = true;
			}
			dfs(i, i + day[i].first - 1, total + day[i].second);

			for (int j = i; j <= i + day[i].first - 1; j++) {
				visit[j] = false;
			}
		}
	}
	for (int j = d; j <= d + day[d].first - 1; j++) {
		visit[j] = false;
	}
}
int main() {
	int t, p;
	cin >> n;
	vector<pair<int, int> > v;
	for (int i = 1; i <= n; i++) {
		cin >> t >> p;
		day[i] = { t,p };
	}

	for (int i = 1; i <= n; i++) {
		visit[i] = true;
		dfs(i, i + day[i].first -1, day[i].second);

	}
	cout << answer;
}