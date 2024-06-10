#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void print_arr(int arr[]){
    for(int i = 0; i < 10; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

void solve() {
    int n = 10;
    int arr[10];
    memset(arr, -1, sizeof arr); // can make 0/1
    print_arr(arr);
    fill(arr, arr + n, 5); // fill array
    print_arr(arr);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}