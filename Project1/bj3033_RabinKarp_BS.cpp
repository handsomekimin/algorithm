#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int L;
char input[200001];
vector<int> s_hash[100008];

const int mod = 100007;
const int mul = 31;

int RabinKarp(int length) {
	for (int i = 0; i < mod; ++i) s_hash[i].clear();
	int j;
	long long power = 1;
	long long hash = 0;
	for (int i = 0; i < L - length; ++i) {
		if (i == 0) {
			for ( j = 0; j < length; ++j) {
				hash *= mul;
				hash += input[j]-'a';
				hash %= mod;
				if (j == length - 1)break;
				power *= mul;
				power %= mod;
			}
		}
		else {
			hash -= (input[i - 1] -'a') * power;
			hash *= mul; 
			hash += input[i + length - 1] -'a';
			hash = hash < 0 ? ((-hash / mod + 1) * mod + hash) : hash;
			hash %= mod;
		
		}
	
		if (!s_hash[hash].empty()) {
			for (int j = 0; j < s_hash[hash].size(); ++j){
				for (int k = 0; k < length; ++k) {
					if (input[i + k] != input[s_hash[hash][j] + k]) break;
				}
				if (j == length) return 1;
			}
		}
		else {
			s_hash[hash].push_back(i);
		}
	}
	return 0;
}

int main() {
	scanf("%d", &L);
	scanf("%s", &input);
	int s = 0, e = L - 1, m;
	int ans = 0;
	while (s <= e) {
		m = (s + e) / 2;
		if (RabinKarp(m)) {
			ans = m;
			s = m + 1;
		}
		else {
			e = m - 1;
		}
	}
	printf("%d\n", ans);
}