#include <bits/stdc++.h>
using namespace std;

string number_to_str(int n) {
    stringstream ss;
    ss << n;
    string s; ss >> s;
    return s;
}

string a(int curr, int n) {
    if (curr == n) {
        string s = "sin(" + number_to_str(curr) + ")";
        return s;
    }
    char sign = curr % 2 == 0 ? '+' : '-';
    string got = a(curr + 1, n);
    string s = "sin(" + number_to_str(curr) + sign + got + ")";
    return s;
}

string s(int curr, int n) {
    if (curr == 1) {
        string s = a(1, curr) + "+" + number_to_str(n);
        return s;
    }
    string got = "(" + s(curr - 1, n + 1) + ")" + a(1, curr) + "+" + number_to_str(n);
    return got;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    cout << s(n, 1) << '\n';

    return 0;
}