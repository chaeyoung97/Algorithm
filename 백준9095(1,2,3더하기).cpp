#include<iostream>
#include<algorithm>
using namespace std;

int arr[20];	//1~11까지의 경우의 수 저장할 배열

//만약 3 이라고 있으면 1+2라고 표현가능 
//arr[1] + arr[2] = arr[3] 이 될 수 있음
//arr[7]까지 직접 해 본 결과 점화식을 만들 수 있음
//arr[n] = arr[n-1]+arr[n-2]+arr[n-3]
int main()
{
	int t;
	int n; // 0<n<11
	cin >> t;
	
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	int a = 4;
	while (a < 11)
	{
		arr[n] = arr[n - 1] + arr[n - 2] + arr[n - 3];
	}
	while (t--)
	{
		cin >> n;
		cout << arr[n] << endl;
	}
}