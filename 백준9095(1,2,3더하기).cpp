#include<iostream>
#include<algorithm>
using namespace std;

int arr[20];	//1~11������ ����� �� ������ �迭

//���� 3 �̶�� ������ 1+2��� ǥ������ 
//arr[1] + arr[2] = arr[3] �� �� �� ����
//arr[7]���� ���� �� �� ��� ��ȭ���� ���� �� ����
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