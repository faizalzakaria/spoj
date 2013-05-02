/**
   @author Faizal Zakaria
*/

#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_SIZE 202
#define sz(x) (int) (x).size()

enum DIRECTION {
	RIGHT = 1,
	LEFT,
	DOWN
};

void solve(string s, int col) {
	int n = sz(s);
	int row = double(n) / col + 0.5;
	char R[row][col];
	memset(R, 0, row * col);

	int cr = 0, cc = 0;
	int direction = RIGHT;
	for (int i = 0; i < n; i++) {
		R[cr][cc] = s[i];

		if (direction == RIGHT)
			cc++;
		else if (direction == LEFT)
			cc--;

		if (cc >= col) {
			cr++;
			cc--;
			direction = LEFT;
		} else if (cc < 0) {
			cr++;
			cc++;
			direction = RIGHT;
		}
	}

	for (int j = 0; j < col; j++) {
		for (int i = 0; i < row; i++) {
			if (R[i][j] == 0) continue;
			printf("%c", R[i][j]);
		}
	}
	printf("\n");
}

int main() {
	
	int col;
	while (1) {
		scanf("%d", &col);
		if (!col) break;
		char buf[MAX_SIZE];
		scanf("%s", buf);
		solve(string(buf), col);
	}
}
