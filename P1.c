#include <stdio.h>
#include <stdlib.h>


#define MOD 100000007
#define MAX_LETTERS 100

// Function to calculate factorial of a number
unsigned long long factorial(int n) {
    if (n == 1 || n == 0) return 1;
    return n * factorial(n - 1);
}

// Function to calculate the number of combinations (nCr)
unsigned long long combinations(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Function to calculate the number of paths from (0, 0) to (x, y)
int paths(int xInit, int yInit, int x, int y) {
    if (xInit > x || yInit > y) return 0;
    if (xInit == x && yInit == y) return 1;

    return paths(xInit + 1, yInit, x, y) + paths(xInit, yInit + 1, x, y);
}

int main() {
    long long numPaths = 0;
    int n, xs, ys, x, y;
    printf("How many friends are you picking up?\n");
    scanf("%d", &n);

    printf("Where is School (x, y)");
    scanf("%d %d", &xs, &ys);
    if (n == 0) {
        numPaths = paths(0,0,xs,ys);
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("Starting at home (0, 0)");
            printf("friend to pick up at (x y): ");
            scanf("%d %d", &x, &y);
            numPaths = paths(0,0,x,y);
        } else {
            printf("friend to pick up at (x y): ");
            scanf("%d %d", &x, &y);
            numPaths = paths(x,y,xs,ys);
        }
    }
    if (n != 0 && x != xs && y != ys) {
        numPaths *= paths(x,y,xs,ys);
    }
    printf("%lld\n", numPaths);

    return 0;
}
