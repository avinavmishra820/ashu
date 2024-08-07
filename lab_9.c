#include <stdio.h>
#include <time.h>

double clk;
clock_t starttime, endtime;

int min(int a, int b) {
    return (a < b) ? a : b;
}

void floyd(int n, int W[10][10], int D[10][10]) {
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            D[i][j] = W[i][j];
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
}

int main(void) {
    int i, j, n, D[10][10], W[10][10];
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &W[i][j]);
    
    starttime = clock();
    floyd(n, W, D);
    endtime = clock();
    
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("All pairs shortest path matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", D[i][j]);
        }
        printf("\n");
    }
    printf("\nThe runtime is %f seconds\n", clk);
    
    return 0;
}

