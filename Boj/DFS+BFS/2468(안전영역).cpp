#include<iostream>
#include<cstring>
using namespace std;

bool visit[101][101];
int place[101][101];
int n,cnt, m = -1, answer = 0;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void dfs(int a, int b) {
	if (visit[a][b]) return;
	visit[a][b] = true;
	int xx, yy;
	for (int i = 0; i < 4; i++) {
		xx = a + dx[i];
		yy = b + dy[i];
		if (xx<1 || yy<1 || xx>n || yy>n)continue;
		if (visit[xx][yy])continue;

		dfs(xx, yy);
	}
}
int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> place[i][j];
			if (place[i][j] > m) m = place[i][j];
		}
	}
	m--;
	while (m >= 0) {
		for (int i = 0; i <= n; i++) {
			memset(visit[i], 0, sizeof(visit[i]));
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (place[i][j] <= m)visit[i][j] = true;
			}
		}
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!visit[i][j]) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		if (answer < cnt) answer = cnt;
		m--;
	}
	cout << answer;
}