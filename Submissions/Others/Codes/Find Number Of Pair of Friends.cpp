#include <bits/stdc++.h>
using namespace std;

#define int long long
bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

void solve() {
  int n; cin >> n;
  map<int, int> cnt;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    int x = 0;
    for (auto c : s) {
      SET(x, c - '0');
    }
    cnt[x]++;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
  int ans = 0;
  n = v.size();
  for (int i = 0; i < n; i++) {
    ans += (cnt[v[i]] * (cnt[v[i]] - 1)) / 2;
    for (int j = i + 1; j < n; j++) {
      int x = v[i] & v[j];
      if (x) {
        ans += cnt[v[i]] * cnt[v[j]]; 
      }
    }
  }
  cout << ans << '\n';
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