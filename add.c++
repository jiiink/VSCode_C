#include <iostream>
using namespace std;

int main() {
    float a = 0xD0B10301;
    float b = 0xD1B43203;
    // int c = 0b0101;
    // cout << a << endl;
    // cout << a + b << endl;
    printf("a : %0x\n", a);
    printf("a + b : %0x\n", a+b);
    // printf("%x\n", c);

    return 0;
}