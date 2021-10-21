#include<iostream>
#include<cmath>
using namespace std;

int n;
int row[16];
int answer;

bool posible(int tmp) {
	int a = tmp;
	for (int i = 0; i < tmp; i++) {
		if (row[i] == row[tmp])return false;
		if (abs(tmp-i) == abs(row[tmp] - row[i])) return false;
	}
	return true;
}

void solution(int cnt) {	//몇행까지 채워졌나
	if (cnt == n) {
		answer++;
		return;
	}


	for (int i = 0; i < n; i++) {
		row[cnt] = i;

		if (posible(cnt)) {
			solution(cnt + 1);
		}

	}
}

int main() {
	cin >> n;

	solution(0);
	cout << answer;

}