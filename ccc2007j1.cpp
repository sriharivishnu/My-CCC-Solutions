//Solution by Srihari Vishnu
//CCC 2007 J1 : Who is in the Middle?

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
int arr[3];
int main() {
    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+3);
    cout << arr[1];
}
