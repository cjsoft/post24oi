#include <cstdio>

struct mat {
    float _m[4][4];
    mat() {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                _m[i][j] = i * 4 + j;
            }
        }
    }
    float *operator[](int x) {
        return _m[x];
    }
};

int main() {
    mat a = mat();
    printf("%f", a[2][2]);
    return 0;
}