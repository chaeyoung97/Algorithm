#include<iostream>
using namespace std;
#include<cmath>

int main()
{
	int c;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		int x, y, x2, y2;
		int r, r2;
		cin >> x >> y >> r >> x2 >> y2 >> r2;

		if (x == x2 && y == y2 && r == r2)//겹칠떄
		{
			cout << -1 << endl;
			continue;
		}
		else//무한대가 아닐경우
		{
			double distance = sqrt((x - x2)*(x - x2) + (y - y2)*(y - y2));
			if (distance == 0)//중심같고 반지름 다른 경우
			{
				cout << 0 << endl;
			}
			else if (distance > r + r2)//외부
			{
				cout << 0 << endl;
			}
			else if (distance == r + r2)//외접할 때
			{
				cout << 1 << endl;
			}
			else if (distance < r + r2)//내부
			{
				int R;
				int rr;
				if (r <= r2)
				{
					R = r2;
					rr = r;
				}
				else
				{
					R = r;
					rr = r2;
				}
				if (R - distance == rr)
				{
					cout << 1 << endl;
				}
				else if (R - distance > rr)
				{
					cout << 0 << endl;
				}
				else
				{
					cout << 2 << endl;
				}

			}
		}




			
			

		
	}
}
