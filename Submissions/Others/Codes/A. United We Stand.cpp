#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> a(n + 1), b, c;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int mx = *max_element(a.begin() + 1, a.end());
    int mn = *min_element(a.begin() + 1, a.end());
    if(mx == mn) {
      cout << -1 << '\n';
      continue;
    }
    for(int i = 1; i <= n; i++) {
      if(a[i] == mx) {
        c.push_back(a[i]);
      }
      else {
        b.push_back(a[i]);
      }
    }
    cout << b.size() << ' ' << c.size() << '\n';
    for(auto i: b) {
      cout << i << ' ';
    }
    cout << '\n';
    for(auto i: c) {
      cout << i << ' ';
    }
    cout << '\n';
  }

  return 0;
}