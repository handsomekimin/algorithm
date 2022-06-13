#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<stack>
using namespace std;

const int MAXN = 1001;
string A, B;
int dp[MAXN][MAXN];
void print(int i, int j) {
	if (dp[i][j] == 0)return;
	if (A[i - 1] == B[j - 1]) {
		print(i - 1, j - 1);
		cout << A[i - 1];
	}
	else dp[i - 1][j] > dp[i][j - 1] ? print(i - 1, j) : print(i, j - 1);
}
int main()
{
	cin >> A >> B;
	int MAX = 0;
	int i = 1, j = 1;
	for (i = 1; i <= A.length(); i++)
	{
		for ( j = 1; j <= B.length(); j++)
		{
			if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i ][j] = max(dp[i-1][j], dp[i ][j-1]);
		}
	}
	cout << dp[i-1][j-1] << endl;
	print(i-1, j-1);
	return 0;
}






