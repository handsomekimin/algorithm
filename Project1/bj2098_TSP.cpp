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
		//�� ���������,       0���� ���°� ã���� �������� ���� ��ȯ.
		return A[city][0] == 0 ? INF : A[city][0]; //�ڱ� �ڽ����� ���°� ����.
	}
	if (dp[city][state] != -1)
		return dp[city][state];
	dp[city][state] = INF;
	for (int i = 0; i < N; i++)
	{
		if ((state & (1 << i)) == 0 && A[city][i] != 0) //�Ȱ����� �ڱ��ڽ����� ���� �ʴ� ���
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














