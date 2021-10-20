#include<iostream>
using namespace std;

int n,m,r,c,d;
int visit[51][51];
int direction[] = { 0,1,2,3 };
int answer;

void change_direction() {
	d = (d + 3) % 4;
}

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void clean(int a, int b) {

	int xx, yy;
	int tmp = d;
	bool is_clean = false;
	for (int i = 0; i < 4; i++) {
		change_direction();
		xx = a + dx[d];
		yy = b + dy[d];

		if (visit[xx][yy]==1) continue;
		if (visit[xx][yy]==2) continue;
		answer++;
		visit[xx][yy] = 2;
		is_clean = true;
		clean(xx, yy);
		break;
	}

	if (!is_clean) {
		d = tmp;
		xx = a - dx[d];
		yy = b - dy[d];
		if (visit[xx][yy]==1) return;

		clean(xx, yy);
	}
}

int main() {
	cin >> n >> m >> r >> c >> d; //0북 1동 2남 3서
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> visit[i][j];
		}
	}

	visit[r][c] = 2;
	answer++;
	clean(r, c);
	cout << answer;
}