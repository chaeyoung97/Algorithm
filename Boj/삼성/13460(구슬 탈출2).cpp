#include<iostream>
using namespace std;
#include<queue>
#include<vector>

int n, m;
char board[11][11];
bool visit[11][11][11][11];
pair<int, int> red;
pair<int, int> blue;
pair<int, int> hole;


bool is_same_rb(int rx, int ry ,int bx, int by) {
	if (rx==bx && ry ==by) return true;
	return false;
}

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool is_red_front(int i) {
	if (i == 0) {
		if (red.first > blue.first)return true;
		return false;
	}
	if (i == 1) {
		if (red.first < blue.first) return true;
		return false;
	}
	if (i == 2) {
		if (red.second > blue.second) return true;
		return false;
	}
	if (i == 3) {
		if (red.second < blue.second) return true;
		return false;
	}
}

int main() {
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') red = { i,j };
			if (board[i][j] == 'B') blue = { i,j };
			if (board[i][j] == 'O') hole = { i,j };
		}
	}

	queue< vector<pair<int, int> > > q;
	pair<int, int> top;
	q.push({ red, blue });
	visit[red.first][red.second][blue.first][blue.second]= true;
	

	int answer = 1;
	int xx, yy , bxx, byy, rcnt, bcnt;
	int queue_size;
	
	while(!q.empty()) {
		queue_size = q.size();
		while (queue_size != 0) {
			if (answer == 11) {
				cout << -1; return 0;
			}
			red = q.front()[0];
			blue = q.front()[1];
			q.pop();
	
			bool blue_hole ,red_hole;

			for (int i = 0; i < 4; i++) {
				blue_hole = false;
				red_hole = false;
				xx = red.first;
				yy = red.second;
				bxx = blue.first;
				byy = blue.second;

				while (board[bxx + dx[i]][byy + dy[i]] != '#') {
					bxx = bxx + dx[i];
					byy = byy + dy[i];
					if (board[bxx][byy] == 'O') {
						blue_hole = true; break;
					}
				}
				if (blue_hole) { continue; }
				while (board[xx + dx[i]][yy + dy[i]] != '#') {
					xx = xx + dx[i];
					yy = yy + dy[i];
					if (board[xx][yy] == 'O') {
						red_hole = true; break;
					}
				}
				if (red_hole) { cout << answer; return 0; }
				
				
				if (is_same_rb(xx,yy,bxx,byy)) {
					if (is_red_front(i)) {
						bxx = bxx - dx[i];
						byy = byy - dy[i];
					}
					else {
						xx = xx - dx[i];
						yy = yy - dy[i];
					}
				}
				if (visit[xx][yy][bxx][byy]) continue;
				q.push({ {xx,yy},{bxx,byy} });
				visit[xx][yy][bxx][byy] = true;
				
			}
			queue_size--;
			
		}answer++;
	}
	cout << -1;
}