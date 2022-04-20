
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int T, N;
int F[100001];
int P[100001];
vector<int> from[100001];
bool used[100001];
int maxF[100001];

int Find(int idx) {
	if (from[P[idx]].size() > 1 || P[idx] ==0) return idx;
	return Find(P[idx]);
}

long long solve() {
	long long ret = 0;
	for (int i = N; i >0; --i) {
		//chaining
		if (from[i].size()==0) {
			int idx = i;
			int cur_max = F[idx];
		
			while (1) {
				while (from[P[idx]].size() == 1 && P[idx] != 0) {
					cur_max = max(cur_max, F[P[idx]]);
					idx = P[idx];
				}
				maxF[idx] = cur_max;
				if (P[idx] == 0) break;
				
				
				idx = P[idx];
				if (maxF[Find(idx)]) break;
				cur_max = F[idx];

			}
		}
	}

	for (int i = N; i >= 1; --i) {
	}
	return ret;
}

int main() {
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; ++testcase) {
		memset(maxF, 0, sizeof(maxF));
		memset(used, 0, sizeof(used));
		scanf("%d", &N);
		from[0].clear();
		for (int i = 1; i <= N; ++i) {
			scanf("%d", F + i);
			from[i].clear();
		}
		for (int i = 1; i <= N; ++i) {
			scanf("%d", P + i);
			from[P[i]].push_back(i);
		}

		printf("Case #%d: %lld\n", testcase, solve());
	}
	return 0;
}