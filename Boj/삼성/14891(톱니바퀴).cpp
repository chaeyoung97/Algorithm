#include<iostream>
#include<string>
#include<vector>
using namespace std;

int arr[5][9];
int k;
int one = 0, two = 0, three = 0, four = 0;

void solution(int num, int direction) {
	//1 시계방향 -1반시계방향

	int tmp1 = arr[0][(one + 2) % 8];
	int tmp2 = arr[1][(two + 6) % 8];
	int tmp23 = arr[1][(two + 2) % 8];
	int tmp3 = arr[2][(three + 6) % 8];
	int tmp34 = arr[2][(three + 2) % 8];
	int tmp4 = arr[3][(four + 6) % 8];

	if (num == 1) {
		if(direction==1)one = (one + 7) % 8;
		else one = (one + 1) % 8;
		direction = direction * -1;

		if (tmp1 == tmp2) return;

		if (direction == 1)two = (two + 7) % 8;
		else two = (two + 1) % 8;
		direction = direction * -1;

		if (tmp23 == tmp3) return;

		if (direction == 1)three = (three + 7) % 8;
		else three = (three + 1) % 8;
		direction = direction * -1;

		if (tmp34 == tmp4) return;

		if (direction == 1)four = (four + 7) % 8;
		else four = (four + 1) % 8;


	}
	else if (num == 2) {

		if (direction == 1)two = (two + 7) % 8;
		else two = (two + 1) % 8;
		direction = direction * -1;

		if (tmp1 != tmp2) {

			if (direction == 1)one = (one + 7) % 8;
			else one = (one + 1) % 8;
		}

		if (tmp23 == tmp3) return;

		if (direction == 1)three = (three + 7) % 8;
		else three = (three + 1) % 8;
		direction = direction * -1;

		if (tmp34 == tmp4) return;

		if (direction == 1)four = (four + 7) % 8;
		else four = (four + 1) % 8;

	}
	else if (num == 3) {
		if (direction == 1)three = (three + 7) % 8;
		else three = (three + 1) % 8;
		direction = direction * -1;

		if (tmp34 != tmp4) {

			if (direction == 1)four = (four + 7) % 8;
			else four = (four + 1) % 8;
		}

		if (tmp23 == tmp3) return;

		if (direction == 1)two = (two + 7) % 8;
		else two = (two + 1) % 8;
		direction = direction * -1;

		if (tmp1 == tmp2) return;

		if (direction == 1)one = (one + 7) % 8;
		else one = (one + 1) % 8;


	}
	else if (num == 4) {
		if (direction == 1)four = (four + 7) % 8;
		else four = (four + 1) % 8;
		direction = direction * -1;

		if (tmp34 == tmp4) return;

		if (direction == 1)three = (three + 7) % 8;
		else three = (three + 1) % 8;
		direction = direction * -1;

		if (tmp23 == tmp3) return;

		if (direction == 1)two = (two + 7) % 8;
		else two = (two + 1) % 8;
		direction = direction * -1;


		if (tmp1 == tmp2)  return;

		if (direction == 1)one = (one + 7) % 8;
		else one = (one + 1) % 8;

	}
}
int main() {
	string s;
	for (int i = 0; i < 4; i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if(s[j]=='1')arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}

	int num; int direction;
	cin >> k;
	for (int i = 0; i < k; i++) {
		//1 시계방향 -1반시계방향
		cin >> num >> direction;
		solution(num, direction);
	}
	int answer = 0;
	if (arr[0][one]==1)answer += 1;
	if (arr[1][two]==1)answer += 2;
	if (arr[2][three]==1)answer += 4;
	if (arr[3][four]==1)answer += 8;
	cout << answer;
}