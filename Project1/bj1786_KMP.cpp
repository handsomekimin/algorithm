#include <cstdio>
#include <string>
#include <iostream>

using namespace std;



int n, m;
string Origin, Find;
int FindIdx[1000001];
int matchIdx[1000001];
int ans;

int main() {
	getline(cin, Origin);
	getline(cin, Find);
	n = Origin.length();
	m = Find.length();
	//making Find idx;
	int j = 0;
	for (int i = 1; i < m; ++i) {
		while (j > 0 && Find[j] != Find[i]) {
			j = FindIdx[j - 1];
		}
		if (Find[j] == Find[i]) FindIdx[i] = ++j;
	}
	
	//Searching
	j = 0;
	for (int i = 0; i < n; ++i) {
		while (j > 0 && Find[j] != Origin[i]) {
			j = FindIdx[j - 1];
		}
		if (Origin[i] == Find[j]) {
			++j;
			if (j == m) {
				matchIdx[ans++] = i-m+2;
				j = FindIdx[j - 1];
			}
		}
	}
	printf("%d\n", ans);
	for (int i = 0; i < ans; ++i) printf("%d ", matchIdx[i]);

}