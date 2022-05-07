
#include <cstdio>
#include <algorithm>
#include <random>
#include <time.h>

using namespace std;

#define MAXN (int)10e3


int A[MAXN];
int sorted[MAXN], temp[MAXN];

int* radixSort();

int main() {

	for (int i = 0; i < MAXN; ++i) {
		A[i] = rand() * (i%2?-1:1) % 100;
		sorted[i] = A[i];
	}

	printf("START SORT\n");
	time_t t = clock();
	sort(A, A + MAXN);
	printf("ALROGITHM N LOG N SORTING : %lld\n", (clock() - t) / CLOCKS_PER_SEC * 1000);
	t = clock();
	int* ret=radixSort();
	printf("RADIX SORTING N * d: %lld\n", (clock() - t) / CLOCKS_PER_SEC * 1000);

	for (int i = 0; i < MAXN; ++i) {
			printf(" A : %d B : %d %d\n", A[i], ret[i], A[i]==ret[i]);
	}
}

int cnt[(1 << 8) + 1];
int* radixSort() {
	int d = 1 << 8;
	int MASK = d - 1;
	int* sp = sorted, * tp = temp, *ap;
	int minus_start=MAXN-1;
	
	for (int i = 0; i < 32; i += 8) {
		//계수정렬
		for (int j = 0; j < d; ++j) cnt[j] = 0;//8비트 단위로 쪼개기 초기화
		for (int j = 0; j < MAXN; ++j) cnt[(sp[j] >> i) & MASK]++; //8비트 단위로 쪼갠 것 중 개수 세기
		for (int j = 1; j < d; ++j) cnt[j] += cnt[j - 1]; // 누적 개수
		for (int j=MAXN-1; j>=0; --j){
			tp[--cnt[(sp[j] >> i) & MASK]] = sp[j]; // 정렬 
			if (i == 24 && sp[j] < 0) minus_start = min(minus_start, j);
		}
		ap = sp, sp = tp, tp = ap;
	}
	
	for (int i =minus_start; i < MAXN; ++i) {
		tp[i-minus_start] = sp[i];
	}
	for (int i = 0; i < minus_start; ++i) {
		tp[i+minus_start] = sp[i];
	}
	return tp;

}