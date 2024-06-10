#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1], b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  map<int, int> freq;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    freq[b[i]]++;
  }
  set<int> se;
  for (int j = 1; j <= n; j++) {
    int xr = a[1] ^ b[j];
    map<int, int> freq_tmp;
    for (int i = 1; i <= n; i++) {
      freq_tmp[a[i] ^ xr]++;
    }
    if (freq == freq_tmp) se.insert(xr);
  }
  cout << se.size() << '\n';
  for (auto x : se) cout << x << '\n';

  return 0;
}