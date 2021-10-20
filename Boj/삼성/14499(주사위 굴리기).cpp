#include<iostream>
#include<queue>
using namespace std;

int k, x, y, n, m;
queue<int> inst;
int map[21][21];
int dice[7];
int up=1, down=6, east=3, west=4, south=5, north=2;

void move(int a) {
	//1오 2왼 3위 4아
	int tmp;
	if (a == 1) {
		tmp = up;
		up = west;
		west = down;
		down = east;
		east = tmp;
	}
	else if (a == 2) {
		tmp = up;
		up = east;
		east = down;
		down = west;
		west = tmp;
	}
	else if(a == 3) {
		tmp = up;
		up = south;
		south = down;
		down = north;
		north = tmp;
	}
	else if (a == 4) {
		tmp = up;
		up = north;
		north = down;
		down = south;
		south = tmp;
	}
}
int main() {

	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int a;
	for (int i = 0; i < k; i++) {
		cin >> a;
		inst.push(a);
	}
	// 1오 2왼 3위 4아
	int dx[] = { 0,0,0,-1,1 };
	int dy[] = { 0,1,-1,0,0 };

	while (!inst.empty()) {
		a = inst.front();
		inst.pop();
		x = x + dx[a];
		y = y + dy[a];

		if (x < 0 || y < 0 || x >= n || y >= m) {
			x = x - dx[a];
			y = y - dy[a];
			continue;
		}
		move(a);	//주사위를 이동과 함께 굴림

		if (map[x][y] == 0) {
			map[x][y] = dice[down];
		}
		else{
			dice[down] = map[x][y];
			map[x][y] = 0;
		}
		cout << dice[up] << "\n";
	}

}