#include <stdio.h>
#include <stdlib.h>

#define MAX_M 200000

typedef struct {
    int x;
    long long a;
} Cell;

int compare(const void *a, const void *b) {
    Cell *cellA = (Cell *)a;
    Cell *cellB = (Cell *)b;
    return cellA->x - cellB->x;
}

long long minOperations(int N, int M, Cell cells[]) {
    long long totalStones = 0;
    for (int i = 0; i < M; i++) {
        totalStones += cells[i].a;
    }
    if (totalStones != N) {
        return -1;
    }

    qsort(cells, M, sizeof(Cell), compare);

    long long operations = 0;
    long long currentStones = 0;
    int target = 1;

    for (int i = 0; i < M; i++) {
        long long needed = cells[i].x - target + 1;
        if (currentStones + cells[i].a < needed) {
            return -1;
        }
        operations += cells[i].a * (cells[i].x - target);
        currentStones += cells[i].a - needed;
        target += needed;
    }

    return operations;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    Cell cells[MAX_M];
    for (int i = 0; i < M; i++) {
        scanf("%d %lld", &cells[i].x, &cells[i].a);
    }

    long long result = minOperations(N, M, cells);
    printf("%lld\n", result);

    return 0;
}
