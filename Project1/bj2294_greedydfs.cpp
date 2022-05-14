#include <cstdio>
#include <algorithm>

using namespace std;

int N, K; 
int value[101];
int dp[10001];

int dfs(int idx=N-1, int coinNum=0, int remain = K) {
	if (remain < 0) return 0;
	if (remain == 0) {
		return dp[remain] = min(dp[remain], coinNum);
	}
	if (coinNum >= dp[0] || idx<0) return 0;
	if (dp[remain] <= coinNum) return dp[remain];
	dp[remain] = coinNum;

	int coinValue = value[idx];
	int availableCoinNum = remain/value[idx];
	if (remain % value[idx] == 0) {
		return dp[0] = min(dp[0], coinNum + availableCoinNum);
	}

	for (int i = availableCoinNum; i >= 0; --i) {
		dfs(idx - 1, coinNum + i, remain - coinValue * i);
	}
	return 0;
}

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i <= K; ++i) dp[i] = 987654321;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &value[i]);
		if (K % value[i] == 0) dp[0] = min(dp[0],  K  / value[i]);
	}
	sort(value, value + N);
	dfs();

	printf("%d\n", dp[0]==987654321?-1:dp[0]);
	return 0;
}