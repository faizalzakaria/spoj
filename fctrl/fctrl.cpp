/**
   @author Faizal Zakaria
*/

#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

int calc(int n) {
	
	int cnt = 0;
	int cur = n;
	while (cur) {
		cur = cur / 5;
		cnt += cur;
	}
	return cnt;
}

int main() {

	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", calc(n));
	}

}
