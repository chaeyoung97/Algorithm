#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n;
int answer = 0;

void dfs(int board[21][21], int cnt) {

	if (cnt == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] > answer) answer = board[i][j];
			}
		}
		return;
	}

	queue<int> q;
	vector<int> v;
	int tmp[21][21];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = board[i][j];
		}
	}
	for (int k = 0; k < 4; k++) {
		if (k == 0) {//위
			for (int j = 0; j < n; j++) {
				v.clear();

				for (int i = 0; i < n; i++) {
					if (board[i][j] != 0) v.push_back(board[i][j]);
				}

				for (int i = 0; i < v.size(); i++) {
					if (i + 1 > v.size()-1) break;

					if (v[i] == v[i + 1]) {
						q.push(v[i] * 2);
						v[i + 1] = 0;
						i++;
						continue;
					}
					q.push(v[i]);
				}
				if (v.size() != 0) {
					if(v[v.size()-1] != 0) q.push(v[v.size() - 1]);
				}

				for (int i = 0; i < n; i++) {
					if (q.empty()) {
						tmp[i][j] = 0;
						continue;
					}
					tmp[i][j] = q.front();
					q.pop();
				}
			}
		}
		if (k == 1) {//아래
			for (int j = 0; j < n; j++) {
				v.clear();

				for (int i = n-1; i >=0; i--) {
					if (board[i][j] != 0) v.push_back(board[i][j]);
				}

				for (int i = 0; i < v.size(); i++) {
					if (i + 1 > v.size() - 1) break;

					if (v[i] == v[i + 1]) {
						q.push(v[i] * 2);
						v[i + 1] = 0;
						i++;
						continue;
					}
					q.push(v[i]);
				}
				if (v.size() != 0) {
					if (v[v.size() - 1] != 0) q.push(v[v.size() - 1]);
				}

				for (int i = n-1; i >= 0; i--) {
					if (q.empty()) {
						tmp[i][j] = 0;
						continue;
					}
					tmp[i][j] = q.front();
					q.pop();
				}
			}
		}
		if (k == 2) {//오
			for (int i = 0; i < n; i++) {
				v.clear();

				for (int j = n - 1; j >= 0; j--) {
					if (board[i][j] != 0) v.push_back(board[i][j]);
				}

				for (int j = 0; j < v.size(); j++) {
					if (j + 1 > v.size() - 1) break;

					if (v[j] == v[j + 1]) {
						q.push(v[j] * 2);
						v[j + 1] = 0;
						j++;
						continue;
					}
					q.push(v[j]);
				}
				if (v.size() != 0) {
					if (v[v.size() - 1] != 0) q.push(v[v.size() - 1]);
				}

				for (int j = n - 1; j >= 0; j--) {
					if (q.empty()) {
						tmp[i][j] = 0;
						continue;
					}
					tmp[i][j] = q.front();
					q.pop();
				}
			}
		}
		if (k == 3) {//왼
			for (int i = 0; i < n; i++) {
				v.clear();

				for (int j = 0; j < n; j++) {
					if (board[i][j] != 0) v.push_back(board[i][j]);
				}

				for (int j = 0; j < v.size(); j++) {
					if (j + 1 > v.size() - 1) break;

					if (v[j] == v[j + 1]) {
						q.push(v[j] * 2);
						v[j + 1] = 0;
						j++;
						continue;
					}
					q.push(v[j]);
				}
				if (v.size() != 0) {
					if (v[v.size() - 1] != 0) q.push(v[v.size() - 1]);
				}

				for (int j = 0; j <n; j++) {
					if (q.empty()) {
						tmp[i][j] = 0;
						continue;
					}
					tmp[i][j] = q.front();
					q.pop();
				}
			}
		}

		dfs(tmp, cnt + 1);
	}

}


int main() {
	cin >> n;
	int board[21][21];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	dfs(board, 0);
	cout << answer;
}