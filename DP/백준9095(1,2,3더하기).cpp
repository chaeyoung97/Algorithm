#include<iostream>
#include<algorithm>
using namespace std;

int arr[12];	//1~11������ ����� �� ������ �迭


//arr[7]���� ���� �� �� ��� ��ȭ���� ���� �� �־���
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
		arr[a] = arr[a - 1] + arr[a - 2] + arr[a - 3];
		a++;
	}
	while (t--)
	{
		cin >> n;
		cout << arr[n] << endl;
	}

}