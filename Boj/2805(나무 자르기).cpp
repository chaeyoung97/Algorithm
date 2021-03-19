//이분탐색이용
#include<iostream>
#include<algorithm>
using namespace std;

long long arr[1000001];

int main() {
	int n;
	long long m, s, e, mid, max = -5, tmp = 0, h = -1;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (max < arr[i])
			max = arr[i];
	}
	s = 0;
	e = max;
	while (s <= e)
	{
		mid = (s + e) / 2;
		tmp = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] - mid > 0)
				tmp += (arr[i] - mid);
		}
		if (tmp >= m)
		{
			if (mid >= h)
				h = mid;
			s = mid + 1;
		}
		else if (tmp < m)
		{
			e = mid - 1;
		}

	}
	cout << h << endl;


}
// 10 15 17 20