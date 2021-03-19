#include<iostream>
#include<algorithm>
using namespace std;

int arr[1000003];

void search(int a, int s, int e)
{
	int start = s;
	int end = e;
	int mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (arr[mid] == a)
		{
			cout << 1 << "\n";
			return;
		}
		else if (arr[mid] < a)
		{
			start = mid + 1;
		}
		else if (arr[mid] > a)
		{
			end = mid - 1;
		}
	}
	cout << 0 << "\n";


}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n, m, a;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + n);
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> a;
			search(a, 0, n - 1);
		}
	}
}