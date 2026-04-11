#include <iostream>
#include <cstdio>
using namespace std;
bool is_sum_btw_a_b(int n, int a, int b){
    short sum = 0;
    while (n > 0){        
        sum += n % 10;
        n /= 10;
    }
    if (sum < a || sum > b) {return false;}
    return true;
}
int main(){
    int n; cin >> n;
    short a, b; cin >> a >> b;
    int result = 0;
    for (int i = 0; i < n + 1; i++){
        if (!is_sum_btw_a_b(i, a, b)) continue;
        result += i;
    }
    cout << result;
    return 0;
}

//Link Problem: https://atcoder.jp/contests/abs/tasks/abc083_b
/*
g++ Some_Sums.cpp -o main.exe
@"
20 2 5
"@ | ./main.exe
*/