#include<iostream>
#include<queue>
using namespace std;

bool visit[101];
bool m[101][101];
int total, n;
int answer = 0;
void dfs(int a) {

	visit[a] = true;


	for (int i = 1; i <= total; i++) {
		if (m[a][i] && !visit[i]) { dfs(i); answer++; }
	}
}

int main() {

	cin >> total >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		m[a][b] = m[b][a] = true;
	}

	dfs(1);
	cout << answer;

}