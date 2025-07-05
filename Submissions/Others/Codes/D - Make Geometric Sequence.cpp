#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double eps = 1e-9;

bool f(vector<int> &a) {
  int n = a.size();
  for (int i = 1; i + 1 < n; i++) {
    if (a[i] * a[i] != a[i + 1] * a[i - 1]) {
      return false;
    }
  }
  return true;
}

void solve() {
  int n; cin >> n;
  int a[n + 1];
  int neg = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    neg += a[i] < 0;
  }
  sort(a + 1, a + n + 1);

  int pos = n - neg;
  if (abs(pos - neg) <= 1) {
    vector<int> v1, v2;
    for (int i = 1; i <= n; i++) {
      if (a[i] < 0) v1.push_back(a[i]);
      else v2.push_back(a[i]);
    }

    reverse(v1.begin(), v1.end());

    if (pos >= neg) {
      vector<int> v;
      for (int i = 0; i < pos; i++) {
        v.push_back(v2[i]);
        if (i < neg) v.push_back(v1[i]);
      }
      if (v.size() == n and f(v)) {
        cout << "Yes\n";
        return;
      }
    }
    if (neg >= pos) {
      vector<int> v;
      for (int i = 0; i < neg; i++) {
        v.push_back(v1[i]);
        if (i < pos) v.push_back(v2[i]);
      }
      if (v.size() == n and f(v)) {
        cout << "Yes\n";
        return;
      }
    }
  }

  vector<int> v;
  for (int i = 1; i <= n; i++) {
    v.push_back(a[i]);
  }

  if (f(v)) cout << "Yes\n";
  else cout << "No\n";
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