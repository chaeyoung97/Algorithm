#include<iostream>
#include<queue>
using namespace std;

int f, s, g, u, d;
bool visit[1000001];
int cnt[1000001];
int main() {
	cin >> f >> s >> g >> u >> d;

	queue<int> q;
	q.push(s); //현재층
	int top;
	int dx[] = { u, d*(-1) };
	while (!q.empty()) {
		top = q.front();
		q.pop();
		visit[top] = 1;
		int xx;
		for (int i = 0; i < 2; i++) {
			xx = top + dx[i];
			if (xx<1 || xx>f) continue;
			if (visit[xx]) continue;

			visit[xx] = 1;
			q.push(xx);
			cnt[xx] = cnt[top] + 1;
			if (visit[g]) {
				cout << cnt[g];
				return 0;
			}
		}

	}
	cout << "use the stairs";

}