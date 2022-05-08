#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int N, M;

pair<pair<int, int>, int> Album[101];

int main()
{
	cin >> N >> M;
	bool isEmpty = true;
	int count = 0;
	int* Ans = new int[N];

	for (int i = 0; i < M; i++)
	{
		if (!isEmpty)
			sort(Album, Album + N);
		int a;
		cin >> a;

		for (int j = 0; j < N; j++)
		{
			if (Album[j].second == NULL)// 앨범이 비어있다면
			{
				Album[j].first.second = i;
				Album[j].first.first = 1;
				Album[j].second = a;
				count += 1;
				if (count == N)
					isEmpty = false;
				break;
			}
			if (Album[j].second == a)
			{
				Album[j].first.second = i;
				Album[j].first.first += 1;
				break;
			}
			if (j == N - 1 && !isEmpty) {
				Album[0].second = a;
				Album[0].first.first = 1;
				Album[0].first.second = i;
			}
		}
	}

	for (int i = 0; i < count; i++)
	{
		Ans[i] = Album[i].second;

	}
	sort(Ans, Ans + (count));

	for (int i = 0; i < count; i++)
		cout << Ans[i] << " ";


}