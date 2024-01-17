#include<iostream>
using namespace std;

int main() {
    int t = 4;
    bool flag = false;
    int num, sum = 0, x = 128;

    while(t--) {
        for(int i = 0; i < 8; i++) {
            cin >> num; // one space is mandotory while giving input else the compiler will thought it is a single number and error may occur
            if(num == 1) {
                sum = sum + x;
            }
            x = x / 2;
        }

        if(t > 0) {
            flag = true;
            cout << sum << ".";
            sum = 0;
            x = 128;
        } else {
            cout << sum << " ";
        }
    }

    if(flag) {
        cout << "is the dotted IP address.";
    }

    return 0;
}
