/**
   @author Faizal Zakaria
*/

#include <cstdlib>
#include <cstdio>

using namespace std;

bool isValid(int x, int y) {
	return (x == y) || ((x - 2) == y);
}

void solve(int x, int y) {
	if (!isValid(x, y)) {
		printf("No Number\n");
		return;
	}

	int res = 0;
	if (x % 2) res = x + y - 1;
	else res = x + y;
		
	printf("%d\n", res);
}

int main() {

	int T;
	scanf("%d", &T);
	while (T--) {
		int x, y;
		scanf("%d%d", &x, &y);
		solve(x, y);
	}

}

