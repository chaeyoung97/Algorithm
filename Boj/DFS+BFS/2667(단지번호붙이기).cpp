#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool visit[25][25];
int answer = 0;
vector<int> arr;
int n;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int total;

void dfs(int a, int b) {

	visit[a][b] = true;
	for (int i = 0; i < 4; i++) {
		int xx = a + dx[i];
		int yy = b + dy[i];

		if (xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
		if (visit[xx][yy]) continue;
		total++;
		dfs(xx,yy);
	}
}

int main() {
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == '1') visit[i][j] = false;
			else visit[i][j] = true;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				answer++;
				total = 1;
				dfs(i, j);
				arr.push_back(total);
			}
		}
	}

	sort(arr.begin(), arr.end());
	cout << answer << "\n";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << "\n";
	}
}