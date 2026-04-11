#include <iostream>
#include <cstdio>
using namespace std;

void print_result (short a, short b, short c) { 
    cout << a << " " << b << " " << c;
    return;
}

struct bc {
    short b, c; 
};

bc from_5_to_10(long int y, int  n) { 
    /*
    5b + c = y
    b + c = n 
    b: 0 -> int (y / 5)
    c: y -> y % 5
    */
    for (short b = y / 5; b > -1; b--) {
        short c = y - 5*b;
        if (b + c != n) {continue;}
        return {b, c};
    }
    return {-1,-1};
}

int main(){
    int n; cin >> n;
    long int y; cin >> y; 
    y /= 1000;
    if (y < 5) { 
        if (n > 5) {print_result(-1, -1, -1);}
        else {print_result(0, 0, y);}
    }
    else if (y >= 5 && y < 10) {
        bc b_and_c = from_5_to_10(y, n);
        short b = b_and_c.b, c = b_and_c.c;
        print_result(0, b, c);
    }

    else { 
        /*
        10a + 5b + c = y
        a + b + c = n 
        t = 5b + c
        a: 0 -> y / 10
        t: y -> y % 10
        */

        for (short a = y / 5; a > -1; a--) { 
            short t = y - a * 10;
            bc bandc = from_5_to_10(t, n - a);
            short b = bandc.b, c = bandc.c;
            if (b == -1 || c == -1) {continue;}
            print_result(a,b,c);
            return 0;
        }
        print_result(-1, -1, -1);
        return 0;
    }
    return 0;
}

//Link Problem: https://atcoder.jp/contests/abs/tasks/abc085_c

/*
g++ Otoshidama.cpp -o main.exe
@"
9 45000
"@ | ./main.exe
*/