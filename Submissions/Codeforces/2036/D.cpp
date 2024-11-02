#include <bits/stdc++.h>
using namespace std;
#define int long long 

int n, m;
string s[1005];

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = '.' + s[i];
  }

  int ans = 0;
  int layer = min(((n + 1) / 2), ((m + 1) / 2));
  for (int cnt = 1; cnt <= layer; cnt++) {
    string tmp = "";
    int en = m - cnt + 1;
    for (int j = cnt; j <= en; j++) {
      tmp += s[cnt][j];
    }

    en = n - cnt + 1;
    for (int i = cnt + 1; i <= en; i++) {
      tmp += s[i][m - cnt + 1];
    }

    en = cnt;
    for (int j = m - cnt; j >= en; j--) {
      tmp += s[n - cnt + 1][j];
    }

    en = cnt;
    for (int i = n - cnt; i >= en; i--) {
      tmp += s[i][cnt];
    }
    tmp.pop_back();

    if (tmp.size() >= 4) {
      tmp += tmp[0];
      tmp += tmp[1];
      tmp += tmp[2];
    }
    

    int sz = tmp.size();
    for (int i = 0; i + 3 < sz; i++) {
      if (tmp[i] == '1' and tmp[i + 1] == '5' and tmp[i + 2] == '4' and tmp[i + 3] == '3') {
        ans++;
      }
    }
  }

  cout << ans << '\n';
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