#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;

  vector<int> zero, one;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') zero.push_back(i);
    else one.push_back(i);
  }

  if (zero.size() == n) {
    cout << 0 << '\n';
    return;
  }

  int idx = -1;
  for (int i = 1; i <= n; i++) {
    int here = (i & 1) ? i : n - i;
    if (here == zero.size()) {
      idx = i;
      break;
    }
  }

  cout << idx << '\n';
  if (idx == -1) return;
  for (int i = 1; i <= idx; i++) {
    if (idx & 1) cout << zero[i - 1] << ' ';
    else cout << one[i - 1] << ' ';
  }
  cout << '\n';
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