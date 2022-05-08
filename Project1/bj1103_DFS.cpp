#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
const int MAXN = 52;
int Map[MAXN][MAXN];
int dp[MAXN][MAXN];
bool isVisited[MAXN][MAXN];

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };

int dfs(int y=1, int x=1) {
	if (y > N || y <= 0 || x > M || x <= 0 || Map[y][x] == 0) {
		return 0;
	}
	else if (isVisited[y][x]) {
		return -1;
	}
	else if (dp[y][x] != -1) {
		return dp[y][x];
	}

	isVisited[y][x] = true;

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i] * Map[y][x];
		int nx = x + dx[i] * Map[y][x];
	
		int nextMaxMove = dfs(ny, nx);
		if (nextMaxMove == -1) return -1;
		dp[y][x] = max(dp[y][x], nextMaxMove + 1);
	}

	isVisited[y][x] = false;

	return dp[y][x];
}

int main() {
	scanf("%d %d", &N, &M);

	char input[MAXN];
	for (int i = 1; i <= N; i++)
	{
		scanf("%s", input+1);
		for (int j = 1; j <= M; ++j) {
			if (input[j] == 'H') continue;
			Map[i][j] = input[j] - '0';
		}
	}

	memset(dp, -1, sizeof(dp));
	printf("%d\n", dfs());
	return 0;


}