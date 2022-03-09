#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

char input[1000001];
int findIdx[1000001];

int main() {
	while (1) {
		ios::sync_with_stdio(false);
		cin.tie(0);
		cin >> input;
		if (input[0] == '.') break;
		//KMP making idx array;
		int j = 0;
		int i;
		for (i = 1; input[i]; ++i) {
			while (j && input[i] != input[j]) {
				j = findIdx[j - 1];
			}
			if (input[i] == input[j]) {
				findIdx[i] = ++j;
			} 
			else {
				findIdx[i] = 0; 
			}
		}
		//verify
		if (i %(i - findIdx[i-1] )==0) {
			printf("%d\n", i / (i - findIdx[i-1]));
		}
		else {
			printf("1\n");
		}

		
	}
	return 0;
}