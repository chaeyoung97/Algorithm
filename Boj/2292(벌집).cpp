#include<iostream>
using namespace std;

unsigned long long n;
int main() {
	cin >> n;

	unsigned long long limit = 1;

	unsigned long long answer =0;
	while (1) {
		answer++;
		if (limit >= n) {
			cout << answer;
			return 0;
		}
		limit += 6 * answer;

	}
//1 6 12
}