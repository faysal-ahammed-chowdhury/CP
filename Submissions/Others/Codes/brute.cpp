#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int n, a[N], ans;

void f(int i, int last, vector<int> &v) {
  if (i > n + 1) {
    if (v.size() > 0) {
      for (auto x : v) {
        cout << x << ' ';
      }
      cout << '\n';
      ans++;
    }
    return;
  }
  f(i + 1, last, v);
  if (a[i] > last) {
    v.push_back(a[i]);
    f(i + 1, a[i], v);
    v.pop_back();
  }
}

int cs;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  ans = 0;
  vector<int> v;
  f(1, -1, v);
  cout << "Case " << ++cs << ": " << ans << '\n';
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