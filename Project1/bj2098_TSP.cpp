#include <algorithm>
#include <cstdio>
using namespace std;


const int MAXN = 17;
const int MAXW = 1005;
const int INF = 987654321;
int A[MAXN][MAXN];
int dp[MAXN][1 << MAXN];




int N, W;




int tsp(int city, int state)
{
	printf("city : %d stated : %d\n", city, state);
	if (state == (1 << N) - 1) {
		//꽉 차있을경우,       0으로 가는거 찾으면 나머지도 같은 순환.
		return A[city][0] == 0 ? INF : A[city][0]; //자기 자신으로 가는거 빼고.
	}
	if (dp[city][state] != -1)
		return dp[city][state];
	dp[city][state] = INF;
	for (int i = 0; i < N; i++)
	{
		if ((state & (1 << i)) == 0 && A[city][i] != 0) //안갔었고 자기자신으로 가지 않는 경우
		{
			dp[city][state] = min(dp[city][state], tsp(i, (state | (1 << i))) + A[city][i]);
			
		}
	}
	return dp[city][state];

}



int main()
{
	scanf("%d", &N);

	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &A[j][i]);
		}
	}

	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < (1 << N); i++)
		{
			dp[j][i] = -1;
		}
	}
	printf("%d\n", tsp(0, 1));

	return 0;

}














