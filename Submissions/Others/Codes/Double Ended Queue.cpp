#include <bits/stdc++.h>
using namespace std;

int cs;
void solve() {
  int n, m; cin >> n >> m;
  deque<int> dq;
  cout << "Case " << ++cs << ":\n";
  while (m--) {
    string s; cin >> s;
    if (s == "pushLeft") {
      int x; cin >> x;
      if (dq.size() == n) {
        cout << "The queue is full\n";
      }
      else {
        dq.push_front(x);
        cout << "Pushed in left: " << x << '\n';
      }
    }
    else if (s == "pushRight") {
      int x; cin >> x;
      if (dq.size() == n) {
        cout << "The queue is full\n";
      }
      else {
        dq.push_back(x);
        cout << "Pushed in right: " << x << '\n';
      }
    }
    else if (s == "popLeft") {
      if (dq.size() == 0) {
        cout << "The queue is empty\n";
      }
      else {
        cout << "Popped from left: " << dq.front() << '\n';
        dq.pop_front();
      }
    }
    else {
      if (dq.size() == 0) {
        cout << "The queue is empty\n";
      }
      else {
        cout << "Popped from right: " << dq.back() << '\n';
        dq.pop_back();
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}