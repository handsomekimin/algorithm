#include <cstdio>

int N, X, Y, C;
int A, B;
int main() {
	scanf("%d %d", &N, &C);
	A = B = N;
	for (int i = 0; i < C; ++i) {
		scanf("%d %d", &X, &Y);

		if (X >= A || Y >= B) continue;

		int rowArea = X * B;
		int colArea = Y * A;

		if (rowArea >= colArea) A = X;
		else B = Y;
	}
	printf("%d\n", A * B);
}