#include<iostream>
#include<string>
#include<queue>
using namespace std;

bool visit[101][101];
int cnt[101][101];
int n, m;


void bfs(int x, int y) {
	queue<pair<int, int> > q;
	int topx, topy;
	q.push({ x, y });
	cnt[x][y] = 1;

	int dx[] = { 0,0,-1,1 };
	int dy[] = { 1,-1,0,0 };

	while (!q.empty()) {
		topx = q.front().first;
		topy = q.front().second;
		q.pop();

		int xx, yy;
		for (int i = 0; i < 4; i++) {
			xx = topx + dx[i];
			yy = topy + dy[i];

			if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
			if (visit[xx][yy]) continue;

			visit[xx][yy] = true;
			q.push({ xx,yy });
			cnt[xx][yy] = cnt[topx][topy] + 1;
			if (xx == n - 1 && yy == m - 1)return;
		}
	}
}

int main() {
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '1') visit[i][j] = false;
			else visit[i][j] = true;
		}
	}

	bfs(0, 0);
	cout << cnt[n - 1][m - 1];
}