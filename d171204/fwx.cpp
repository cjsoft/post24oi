#include <stdio.h>
#include <math.h>
int main() {
    double eps;
    double sum = 0;
    scanf("%lf", &eps);
    double r = 1;
    for (int i = 1; fabs(r) > eps; i += 3) {
        if ((i / 3) % 2 == 0) {
            sum += 1.0 / i;
        } else {
            sum -= 1.0 / i;
        }
        r = 1.0 / i;
    }
    printf("sum = %.6lf\n", sum);
}