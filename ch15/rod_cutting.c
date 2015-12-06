#include <stdio.h>
#include <stdlib.h>

#define N 10
int prices[N] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

int best_price[N];
int rod_cut_price_bottom_up(int n){
    //best_price[n] = max(price[i] + best_price[n-i], for 1 <= i <= n)
    for (int i=0; i < n; i++){
        best_price[i] = prices[i];
        for (int j=0; j < i; j++){
            if (prices[j] + best_price[i-j-1] > best_price[i]){
                best_price[i] = prices[j] + best_price[i-j-1];
            }
        }
    }
    return best_price[n-1];
}

int main(int argc, char *argv[]){
    for (int i=1; i<=10; i++){
        printf("i=%d: %d, %d\n", i, prices[i-1], rod_cut_price_bottom_up(i));
    }
    return 0;
}
