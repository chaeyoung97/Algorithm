//재귀로 푼 코드
#include<iostream>
using namespace std;
#include<algorithm>
//DP 문제 
//메모제이션 이용
//점화식 세우기
//dp(n) = min(dp(n-1) , dp(n/2), dp(n/3)) + 1
//즉 3으로 나누던가 2로 나누던가 1을 뺀 숫자 중 더 적은 연산을 필요로 하는 것에 +1 을 해줌

//algorithm 의 min함수의 인자를 두개 이상 사용할 때는 {} 이렇게 중괄호로 배열처럼 사용해주면 됨
int arr[1000005]; 
int dp(int n)
{
	if (n == 1 || n == 2 || n == 3)
	{
		return arr[n];
	}
	if (arr[n] == 0)
	{
		//나눠지는지의 여부도 중요함 
		//ex) 10의 경우 10/2 =5  10/3=3 이기때문에 arr[3]이 min이라서 이상한 값이 리턴 될 수 있음
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
	//이건 기본이라서 만약 재귀로 만들었어도 디폴트임

	cout << dp(n) << endl;

}