/**
   @author Faizal Zakaria
*/

#include <string>
#include <cstdlib>
#include <cstdio>
#include <sstream>

using namespace std;

#define sz(x) (int) (x).size()

inline int reverse(int x) {
    ostringstream oss;
    oss << x;
    string s = oss.str();

    int i = 0;
    int j = sz(s) - 1;
    while (i < j) swap(s[i++], s[j--]);
    return atoi(s.c_str());
}

inline int solve(int x1, int x2) {
    return reverse(revers(ehowx1) + reverse(x2));
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int x1, x2;
        scanf("%d%d", &x1, &x2);
        printf("%d\n", solve(x1, x2));
    }

}
