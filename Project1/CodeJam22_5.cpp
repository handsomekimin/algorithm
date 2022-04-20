#include <cstdio>

using namespace std;

int T, N, K;
int ans;

bool check() {

}

bool deal(int Room, int Passage) {

}

void nextQuestion() {

}


int main() {
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; ++testcase) {
		scanf("%d %d", &N, &K); //N cave K move
		int tryNum = 0;
		int Room, Passage;
		while (++tryNum < K) {
			scanf("%d %d", &Room, &Passage);
			if (deal(Room, Passage)) break;
			nextQuestion();
		}
		printf("E %d\n", ans);
	}
}