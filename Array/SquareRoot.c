#include <stdio.h>
#include <stdlib.h>

double squareRoot(int num) {
    int start = 0;
    int end = num;
    while(start < end) {
        int mid = start + (end - start) / 2;
        if(mid*mid == num) {
            return mid;
        } else if(mid*mid > num) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    double root = 0.0;
    double incr = 0.1;
    for(int i = 0; i < 3; i++) {
        while(root*root < num) {
            root += incr;
        }
        root -= incr;
        incr /= 10;
    }
    return root;
}
int main() {
    int num = 40;
    double sqrt = squareRoot(num);
    printf("%lf", sqrt);
}
