#include<iostream>
#include<vector>
using namespace std;

int n;
bool posible;
int w[] = { 5,3 };

void solution(int cnt, int total) {
	if (total > n) return;
	if (total == n) {
		posible = true;
		cout << cnt;
		return;
	}

	for (int i = 0; i < 2; i++) {
		solution(cnt + 1, total + w[i]);
		if (posible) return;
	}
}
int main() {
	cin >> n;

	vector<int> v;
	solution(0, 0);

	if (!posible)cout << -1;
}