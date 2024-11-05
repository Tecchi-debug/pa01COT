#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
typedef long long ll;

#define MAX 2000 // Adjust based on maximum possible total steps
// Will store Pascal's Triangle here.
long long combo[MAX+1][MAX+1];

void initPascalTriangle() {

    // Put in 1s
    for (int i=0; i<=MAX; i++) {
        combo[i][0] = 1;
        combo[i][i] = 1;
    }
    // Fills in triangle.
    for (int i=2; i<=MAX; i++)
        for (int j=1; j<i; j++)
            combo[i][j] = (combo[i-1][j-1]+combo[i-1][j])%MOD;
}

void visitPath(int *x, int *y, int numLoc) {
    
    ll paths = 1;

    for (int i = numLoc; i >= 0; i--) {
        int totalSteps = (x[i + 1] - x[i]) + (y[i + 1] - y[i]);
        ll segmentPaths = combo[totalSteps][x[i + 1] - x[i]];
        paths = (paths * segmentPaths) % MOD;
    }

    printf("%lld\n", paths);
}

void bullyPath(int *x, int *y, int n) {
    
}

int main() {
    initPascalTriangle(); // Initialize Pascal's Triangle

    int xs, ys, query, type, numLoc;
    printf("xs ys\n");
    scanf("%d %d", &xs, &ys);
    printf("Queries\n");
    scanf(" %d", &query);

    for (int i = 0; i < query; i++) {
        printf("Type\n");
        scanf("%d", &type);
        printf("Num Locations\n");
        scanf("%d", &numLoc);

        int *x = malloc(sizeof(int) * (numLoc + 2));
        int *y = malloc(sizeof(int) * (numLoc + 2));

        x[0] = 0;
        y[0] = 0;

        for (int j = 1; j <= numLoc; j++) {
            printf("[%d] (x,y)\n", j);
            scanf("%d %d", &x[j], &y[j]);
        }

        x[numLoc + 1] = xs;
        y[numLoc + 1] = ys;

        if (type == 1) visitPath(x, y, numLoc);
        else bullyPath(x, y, numLoc);

        free(x);
        free(y);


        return 0;
    }
}

