
#include <cstdio>
#include <algorithm>

#define ANS (1000000)

using namespace std;

int T;
int c[3],m[3],y[3],k[3];
int ac, am, ay, ak;

bool solve() {

	int minc = min(c[0], min(c[1], c[2]));
	int minm = min(m[0], min(m[1], m[2]));
	int miny = min(y[0], min(y[1], y[2]));
	int mink = min(k[0], min(k[1], k[2]));

	int sum = minc + minm + miny + mink;
	if (sum < ANS) return false;

	int over = ANS - sum;
	if (minc + over < 0) {
		over += minc;
		minc = 0;
	}
	else {
		minc += over;
		over = 0;
	}


	if (minm + over < 0) {
		over += minm;
		minm = 0;
	}
	else {
		minm += over;
		over = 0;
	}

	if (miny + over < 0) {
		over += miny;
		miny = 0;
	}
	else {
		miny += over;
		over = 0;
	}

	if (mink + over < 0) {
		over += mink;
		mink = 0;
	}
	else {
		mink += over;
		over = 0;
	}

	ac = minc;
	am = minm;
	ay = miny;
	ak = mink;
	

	return true;

}

int main() {
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; ++testcase) {
		for (int i = 0; i < 3; ++i)
			scanf("%d %d %d %d", c + i, m + i, y + i, k + i);

		bool isAns = solve();
		printf("Case #%d: ", testcase);
		if (isAns) {
			printf("%d %d %d %d\n", ac, am, ay, ak);
		}
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}

