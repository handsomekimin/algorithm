#include <cstdio>

using namespace std;


int N;
long long num[10];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		int cur = i;
		while (cur) {
			num[cur % 10]++;
			cur /= 10;
		}
	}
	for (long long i : num) {
		printf("%lld ", i);
	}
}