//��Ͷ� �ݺ��� �ΰ��� �� Ǯ�
#include<iostream>
using namespace std;

int arr[41][2];

void fibo(int n)
{
	if (n == 1)
		return ;
	if (n == 0)
		return ;
	if (arr[n][0] == 0 && arr[n][1] == 0)
	{
		fibo(n - 1); fibo(n - 2);
	}
	arr[n][0] = arr[n - 1][0] + arr[n - 2][0];
	arr[n][1] = arr[n - 1][1] + arr[n - 2][1];
}

int main()
{
	//��ͷ� Ǯ��
	arr[0][0] = 1;
	arr[1][1] = 1;

	int t; 
	int n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		fibo(n);
		cout << arr[n][0] << " " << arr[n][1] << endl;
	}

	//�ݺ������� Ǯ��
	/*
	int a = 2;
	while (a < 41)
	{
		arr[a][0] = arr[a - 1][0] + arr[a - 2][0];
		arr[a][1] = arr[a - 1][1] + arr[a - 2][1];
		a++;
	}
	while (t--)
	{
		cin >> n;
		cout << arr[n][0] << " " << arr[n][1] << "\n";
	}
	*/
}