#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

bool visit[1001];
bool edge[1001][1001];
int n, m, start;

void init() {
	memset(visit, 0, sizeof(visit));
}
void bfs(int a) {
	queue<int> list;
	list.push(a);
	int now;
	while (!list.empty()) {
		now = list.front();
		list.pop();
		if (visit[now]) continue;
		visit[now] = true;
		cout << now << " ";

		for (int i = 1; i <= n; i++) {
			if (edge[now][i] && !visit[i]) {
				list.push(i);
			}
		}


	}
}

void dfs(int a) {
	if (visit[a] == true)
		return;
	visit[a] = true;
	cout << a << " ";
	for (int i = 1; i <= n; i++) {
		if (edge[a][i] && !visit[i]) dfs(i);
	}
}

int main() {
	cin >> n >> m >> start;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		edge[a][b] = edge[b][a] = true;
	}
	dfs(start);
	init();
	cout << "\n";
	bfs(start);

}