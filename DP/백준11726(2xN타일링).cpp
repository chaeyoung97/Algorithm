#include<iostream>
using namespace std;


//생각을 잘 해보면 n-1번째 타일의 맨 오른쪽에 세로로 타일을 하나 붙이는 경우
//n-2번째 타일의 맨 오른 쪽에 가로로 타일 두개를 붙이는 경우 
//위의 두가지 경우로 나눌 수 있으므로 점화식을 세울 수 있음
//또는 직접 4번~5번 해보면 점화식을 세울 수 있음
//a[n] = a[n-1] + a[n-2]

int arr[1001];
int main()
{
	int n;
	cin >> n;

	arr[1] = 1;
	arr[2] = 2;
	int a = 3;
	while (a <= n)
	{
		arr[a] = (arr[a - 1] % 10007 + arr[a - 2] % 10007) % 10007;
		a++;
	}
	cout << arr[n] << endl;
}