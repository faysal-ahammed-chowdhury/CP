#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

int a, b;

void assign() {
    a = 10; b = 20;
}

void print() {
    cout << "a: " << a << ", b: " << b << '\n';
}

void my_swap() {
    a = a + b;
    b = a - b;
    a = a - b;
}

void solve() {
    assign();
    print();
    swap(a, b); // swap a and b
    print();
    assign();
    my_swap(); // my swap function to swap to int
    print();
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