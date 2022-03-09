#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

#define INF 987654321

int N, M, K,p, d;
int capa[2005][2005];
vector< int> edge[2005]; //nextnode
int prev_node[2005];
bool used[2005];
int S,E;

int BFS() {
	queue<int> q;//curnode
	q.push(S);
	memset(used, 0, sizeof(used));
	used[S] = true;
	
	while (!q.empty()) {
		int cur_node = q.front();
		q.pop();
		for (int i=0; i<edge[cur_node].size(); ++i){
		
			int next_node = edge[cur_node][i];
			if (used[next_node]) continue;
			if (capa[cur_node][next_node] <=0) continue;
			used[next_node] = true;
			prev_node[next_node] = cur_node;
			q.push(next_node);

		}
	}
	return used[E];
}

int DFS(int cur=E, int max_flow = INF) {
	if (cur == S) return max_flow;

	int prev = prev_node[cur];
	max_flow = DFS(prev, max_flow > capa[prev][cur] ? capa[prev][cur] : max_flow);
	capa[prev][cur] -= max_flow;
	capa[cur][prev] += max_flow;

	return max_flow;
}

int main() {
	scanf("%d %d %d\n", &N, &M, &K);
	S = (N+M) + 1; // [start] -> [0] -> [1],2345 -> [1000+1,2,3,4] -> end
	E = (N+M) + 2;	// and [start] -> [12345] -> [1000+1,2,3,4] -> end
	capa[S][0] = K;
	edge[S].push_back(0);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &p);
		for (int j = 0; j < p; ++j) {
			scanf("%d", &d);
				//´Ü¹æÇâ
			capa[i][d+N] = INF;
			edge[i].push_back(d + N);
			edge[d+N].push_back(i);
		}
		capa[0][i] = INF;
		edge[0].push_back(i);
		edge[i].push_back(0);
		capa[S][i] = 1;
		edge[S].push_back(i);
		edge[i].push_back(S);
	}
	for (int i = 1; i <= M; ++i) {
		capa[N + i][E] = 1;
		edge[N + i].push_back(E);
	}
	int ans = 0;
	while (BFS()) {
		ans += DFS();
	}
	printf("%d\n", ans);

}