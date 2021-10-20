#include<iostream>
#include<vector>
using namespace std;

int arr[9][9];
vector<pair<int, int> > blank;
vector<pair<int, int> > virus;
bool visit[9][9];
int n, m;
int answer = 0;
bool tmp[9][9];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void dfs(int a, int b) {

	int xx, yy;
	for (int i = 0; i < 4; i++) {
		xx = a + dx[i];
		yy = b + dy[i];
		if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
		if (tmp[xx][yy]) continue;
		tmp[xx][yy] = true;
		dfs(xx, yy);
	}
}

void comb(vector<int>v, int cnt) {
	if (cnt == 3) {
		//벽세우기
		for (int i = 0; i <n; i++) {
			for (int j = 0; j < m; j++) {
				tmp[i][j] = visit[i][j];
			}
		}

		tmp[blank[v[0]].first][blank[v[0]].second] = true;
		tmp[blank[v[1]].first][blank[v[1]].second] = true;
		tmp[blank[v[2]].first][blank[v[2]].second] = true;


		for (int i = 0; i < virus.size(); i++) {
			dfs(virus[i].first, virus[i].second);
		}
		int total = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (tmp[i][j] == false)total++;
			}
		}
		if (answer < total) {
			answer = total;
		}
		return;
	}
	int smallest = v.size() == 0 ? -1 : v.back();

	for (int i = smallest+1; i < blank.size(); i++) {
		v.push_back(i);
		comb(v, cnt + 1);
		v.pop_back();
	}
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) blank.push_back({ i,j });
			if (arr[i][j] == 1||arr[i][j]==2) visit[i][j] = true;
			if (arr[i][j] == 2) virus.push_back({ i,j });
		}
	}
	vector<int> v;
	comb(v, 0);
	cout << answer;
}