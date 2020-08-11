#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001][3];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
	}

	for (int i = 2; i <= n; i++)
	{
		arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + arr[i][0];
		arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + arr[i][1];
		arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + arr[i][2];
	} 
	cout << min({ arr[n][0], arr[n][1], arr[n][2] }) << endl;
	//min함수 인자 여러개는 {} 써서 배열만들어줘서 사용하면 됨
}
