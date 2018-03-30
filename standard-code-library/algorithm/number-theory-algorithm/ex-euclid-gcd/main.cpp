/**--------------------
 * Extended Euclid Greatest Common Divisor Algorithm
 *
 * Time Consumption: \log{N}
 * Mem Consumption: \log{N} (on stack)
 * Author: cjsoft
 * Date: 2018/01/28
 * --------------------
 */

int exgcd(int a, int b, int &x, int &y) {
    if (b) {
        int r = exgcd(b, a % b, y, x);
        y -= x * (a / b);
        return r;
    } else {
        x = 1; y = 0;
        return a;
    }
}
