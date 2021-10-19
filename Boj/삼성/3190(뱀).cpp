#include<iostream>
#include<queue>
using namespace std;

int n, k, l, direction;
int board[101][101];
queue<pair<int, char> > inst;
deque<pair<int, int> > snake;

int answer = 0;

int change_direction(char c, int d) {
	if (c == 'L')return (d + 3) % 4;
	if (c == 'D') return (d + 1) % 4;
}

int main() {
	cin >> n >> k;
	int x, y;
	for (int i = 1; i <= k; i++) {
		cin >> x >> y;
		board[x][y] = 1;
	}
	cin >> l;
	char c;
	for (int i = 0; i < l; i++) {
		cin >> x >> c;
		inst.push({ x,c });
	}

	int dx[] = { 0,1,0,-1 };
	int dy[] = { 1,0,-1,0 };

	direction = 0; // 0오 1아래 2왼 3위
	board[1][1] = -1;
	snake.push_back({ 1,1 });
	int xx, yy;
	while (1) {
		answer++;
		x = inst.front().first;
		c = inst.front().second;
		//움직이는 동작
		xx = snake.front().first + dx[direction];
		yy = snake.front().second + dy[direction];

		if (xx<1 || yy<1 || xx>n || yy>n) { cout << answer; return 0; } //벽에 부딪히면 안돼
		if (board[xx][yy]<0) { cout << answer; return 0; } //내몸이랑 부딫혀도 안댕
		if (board[xx][yy] == 1) {	//사과먹은경우

			board[xx][yy] = -1;	//사과 지우고 몸통 마킹
			snake.push_front({ xx,yy });
		}
		else {
			snake.push_front({ xx,yy });
			board[xx][yy] = -1; //몸통 마킹해주고
			board[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}
		//x초지났으면 방향 바꾸기
		if (x == answer) {
			inst.pop();
			direction = change_direction(c, direction);
		}

	}
	cout << answer;
}