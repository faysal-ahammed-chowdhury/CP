#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9, K = 32;
int cnt[K], tmp[N];

bool query(int n) {
  bitset<K> bs(n);
  string s = bs.to_string();
  reverse(s.begin(), s.end());
  n = s.size();
  for (int k = 0; k < K; k++) {
    tmp[k] = cnt[k];
  }

  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      if (tmp[i] == 0) return false;
      tmp[i]--;
    }
    tmp[i + 1] += tmp[i] / 2;
  }

  return true;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m; cin >> m;
  while (m--) {
    int type, x; cin >> type >> x;
    if (type == 1) {
      cnt[x]++;
    }
    else {
      bool ans = query(x);
      if (ans) cout << "YES\n";
      else cout << "NO\n";
    }
  }

  return 0;
}