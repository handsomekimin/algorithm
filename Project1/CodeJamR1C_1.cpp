#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int T, N;
char S[101][11];
int length[101];
int check[27];


int main() {
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; ++testcase) {
		scanf("%d", &N);
		memset(S, 0, sizeof(S));
		memset(length , 0, sizeof(length));
		bool impossible = false;
		for (int i = 0; i < N; ++i) {
			memset(check, 0, sizeof(check));
			scanf("%s", &S[i]);
			// lut for length
			for (int j = 0; j < 10; ++j) {
				if (!S[i][j]) {
					length[i] = j;
					break;
				}
			}
			//check each tower has appropriate alphabet
			for (int j = 0; j < 10; ++j) {
				if (check[S[i][j] - 'A']) {
					if (S[i][j - 1] != S[i][j]) {
						impossible = true;
					}
				}
				check[S[i][j] - 'A']++;
			}
		}
		//check alphatbet middle of each tower, should be unique
		//except same with it's head / tail
		memset(check, 0, sizeof(check));
		for (int i = 0; i < N; ++i) {
			for (int j = 1; j < length[i] - 1; ++j) {
				if (S[i][j] == S[i][0] || S[i][j] == S[i][length[i] - 1]) continue;
				if (check[S[i][j] - 'A']) {
					impossible = true;
					break;
				}
				check[S[i][j] - 'A']++;
			}
			if (impossible) break;
		}

		if (impossible) {
			printf("Case #%d: IMPOSSIBLE\n", testcase);
			continue;
		}


	}
	return 0;
}