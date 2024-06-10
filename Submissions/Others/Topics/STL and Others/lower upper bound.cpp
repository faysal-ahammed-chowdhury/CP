#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x; n = 7, x = 2;
    vector<int> v({ 1, 3, 3, 3, 4, 5 });

    auto lower = lower_bound(v.begin(), v.end(), x);
    cout << *lower << '\n';
    cout << "Index: " << lower - v.begin() << '\n'; // return first index of 2 (if 2 is not exist then return immediate greater number than 2)

    x = 3;

    auto upper = upper_bound(v.begin(), v.end(), x);
    cout << *upper << '\n';
    cout << "Index: " << upper - v.begin() << '\n'; // return immediate grater number than 3

    return 0;
}