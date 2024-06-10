#include <bits/stdc++.h>
using namespace std;

int cs = 0;
void solve() {
  string s; cin >> s;
  int d; cin >> d;

  int ans = 0;
  sort(s.begin(), s.end());
  do {
    long long n = 0;
    for (auto c : s) {
      n = (n * 10) + (c - '0');
    }
    if (n % d == 0) ans++;
  } while (next_permutation(s.begin(), s.end()));

  cout << "Case " << ++cs << ": ";
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}