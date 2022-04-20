#include <cstdio>
#include <algorithm>

using namespace std;

int T, N;
int S[100001];

int main() {
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; ++testcase) {
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i) {
			scanf("%d", S + i);
		}
		sort(S + 1, S + N+1);
		int cur_num = 1;
		for (int i = 1; i <= N; ++i) {
			if (cur_num > S[i]) continue;
			++cur_num;
		}
		printf("Case #%d: %d\n", testcase, cur_num-1);
	}
}