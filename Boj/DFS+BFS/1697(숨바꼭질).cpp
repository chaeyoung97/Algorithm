#include<iostream>
using namespace std;
#include<queue>

int n, k;
bool visit[100001];
int cnt[100001];
//bfs문제??

int main() {
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	visit[n] = true;
	int top;

	int forward;
	int back;
	int doub;
	while (!q.empty()) {
		top = q.front();
		q.pop();

		forward = top + 1;
		back = top - 1;
		doub = top * 2;
		if (forward >= 0 && forward <= 100000 && !visit[forward]) { q.push(forward); visit[forward]=1; cnt[forward] = cnt[top]+1; }
		if (back >= 0 && back <= 100000 && !visit[back]) { q.push(back); visit[back]=1; cnt[back] = cnt[top] + 1; }
		if (doub >= 0 && doub <= 100000 && !visit[doub]) { q.push(doub); visit[doub]=1; cnt[doub] = cnt[top] + 1; }
		if (visit[k])break;
	}
	cout << cnt[k];
}