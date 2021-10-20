 #include<iostream>
 #include<vector>
 #include<cstring>
 #include<algorithm>
 #include<cmath>
 using namespace std;
 int answer=987654321;
 int n;
 int team[21][21];
 bool visit[21];
 void comb(vector<int> v, int cnt) {
 	if (cnt == n/2) {
 		memset(visit, 0, sizeof(visit));
 		int tmp = 0;
 		for (int i = 0; i < v.size(); i++) {
 			visit[v[i]] = true;
 			for (int j = 0; j < v.size(); j++) {
 				tmp += team[v[i]][v[j]];
 			}
 		}
 		int tmp2 = 0;
 		for (int i = 1; i <= n; i++) {
 			if (!visit[i]) {
 				for (int j = 1; j <= n; j++) {
 					if (!visit[j]) tmp2 += team[i][j];
 				}
 			}
 		}

 		answer = min(answer, abs(tmp- tmp2));
 	}

 	int smallest = v.size() == 0 ? 0 : v.back();
 	for (int i = smallest + 1; i <= n; i++) {
 		v.push_back(i);
 		comb(v, cnt + 1);
 		v.pop_back();
 	}
 }
 int main() {
 	cin >> n;
 	for (int i = 1; i <= n; i++) {
 		for (int j = 1; j <= n; j++) {
 			cin >> team[i][j];
 		}
 	}
 	vector<int> v;
 	comb(v, 0);
 	cout << answer;
 }