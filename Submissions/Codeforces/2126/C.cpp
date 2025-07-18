#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    if (a[i] >= a[k]) v.push_back(a[i]);
  }

  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());

  int sz = v.size();
  int time = 0, water = 1;
  for (int i = 0; i + 1 < sz; i++) {
    int need = abs(v[i] - v[i + 1]);
    time += need;
    water += need;
    if (water > v[i] + 1) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
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