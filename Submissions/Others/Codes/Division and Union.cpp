#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int l[n + 1], r[n + 1];
  vector<int> a;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    a.push_back(l[i]);
    a.push_back(r[i]);
  }
  vector<int> v = a;
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  
  int nn = n + n + 10, d[nn + 1];
  memset(d, 0, sizeof d);
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    l[i] = lower_bound(v.begin(), v.end(), l[i]) - v.begin() + 1;
    r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin() + 1;
    d[l[i]]++;
    d[r[i] + 1]--;
    mp[l[i]]++;
    // cout << l[i] << ' ' << r[i] << '\n';
  }
  int brk_point = -1;
  for (int i = 1; i <= nn; i++) {
    d[i] += d[i - 1];
    // cout << d[i] << ' '; 
    if (i != 1 and mp.find(i) != mp.end() and mp[i] == d[i]) {
      brk_point = i;
      // cout << brk_point << "here\n";
      break;
    } 
  }
  if (brk_point == -1) {
    cout << -1 << '\n';
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (r[i] < brk_point) cout << 1 << ' ';
    else cout << 2 << ' ';
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