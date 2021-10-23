#include<iostream>
using namespace std;
#include<vector>


int n, m, d, s;
int basket[50][100];
int dx[] = {0,-1,-1,-1,0,1,1,1};
int dy[] = {-1,-1,0,1,1,1,0,-1};	// ←, ↖, ↑, ↗, →, ↘, ↓, ↙
vector<pair<int, int> > cloud;
bool visit[50][100];
void cloudMove() {
	//d 방향으로 s칸이동

	d = d - 1; //0부터쓸꺼니까 하나 줄여주고 시작
	int x, y;
	for (int i = 0; i < cloud.size(); i++) {
		x = cloud[i].first + (dx[d] * s);
		y = cloud[i].second + (dy[d] * s);
		while (x <0) {
			x += n;
		}
		while (y < 0) {
			y += n;
		}

		x = x % n;
		y = y % n;
		cloud[i] = { x,y };
		basket[x][y]++;
	}
}

void waterPlus() {
	//대각선은 idx 1 3 5 7
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = false;
		}
	}
	int xx, yy;
	int cnt;
	for (int i = 0; i < cloud.size(); i++) {
		cnt = 0;
		for (int j = 1; j < 8; j += 2) {
			xx = cloud[i].first + dx[j];
			yy = cloud[i].second + dy[j];

			//범위체크
			if (xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
			if (basket[xx][yy] > 0) cnt++;

		}
		if (cnt > 0) {
			basket[cloud[i].first][cloud[i].second] += cnt;

		}
		visit[cloud[i].first][cloud[i].second] = true;
	}
}
void makeCloud() {
	cloud.clear();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (basket[i][j] < 2)continue;
			if (visit[i][j])continue;

			cloud.push_back({ i,j });
			basket[i][j] -= 2;
		}
	}
}
int main() {
	//0,0 ~ n-1,n-1까지
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> basket[i][j];
		}
	}
	//초기 구름 4개 넣고 시작~
	cloud.push_back({ n - 2,0 });
	cloud.push_back({ n - 2,1 });
	cloud.push_back({ n - 1,0 });
	cloud.push_back({ n - 1,1 });

	for (int i = 0; i < m; i++) {
		cin >> d >> s;
		cloudMove();
		waterPlus();
		makeCloud();


	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer += basket[i][j];
		}
	}
	cout << answer;
 }
