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
1. ť�� ������ ����
2. ť���� �ϳ� ����
3. ������?
4. �����׸� ��� �����鼭 üũ��
*/

queue <pair <pair <int, int>, int>> q;// {{y,x} , ����ġ or ��}
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
		if (identity == GO)// ����ġ
		{
			for (int i = 0; i < 4; i++) //4 ���� ������
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < C && ny >= 0 && ny < R) //�ʳ�����
				{
					if (map[ny][nx] == '.' && visited[ny][nx] == 0)//��������ġ���������餡��
					{
						visited[ny][nx] = visited[y][x] + 1;
						q.push({ {ny, nx} , GO });
					}
					else if (map[ny][nx] == 'D') // ������
					{
						visited[ny][nx] = visited[y][x] + 1;
						return visited[ny][nx];
					}
				}
			}
		}
		else // ��
		{
			for (int i = 0; i < 4; i++) //4 ���� ������
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < C && ny >= 0 && ny < R) //�ʳ�����
				{
					if (map[ny][nx] == '.' || map[ny][nx] == 'S')// �� �������� �� ������
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
	}// �Է�
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

