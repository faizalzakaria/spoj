/**
   @author Faizal Zakaria
*/

#include <string>
#include <cstdlib>
#include <cstdio>
#include <stack>

using namespace std;

#define MAX_SIZE 512
#define sz(x) (int) (x).size()

void solve(string s) {
	stack<char> S;
	string res;
	for (int i = 0; i < sz(s); i++) {
		switch(s[i]) {
		case '(':
			break;
		case ')':
			res.push_back(S.top());
			S.pop();
			break;
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			S.push(s[i]);
			break;
		default:
			res.push_back(s[i]);
			break;
		}
	}
	printf("%s\n", res.c_str());
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		char buf[MAX_SIZE];
		scanf("%s", buf);
		solve(string(buf));
	}
}
