#include<iostream>
using namespace std;

int n;
int num[1000001];
int b, c;
long long answer = 0;

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cin >> b >> c;


	for (int i = 0; i < n; i++) {
		num[i] = num[i] - b;
		answer++;
		if (num[i] > 0) {
			answer += (num[i] / c);
			if (num[i] % c != 0) answer++;
		}
	}
	cout << answer;
}