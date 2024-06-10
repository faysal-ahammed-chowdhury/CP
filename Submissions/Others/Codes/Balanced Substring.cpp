#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
string s;
int n, pref1[N], pref2[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  cin >> s;
  s = '.' + s;
  for (int i = 1; i <= n; i++) {
    pref1[i] += pref1[i - 1] + (s[i] == '1');
    pref2[i] += pref2[i - 1] + (s[i] == '0');
  }

  int ans = 0;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    if (pref1[i] == pref2[i]) ans = max(ans, i);
    if (mp.find(pref1[i] - pref2[i]) == mp.end()) mp[pref1[i] - pref2[i]] = i;
    else ans = max(ans, i - mp[pref1[i] - pref2[i]]);
  }
  cout << ans << '\n';

  return 0;
}