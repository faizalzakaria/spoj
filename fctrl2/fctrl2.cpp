/**
   @author Faizal Zakaria
*/

#include <string>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <sstream>

using namespace std;

#define MAX_N 102
#define sz(x) (int) (x).size()
#define MOD 10
#define MAX_SIZE 200

typedef long long unsigned uint64;

struct imba_int {
	short val[MAX_SIZE];
	int l;
	int length() { return l; }

	void multp(int p) {
		if (p > 100) return;
		int c = 0;
		for (int i = 0; i < l; i++) {
			int a = (val[i] * p) + c;
			val[i] = a % MOD;
			c = a / MOD;
		}
		
		while (c > 0) {
			val[l] += c;
			c = val[l] / MOD;
			val[l] %= MOD;
			l++;
		}
	}

	string toString() {
		ostringstream oss;
		for (int i = (l - 1); i >= 0; i--) {
			oss << val[i];
		}
		return oss.str();
	}

	imba_int() : l(0) {
		for (int i = 0; i < MAX_SIZE; i++) {
			val[i] = 0;
		}
	}
};

void calc(int n) {
	imba_int v;
	v.val[0] = 1;
	v.l = 1;

	for (int i = 2; i <= n; i++) {
		v.multp(i);
	}

	printf("%s\n", v.toString().c_str());
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		calc(n);
	}
}
