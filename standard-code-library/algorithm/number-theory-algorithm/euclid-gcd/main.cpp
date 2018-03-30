/**--------------------
 * Euclid Greatest Common Divisor Algorithm
 *
 * Time Consumption: \log{N}
 * Mem Consumption: \log{N} (on stack)
 * Author: cjsoft
 * Date: 2018/01/28
 * --------------------
 */

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
