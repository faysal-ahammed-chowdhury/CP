#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x; cin >> n >> x;
  pair<int, int> a[n + 1];
  int b[n + 1];
  for (int i = 1; i <= n; i++) {
    int k; cin >> k;
    a[i] = {k, i};
  }

  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + n);
  reverse(a + 1, a + 1 + n);

  vector<int> first_x_of_b, last_par_of_b;
  for (int i = 1; i <= x; i++) {
    first_x_of_b.push_back(b[i]);
  }
  for (int i = x + 1; i <= n; i++) {
    last_par_of_b.push_back(b[i]);
  }
  sort(first_x_of_b.rbegin(), first_x_of_b.rend());
  sort(last_par_of_b.rbegin(), last_par_of_b.rend());

  int ans[n + 1];
  for (int i = 1; i <= x; i++) {
    int val = a[i].first, idx = a[i].second;
    int ans_for_val = first_x_of_b[i - 1];
    if (ans_for_val >= val) {
      cout << "NO\n";
      return;
    }
    ans[idx] = ans_for_val;
  }

  int here = 0;
  for (int i = x + 1; i <= n; i++) {
    int val = a[i].first, idx = a[i].second;
    int ans_for_val = last_par_of_b[here++];
    if (ans_for_val < val) {
      cout << "NO\n";
      return;
    }
    ans[idx] = ans_for_val;
  }

  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}