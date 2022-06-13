#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
#define GO 1
#define water 0

/*
BFS
1. 큐에 시작점 넣음
2. 큐에서 하나 빼옴
3. 목적지?
4. 가능항목 모두 넣으면서 체크인
*/

queue <pair <pair <int, int>, int>> q;// {{y,x} , 고슴도치 or 물}
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int R, C;

char map[52][52];
int visited[52][52];

int bfs() {
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int identity = q.front().second;
		q.pop();
		//deque
		if (identity == GO)// 고슴도치
		{
			for (int i = 0; i < 4; i++) //4 방향 움직임
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < C && ny >= 0 && ny < R) //맵내에서
				{
					if (map[ny][nx] == '.' && visited[ny][nx] == 0)//물도고슴도치도없었으면ㄱㄱ
					{
						visited[ny][nx] = visited[y][x] + 1;
						q.push({ {ny, nx} , GO });
					}
					else if (map[ny][nx] == 'D') // 도차쿠
					{
						visited[ny][nx] = visited[y][x] + 1;
						return visited[ny][nx];
					}
				}
			}
		}
		else // 물
		{
			for (int i = 0; i < 4; i++) //4 방향 움직임
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < C && ny >= 0 && ny < R) //맵내에서
				{
					if (map[ny][nx] == '.' || map[ny][nx] == 'S')// 물 닿을데는 다 뒤집기
					{
						map[ny][nx] = '*';
						q.push({ { ny, nx } , water });
					}

				}
			}
		}
	}
	return -1;
}
int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == '*')
			{
				q.push({ {i,j},water });
			}
		}
	}// 입력
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (map[i][j] == 'S') {
				q.push({ {i,j}, GO });
				break;
			}
		}
	}

	int result = bfs();
	if (result > 0)
		cout << result;
	else
		cout << "KAKTUS";

	return 0;
}

