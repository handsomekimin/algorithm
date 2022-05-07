#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;

#define MAXN 1001
#define MAXP 101

int T, N,P;

int customer[MAXN][MAXP];
int dp[MAXN][MAXP];

int main() {

	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; ++testcase) {
		scanf("%d %d", &N, &P);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < P; ++j) {
				scanf("%d", &customer[i][j]);
			}
		}

		for (int i = 0; i < N * P; ++i) {
			for (int j = 0; j < P; ++j) {
				if (i == 0) {
					dp[i][j] = customer[i/P][j];
				}
				else {
					if (j != 0) {
						for (int k = 0; k < P; ++k) {
							if (j == k) continue;
							dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(customer[i/P][k] - customer[i/P][j]));
						}
					}
					else {
						for (int k = 0; k < P; ++k) {
							dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(customer[i / P - 1][k] - customer[i / P][j]));
						}
					}
				}
			}
		}
		printf("Case #%d: %d\n", testcase, dp[0][N * P-1]);
	}
}