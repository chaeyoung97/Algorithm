
/*
	촌수계산 == 결국 거리 구하기 bfs로 거리를 구해나가기 목표지점의 거리 구하려면 결국 그전에 거리도 다 필요
*/
#include<iostream>
#include<queue>
using namespace std;

int n, m, a, b, x,y;
bool visit[101];
bool edge[101][101];
int cnt[101];
void bfs(int i) {
	queue<int> q;
	q.push(i);
	int top;
	visit[i] = true;
	bool is = false;
	cnt[i] = 0;
	while (!q.empty()) {
		top = q.front();
		q.pop();
		for (int j = 1; j <= n; j++) {
			if (edge[top][j] && !visit[j]) {
				visit[j] = true;
				q.push(j);
				cnt[j] = cnt[top] + 1;
				if (j == b) {
					return;
				}
			}
		}
	}
}
int main() {
	cin >> n >> a >> b >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		edge[x][y] = edge[y][x] = true;
	}
	bfs(a);
	if (!visit[b]) cout << -1;
	else cout << cnt[b];
}