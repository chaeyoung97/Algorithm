/*
https://100100e.tistory.com/92
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int visit[101][101][101];
int day,m,n,h;
int unripe;
int cnt[101][101][101];
queue<vector<int> > q;
int main() {
	cin >> m >> n >> h;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				cin >> visit[i][j][k];
				if (visit[i][j][k] == 0) unripe++;
				if (visit[i][j][k] == 1) q.push({ i,j,k });
			}
		}
	}
	if (unripe == 0) { cout << 0; return 0; }
	int x, y, z, xx, yy, zz;
	int dx[] = {0,0,-1,1,0,0};
	int dy[] = {1,-1,0,0,0,0};
	int dz[] = {0,0,0,0,1,-1};

	while (!q.empty()) {
		x = q.front()[0];
		y = q.front()[1];
		z = q.front()[2];
		q.pop();

		for (int i = 0; i < 6; i++) {
			xx = x + dx[i];
			yy = y + dy[i];
			zz = z + dz[i];
			if (xx<1 || yy<1 || zz<1 || xx>h || yy>n || zz>m)continue;
			if (visit[xx][yy][zz]==1 || visit[xx][yy][zz]==-1) continue;

			q.push({ xx,yy,zz });
			visit[xx][yy][zz] = 1;
			cnt[xx][yy][zz] = cnt[x][y][z] + 1;
			unripe--;
		}
	}
	if (unripe != 0) {
		cout << -1;
	}
	else {
		day = -1;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= m; k++) {
					if (cnt[i][j][k] > day) day = cnt[i][j][k];
				}
			}
		}
		cout << day;
	}
}