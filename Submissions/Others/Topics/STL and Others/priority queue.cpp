#include <bits/stdc++.h>
using namespace std;

int get_len(int n) {
    n = abs(n);
    int len = 0;
    while(n > 0) {
        n /= 10;
        len++;
    }
    return len;
}

struct cmp {
  bool operator()(int a, int b) const {
    return get_len(a) > get_len(b); // comparing by length
  }
};

void solve() {
    priority_queue<int> q;
    q.push(2);
    q.push(4);
    q.push(3);
    cout << q.top() << '\n';
    q.pop();
    cout << q.top() << '\n';
    cout << q.size() << '\n';
    cout << q.empty() << '\n';
    priority_queue<int, vector<int>, greater<int>> minq;
    minq.push(4);
    minq.push(2);
    minq.push(3);
    cout << minq.top() << '\n';

    priority_queue<int, vector<int>, cmp> customq;
    customq.push(2);
    customq.push(-41);
    customq.push(333);
    while(!customq.empty()) {
        cout << customq.top() << ' ';
        customq.pop();
    }
    cout << '\n';

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