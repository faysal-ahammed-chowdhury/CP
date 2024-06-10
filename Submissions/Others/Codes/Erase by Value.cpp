#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }

  if (is_sorted(a.begin(), a.end())) {
    int last = a.back();
    while (!a.empty() and a.back() == last) {
      a.pop_back();
    }
    for (auto x : a) {
      cout << x << ' ';
    }
    cout << '\n';
  }
  else {
    int x = -1;
    for (int i = 1; i < n; i++) {
      if (a[i - 1] > a[i]) {
        x = a[i - 1];
        break;
      }
    }

    for (auto y : a) {
      if (x == y) continue;
      cout << y << ' ';
    }
    cout << '\n';
  }


  return 0;
}