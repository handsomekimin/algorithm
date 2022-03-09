#include <cstdio>
#include <queue>

using namespace std;

int N;
int T;
int main(){
	scanf("%d", &N);
	priority_queue<int> pq;
	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &T);
		T -= i;
		
		pq.push(T);
		if (pq.top() > T) {
			ans += -T + pq.top();
			pq.pop();
			pq.push(T);
		}

	}
	printf("%lld\n" ,ans);
}