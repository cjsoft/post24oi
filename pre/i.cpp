#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MXN 50007
struct Stack {
    int data[MXN];
    int size;
    Stack() { memset(data, 0, sizeof(data)); size = 0; }
    int peak() {
        if (size) return data[size - 1];
        if (size < 0) puts("WARN");
        return -1;
    }
    void pop() { size--; }
    void push(int x) { data[size++] = x; }
} stk;
bool ptag = false;
struct operation {
    int opcode;
    int data;
    int timestamp;
    bool operator<(const operation &b) const {
        return timestamp < b.timestamp;
    }
    void perform() {
        switch (opcode) {
            case 0:
            stk.push(data);
            break;
            case 1:
            stk.pop();
            break;
            case 2:
            if (!ptag) printf("%d\n", stk.peak());
            ptag = true;
        }
    }
}
using namespace std;

int main() {

}