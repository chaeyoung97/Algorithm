//��ͷ� Ǭ �ڵ�
#include<iostream>
using namespace std;
#include<algorithm>
//DP ���� 
//�޸����̼� �̿�
//��ȭ�� �����
//dp(n) = min(dp(n-1) , dp(n/2), dp(n/3)) + 1
//�� 3���� �������� 2�� �������� 1�� �� ���� �� �� ���� ������ �ʿ�� �ϴ� �Ϳ� +1 �� ����

//algorithm �� min�Լ��� ���ڸ� �ΰ� �̻� ����� ���� {} �̷��� �߰�ȣ�� �迭ó�� ������ָ� ��
int arr[1000005]; 
int dp(int n)
{
	if (n == 1 || n == 2 || n == 3)
	{
		return arr[n];
	}
	if (arr[n] == 0)
	{
		//������������ ���ε� �߿��� 
		//ex) 10�� ��� 10/2 =5  10/3=3 �̱⶧���� arr[3]�� min�̶� �̻��� ���� ���� �� �� ����
		if (n % 6 == 0)
			arr[n] = min({ dp(n - 1), dp(n / 2), dp(n / 3) }) + 1;
		else if (n % 3 == 0)
			arr[n] = min(dp(n - 1), dp(n / 3)) + 1;
		else if (n % 2 == 0)
			arr[n] = min(dp(n - 1), dp(n / 2)) + 1;
		else
			arr[n] = dp(n - 1) + 1;
	}
	return arr[n];
}
int main()
{
	
	int n;
	cin >> n;

	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1; 
	//�̰� �⺻�̶� ���� ��ͷ� ������ ����Ʈ��

	cout << dp(n) << endl;

}