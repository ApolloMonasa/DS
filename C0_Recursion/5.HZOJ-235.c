#include<stdio.h>
#include<stdlib.h>

void f(int i, int j, int n, int *a){
    for(int k = 0; k<i; k++){
        if(k > 0) printf(" ");
        printf("%d", a[k]);
    }
    if(i > 0) printf("\n");
    if(j > n) return ;
    for(int k = j; k <= n; k++ ){
        a[i] = k;
        f(i+1, k+1, n, a);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    if(!a) {
        printf("Malloc Error\n");
        return 1;
    }

    f(0, 1, n, a);
    return 0;
}
