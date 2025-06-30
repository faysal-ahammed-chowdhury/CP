#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1], b[n + 1];
  int sorted_a[n + 1], sorted_b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sorted_a[i] = a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    sorted_b[i] = b[i];
  }
  sort(sorted_a + 1, sorted_a + n + 1);
  sort(sorted_b + 1, sorted_b + n + 1);

  vector<pair<int, int>> v;
  for (int i = 1; i <= n; i++) {
    int idx = -1;
    for (int j = 1; j <= n; j++) {
      if (sorted_a[i] == a[j]) {
        idx = j;
        break;
      }
    }

    for (int j = idx; j > i; j--) {
      v.push_back({1, j - 1});
      swap(a[j], a[j - 1]);
    }
  }

  for (int i = 1; i <= n; i++) {
    int idx = -1;
    for (int j = 1; j <= n; j++) {
      if (sorted_b[i] == b[j]) {
        idx = j;
        break;
      }
    }

    for (int j = idx; j > i; j--) {
      v.push_back({2, j - 1});
      swap(b[j], b[j - 1]);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (a[i] > b[i]) {
      swap(a[i], b[i]);
      v.push_back({3, i});
    }
  }

  for (int i = 1; i < n; i++) {
    assert(a[i] < a[i + 1]);
    assert(b[i] < b[i + 1]);
    assert(a[i] < b[i]);
  }

  assert(v.size() <= 1709);
  cout << v.size() << '\n';
  for (auto [t, i] : v) {
    cout << t << ' ' << i << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}