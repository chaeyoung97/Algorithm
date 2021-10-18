#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
bool visit[101];
int beer;
int t, n, x, y;
pair<int, int> start;
pair<int, int> cu[101];
pair<int, int> festival;

int distance(int a, int b, int aa, int bb) {
	return abs(a-aa) + abs(b-bb);
}
void init() {
	memset(visit, 0, sizeof(visit));
}
int main() {
	cin >> t;
	for (int p = 0; p < t; p++) {
		init();
		beer = 20*50;
		cin >> n;
		cin >> x >> y;
		start = {x,y};
		for (int i = 0; i <= n; i++) {
			cin >> x >> y;
			cu[i] = { x,y };
		}
		festival = cu[n];

		queue<pair<int, int> > q;
		q.push(start);
		int xx, yy, tx, ty, dist;

		while (!q.empty()) {
			tx = q.front().first;
			ty = q.front().second;
			q.pop();

			for (int i = 0; i <= n; i++) {
				if (visit[i]) continue;
				dist = distance(tx, ty, cu[i].first, cu[i].second);
				if (dist <= beer) {
					visit[i] = true;
					q.push(cu[i]);
				}
			}
		}
		if (visit[n]) cout << "happy" << "\n";
		else cout << "sad" << "\n";

	}
}