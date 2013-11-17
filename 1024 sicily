#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
struct Road {
    int linknode;
    int distance;
    Road(int t, int d) {linknode = t; distance = d;}
};
int mx;
bool visited[10001];
stack<Road> road[10001];
void DFS(int n, int dist) {
    bool deeper = false;
    while (!road[n].empty()) {
    	Road* it = &road[n].top();
        if (!visited[it->linknode]) {
            visited[it->linknode] = true;
            deeper = true;
            DFS(it->linknode, dist + it->distance);
        }
        road[n].pop();
    }
    if ( !deeper && dist > mx )
        mx = dist;
}
int main()
{
    int N, K;
    int X, Y, D;
    while (scanf( "%d%d", &N, &K) != EOF) {
        for (int i = 1; i < N; i++) {
            scanf("%d%d%d", &X, &Y, &D);
            road[X].push(Road(Y, D));
            road[Y].push(Road(X, D));
        }
        mx = 0;
        memset(visited, false, sizeof(visited));
        visited[K] = true;
		DFS(K,0);
		while(!road[K].empty()) {
			road[K].pop();}
        printf("%d\n", mx);
    }
    return 0;
}
