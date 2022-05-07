#include <cstdio>
#include <algorithm>

using namespace std;

int T, D, N;

#define MAXN 100001

struct st {
	int index, value;
};
st arr[MAXN];


int solve() {
	int start = 1, end = N;
	int ret = 0;
	int cur = 0;

	while (start <= end) {
		if (arr[start].value < arr[end].value) {
			if (cur <= arr[start].value) {
				cur = arr[start++].value;
			}
			else {
				if (cur <= arr[end].value) {
					cur = arr[end--].value;
				}
				else break;
			}
		}
		else {
			if (cur <= arr[end].value) {
				cur = arr[end--].value;
			}
			else {
				if (cur <= arr[start].value) {
					cur = arr[start++].value;
				}
				else break;
			}
		}
		++ret;
	}
	return ret;
}

int main() {
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; ++testcase) {
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i) {
			scanf("%d", &arr[i].value);
			arr[i].index = i;
		}
		printf("Case #%d: %d\n", testcase, solve());
	}
	return 0;
}