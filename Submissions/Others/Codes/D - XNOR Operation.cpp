#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int pref_xor[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') s[i] = '1';
    else s[i] = '0';
  }

  for (int i = 1; i <= n; i++) {
    pref_xor[i] = pref_xor[i - 1] ^ (s[i] - '0');
  }

  ll ans = 0;
  map<int, int> mp;
  mp[0] = 1;

  for (int i = 1; i <= n; i++) {
    ans += mp[pref_xor[i]];
    mp[pref_xor[i]]++;
  }

  cout << ans << '\n';

  return 0;
}