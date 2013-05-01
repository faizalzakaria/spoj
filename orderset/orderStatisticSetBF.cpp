/**
   @author Faizal Zakaria
   // Brute force solution
*/

#include <set>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_VALUE 200000

int main() {
    int Q = 0;
    set<int> S;
    scanf("%d", &Q);
    while (Q--) {
        char op[32];
        int p1;
        scanf("%s %d", op, &p1);
        if (!strcmp(op, "I")) {
            S.insert(p1);
        } else if (!strcmp(op, "D")) {
            set<int>::iterator it = S.find(p1);
            if (it != S.end()) S.erase(it);
        } else if (!strcmp(op, "K")) {
            if (p1 > (int) S.size())
                printf("invalid\n");
            else {
                int i = 0;
                set<int>::iterator it = S.begin();
                while (i < (p1 -1)) {
                    it++;
                    i++;
                }
                printf("%d\n", *it);
            }
        } else if (!strcmp(op, "C")) {
            int i = 0;
            for (set<int>::iterator it = S.begin(); it != S.end(); it++) {
                if (*it >= p1) break;
                i++;
            }
            printf("%d\n", i);
        }
    }
}

