#include <bits/stdc++.h>
using namespace std;

#define int long long
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      v.push_back(a[i] * a[j]);
    }
  }
  sort(v.begin(), v.end());
  for (auto x : v) {
    cout << x << '\n';
  }

  return 0;
}