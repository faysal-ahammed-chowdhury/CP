#include <bits/stdc++.h>
using namespace std;

int f(string s) {
  int n = s.size();
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') continue;
    for (int j = i + 1; j < n; j++) {
      ans += s[j] == '1';
    }
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < (1 << n); i++) {
    bitset<4> bs(i);
    string s = bs.to_string();
    cout << s << ' ' << f(s) << '\n';
  }

  return 0;
}