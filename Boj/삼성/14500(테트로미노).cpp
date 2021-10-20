#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;


int arr[501][501];
int n, m;
int answer;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool visit[501][501];

void dfs(int a, int b, int cnt, int total) {
	if (cnt == 3) {
		if (answer < total)
		{
			answer = total;
		}
		return;
	}
	int xx, yy;
	for (int i = 0; i < 4; i++) {
		xx = a + dx[i];
		yy = b + dy[i];
		if (xx < 0 || yy < 0 || xx >= n || yy >= m)continue;
		if (visit[xx][yy]) continue;

		visit[xx][yy] = true;
		dfs(xx, yy, cnt + 1, total + arr[xx][yy]);
		visit[xx][yy] = false;

	}


}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	vector<vector<pair<int, int> > > v;

	//ㅗ모양만 체크해주고 나머진 bfs로 거리 3까지만 체크하면 됨
	v.push_back({ {0,0},{-1,-1},{-1,0},{-1,1} });
	v.push_back({ {0,0},{-1,-1},{0,-1},{1,-1} });
	v.push_back({ {0,0},{1,-1},{1,0},{1,1 } });
	v.push_back({ {0,0},{-1,1},{0,1},{1,1} });

	int tmp;
	bool unable;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = true;
			dfs(i, j, 0, arr[i][j]);
			visit[i][j] = false;
			for (int k = 0; k < 4; k++) {
				tmp = 0;
				unable = false;
				for (int h = 0; h < 4; h++) {
					if (i + v[k][h].first < 0 || i + v[k][h].first >= n || j + v[k][h].second < 0 || j + v[k][h].second >= m) {
						unable = true;
						break;
					}
					tmp += arr[i + v[k][h].first][j + v[k][h].second];
				}
				if (unable) continue;

				if (tmp > answer) answer = tmp;
			}
		}
	}

	cout << answer;
}
