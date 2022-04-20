#include <cstdio>

using namespace std;

int R, C, T;

void draw() {
	//first line
	printf("..");
	for (int i = 0; i < C; ++i) {
		printf("+");
		if (i != C - 1) printf("-");
	}
	printf("\n");
	//second line
	printf("..");
	for (int i = 0; i < C; ++i) {
		printf("|");
		if (i != C - 1) printf(".");
	}
	printf("\n");

	for (int i = 0; i < R; ++i) {
		
		for (int i = 0; i <= C; ++i) {
			printf("+");
			if (i != C ) printf("-");
		}
		printf("\n");

		if (i == R - 1) break;

		for (int i = 0; i <= C ; ++i) {
			printf("|");
			if (i != C ) printf(".");
		}

		printf("\n");
	}
}

int main() {
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; ++testcase) {
		scanf("%d %d", &R, &C);
		printf("Case #%d:\n", testcase);
		draw();
		
	}
}