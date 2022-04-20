#include <cstdio>

using namespace std;

int T;
char S[102];
int len;
int main() {
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; ++testcase) {
		scanf("%s", &S);
		len = 0;
		while (S[len++]);
		printf("Case #%d: ", testcase);
		//find ascending 

		int start_idx = 0;
		for (int last_idx = 1; last_idx < len; ++last_idx) {
			if (S[last_idx] > S[last_idx - 1]) {
				for (int i = start_idx; i < last_idx; ++i) {
					printf("%c", S[i]);
					printf("%c", S[i]);
				}
				start_idx = last_idx;
			}
			else if (S[last_idx] == S[last_idx - 1]) {
				if (last_idx == len - 1) {
					for (int i = start_idx; i < last_idx; ++i) printf("%c", S[i]);
				}
			}
			else {
				for (int i = start_idx; i < last_idx; ++i) printf("%c", S[i]);
				start_idx = last_idx ;
			}
		}
		printf("\n");
	}
	return 0;
}