#include <cstdio>

using namespace std;

int T, N,K;
int E[1001];
long long KARR[1001];

int main() {
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; ++testcase) {
		scanf("%d %d", &N, &K);
		long long sum = 0;
		long long sqr_sum = 0;
		long long ans = 0;

		for (int i = 0; i < N; ++i) {
			scanf("%d", &E[i]);
			sum += E[i];
			sqr_sum += E[i] * E[i];
		}
		if (sqr_sum == 0) {
			printf("Case #%d: 0\n", testcase);
			continue;
		}
		if (sum==0 || (sqr_sum - sum * sum) % (2 * sum)) {
			printf("Case #%d: IMPOSSIBLE\n", testcase);
			continue;
		}
		ans = (sqr_sum - sum * sum)/(2*sum);
		printf("Case #%d: %lld\n",testcase, ans);


	}
	return 0;
}