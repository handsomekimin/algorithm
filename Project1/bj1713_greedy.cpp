#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int N, M;

pair<pair<int, int>, int> Album[101];//count time studentNumber
int Ans[101];

int main()
{
	cin >> N >> M;
	int count = 0;
	int a;

	for (int i = 0; i < M; i++)
	{
		if (count == N) sort(Album, Album + N);
		cin >> a;

		for (int j = 0; j < N; j++)
		{
			if (!Album[j].second)// 앨범이 비어있다면
			{
				Album[j].first.second = i;
				Album[j].first.first = 1;
				Album[j].second = a;
				count++;
				break;
			}
			else if (Album[j].second == a)
			{
				Album[j].first.first++;
				break;
			}
			
			if (j == N - 1 ) {
				Album[0].second = a;
				Album[0].first.first = 1;
				Album[0].first.second = i;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		Ans[i] = Album[i].second;

	}
	sort(Ans, Ans + (count));

	for (int i = 0; i < count; i++)
		cout << Ans[i] << " ";

	return 0;
}