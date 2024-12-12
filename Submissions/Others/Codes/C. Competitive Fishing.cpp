#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int n, k, suff[N];

void solve() {
  cin >> n >> k;
  string s; cin >> s;
  s = '.' + s;

  suff[n + 1] = 0;
  vector<int> v;
  for (int i = n; i > 1; i--) {
    suff[i] = suff[i + 1] + (s[i] == '1' ? 1 : -1);
    if (suff[i] > 0) v.push_back(suff[i]);
  }

  sort(v.begin(), v.end());
  int ans = 1;
  while (k > 0 and !v.empty()) {
    k -= v.back();
    v.pop_back();
    ans++;
  }

  if (k > 0) cout << -1 << '\n';
  else cout << ans << '\n';
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