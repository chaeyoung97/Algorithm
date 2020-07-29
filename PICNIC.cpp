#include<iostream>
using namespace std;

bool arr[10][10];
bool remain[10];
int total;
int n, m;
void recursive(bool r[10])
{
	int smallest = -1;
	for (int i = 0; i < n; i++)
	{
		if (r[i] == false)
		{
			smallest = i;
			break;
		}
	}
	
	if (smallest == -1)
	{
		total++;
		return ;
	}
	for (int i = smallest + 1; i < n; i++)
	{
		if (r[i] == false && arr[i][smallest])
		{
			r[i] = r[smallest] = true;
			recursive(r);
			r[i] =r[smallest]= false;
		}
	}
	


}

int main()
{
	int c;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		
		cin >> n >> m;
		int a, b;
		total = 0;
		for (int j = 0; j < n; j++)
		{
			remain[j] = false;
			for (int k = 0; k < n; k++)
			{
				arr[j][k] = arr[k][j] = false;
			}
		}
		for (int j = 0; j < m; j++)
		{
			cin >> a >> b;
			arr[a][b] = arr[b][a] = true;
		}
		recursive(remain);
		cout << total << endl; 
	}
}
