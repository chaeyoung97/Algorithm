#include<iostream>
#include<cmath>
using namespace std;

int n, l;

int answer;

void solution(int map[101][101]) {
	int chk = 0, tmp;
	bool cant;
	for (int i = 0; i < n; i++) {
		chk = 1;
		tmp = map[i][0];
		cant = false;

		for (int j = 1; j < n; j++) {

			if (abs(map[i][j] - tmp) > 1) {
				cant = true; break;
			}
			//내렬오는 경사
			if (map[i][j] < tmp) {
				if (j + l - 1 >= n) {
					cant = true; break; //범위넘어가는 경우 끝냄
				}
				for (int k = j; k < j+l; k++) {
					if (map[i][j] != map[i][k]) {
						cant = true;
						break;
					}
				}
				if (cant) break;
				tmp = map[i][j];
				j = j + l - 1;
				chk = 0;
			}
			//평지
			else if (map[i][j] == tmp) {
				chk++;
			}
			//올라가는 경사
			else if (map[i][j] > tmp) {
				if (chk < l) {
					cant = true;
					break;
				}
				tmp = map[i][j];
				chk = 1;
			}
		}
		if (cant) continue;
		answer++;
	}
}

int main() {
	int map1[101][101];
	int map2[101][101];
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map1[i][j];
			map2[j][i] = map1[i][j];
		}
	}

	solution(map1);
	solution(map2);
	cout << answer;
}