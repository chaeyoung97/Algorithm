#include<iostream>
using namespace std;
//dp문제
//dp(n) = 1+ min( dp(n-1), dp(n/2), dp(n/3) ) 이란 관계식을 세울 수 있음
//메모제이션 (배열)

int arr[1000001];

int main() 
{
	int n;
	cin >> n;
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	int a = 4;
	while (a != 1000001)
	{
		if (a % 6 == 0)
		{
			if (arr[a - 1] <= arr[a / 2] && arr[a - 1] <= arr[a / 3])
				arr[a] = arr[a - 1] + 1;
			else if (arr[a / 2] <= arr[a - 1] && arr[a / 2] <= arr[a / 3])
				arr[a] = arr[a / 2] + 1;
			else if (arr[a / 3] <= arr[a - 1] && arr[a / 3] <= arr[a / 2])
				arr[a] = arr[a / 3] + 1;
		}
		else if (a % 3 == 0)
		{
			if (arr[a - 1] <= arr[a / 3])
				arr[a] = arr[a - 1] + 1;
			else
				arr[a] = arr[a / 3] + 1;
		} 
		else if (a % 2 == 0)
		{
			if (arr[a - 1] <= arr[a / 2])
				arr[a] = arr[a - 1] + 1;
			else
				arr[a] = arr[a / 2] + 1;
		}
		else
			arr[a] = arr[a - 1] + 1;
		a++;
	}
	cout << arr[n] << endl;
}
