#include <string>
#include <vector>

using namespace std;
int answer = 0;
bool visit[201];
void dfs(int n, vector<vector<int>> computers, int k) {
    visit[k] = 1;
    for(int i=0; i<n; i++ ) {
        if(!visit[i] && computers[k][i])
            dfs(n, computers, i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    for(int i = 0; i<n; i++) {
        if(!visit[i]) {
            answer++;
            dfs(n, computers, i);
        }
    }
    return answer;
}