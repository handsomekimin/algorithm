#include <cstdio>
#include <queue>

using namespace std;

int N;
int A;
int B[1000001];
int main() {
	scanf("%d", &N);
	priority_queue<int> pq;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &A);
		int T =  A - i;

		pq.push(T);
		B[i] = pq.top()+i;
		if (pq.top() > T) {
			pq.pop();
			pq.push(T);
		}
	}
	for (int i = N - 2; i >= 0; --i) {
		B[i] = B[i + 1] > B[i] ? B[i] : B[i + 1]-1;
	}
	for (int i = 0; i < N; ++i) printf("%d\n", B[i]);
}