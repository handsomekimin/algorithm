#include <cstdio>
#include <string>
using namespace std;

string input;
int findIdx[1000001];

int main() {
	while (1) {
		scanf("%s", input);
		if (input[0] == '.') break;
		int n = input.length();
		if (n % 2) printf("1\n");
		else {
			//KMP making idx array;
			int j = 0;
			int idx = 0;
			memset(findIdx, 0, sizeof(findIdx));
			for (int i = 0; i <n; ++i) {
				while (j > 0 && input[i] != input[j]) j = findIdx[j-1];
				if (input[i] == input[j]) {
					findIdx[i] = ++j;
				}
				else idx = i;
			}
			//verify
			if (idx + 1 + findIdx[n - 1] == n) {
				printf("%d\n", n / (idx + 1));
			}
			else {
				printf("1\n");
			}

		}
	}
	return 0;
}