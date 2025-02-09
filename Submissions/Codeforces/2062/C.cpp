#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (auto &ai : a) {
    cin >> ai;
    sum += ai;
  }

  while (n > 1) {
    vector<int> v;
    for (int i = 1; i < n; i++) {
      v.push_back(a[i] - a[i - 1]);
    }
    int sum1 = 0;
    for (auto x : v) {
      sum1 += x;
    }
    sum = max(sum, abs(sum1));
    a = v;
    n--;
  }

  cout << sum << '\n';
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