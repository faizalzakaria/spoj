/**
   @author Faizal Zakaria
*/

#include <string>
#include <cstdlib>
#include <cstdio>
#include <sstream>

using namespace std;

#define MAX_N 200010
#define MAX_SIZE 2
#define MOD 1000

int parentL[MAX_N];
int dist[MAX_N];

void printDist(int N) {
	for (int i = 1; i <= N; i++) {
		printf("%d : %d == %d\n", i, dist[i], parentL[i]);
	}
}

inline void init() {
	for (int i = 0; i < MAX_N; i++) {
		parentL[i] = i;
		dist[i] = 0;
	}
}

void unionT(int x, int y) {
	parentL[x] = y;
	dist[x] = abs(x - y) % MOD;
}

int findP(int x) {
	if (parentL[x] != x) {
		int p = parentL[x];
		parentL[x] = findP(p);
		dist[x] += dist[p];
	}
	return parentL[x];
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int N;
		char buf[MAX_SIZE];
		bool run = true;
		init();
		scanf("%d", &N);

		while (run) {
			scanf("%s", buf);
			
			switch (buf[0]) {
			case 'O':
				run = false;
				break;
			case 'I':
			{
				int x, y;
				scanf("%d%d", &x, &y);
				unionT(x, y);
				break;
			}
			case 'E':
			{
				int x;
				scanf("%d", &x);
				findP(x);
				printf("%d\n", dist[x]);
				break;
			}
			default:
				break;
			}
		}
	}
}
