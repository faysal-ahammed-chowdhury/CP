#include <bits/stdc++.h>
using namespace std;

void solve() {
    pair<int, int> point;
    point = make_pair(0, 3);
    cout << point.first << ' ' << point.second << '\n';
    pair<int, int> p1, p2;
    p1 = make_pair(0, 3);
    p2 = make_pair(1, 5);
    swap(p1, p2);
    cout << p1.first << ' ' << p1.second << '\n';

    pair<int, int> points[10]; // array of pairs
    pair<string, int> you = make_pair("faysal", 22490463);
    pair<pair<int, int>, int> x = make_pair(make_pair(0, 1), 2);
    cout << x.first.first << ' ' << x.first.second << ' ' << x.second << '\n';

    pair<int, int> y;
    cin >> y.first >> y.second;
    cout << y.first + y.second << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}