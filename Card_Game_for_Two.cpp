#include <iostream>
#include <cstdio>
using namespace std; 
void merge (short* arr, short left, short mid, short right);
void mergeSort (short* arr, short left, short right);

int main(){
    short n; cin >> n;
    short nums[n]; 
    for (int i = 0; i < n; i++) { 
        cin >> nums[i];
    }

    mergeSort (nums, 0, n - 1);
    int al = 0, bb = 0;
    for (int i = 0; i < n; i += 2){
        al += nums[i];
        if (i + 1 < n){bb += nums[i + 1];}
    }
    cout << (al - bb);
    return 0;
}

void merge (short* arr, short left, short mid, short right) { 
    short n1 = mid - left + 1;
    short n2 = right - mid; 
    short L[n1], R[n2];
    for (int i = 0; i < n1; i++) { 
        L[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++){
        R[i] = arr[(mid + 1) + i];
    }

    short i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]){
            arr[k] = L[i];
            i++;
        }

        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) { 
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) { 
        arr[k] = R[j];
        j++;
        k++;
    }    
}

void mergeSort (short* arr, short left, short right) { 
    if (left >= right) return;
    short mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge (arr, left, mid, right);
}

//Link Problem:https://atcoder.jp/contests/abs/tasks/abc088_b
/*
g++ Card_Game_for_Two.cpp -o main.exe
@"
2
3 1 | ./main.exe
"@
*/