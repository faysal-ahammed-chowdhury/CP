#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;
  map<int, int> freq;
  for (auto c : s) {
    freq[c]++;
  }
  int ans = 1;
  for (auto [c, cnt] : freq) {
    ans = 1ll * ans * (cnt + 1) % mod;
  }
  --ans;
  if (ans < 0) ans += mod;
  cout << ans << '\n';

  return 0;
}