#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n, k; cin >> n >> k;
  int p[n + 1];
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp[p[i]] = x;
  }

  int q; cin >> q;
  while (q--) {
    int pos; cin >> pos;
    map<int, bool> mp1, mp2;
    int time = 0, dir = 0; // dir = 0 -> forward
    if (mp.find(pos) != mp.end() and mp[pos] == 0) dir = 1;

    bool flag = true;
    while (true) {
      if (pos < 1 or pos > p[n]) {
        cout << "YES\n";
        flag = false;
        break;
      }

      if (!dir) {
        auto it = upper_bound(p + 1, p + n + 1, pos);
        if (it == p + n + 1) {
          cout << "YES\n";
          flag = false;
          break;
        }

        int nxt = *it;
        int dis = nxt - pos;
        time += dis;
        bool is_red = (time >= mp[nxt] ? (time - mp[nxt]) % k == 0 : false);
        
        // cout << time << ' ' << nxt << ' ' << is_red << '\n';

        if (is_red and mp1.find(nxt) != mp1.end()) {
          cout << "NO\n";
          flag = false;
          break;
        }
        if (is_red) {
          dir ^= 1;
          mp1[nxt] = true;
        }

        pos = nxt;
      }
      else {
        auto it = lower_bound(p + 1, p + n + 1, pos);
        --it;
        if (it == p) {
          cout << "YES\n";
          flag = false;
          break;
        }

        int nxt = *it;
        int dis = pos - nxt;
        time += dis;
        bool is_red = (time >= mp[nxt] ? (time - mp[nxt]) % k == 0 : false);
        
        if (is_red and mp2.find(nxt) != mp2.end()) {
          cout << "NO\n";
          flag = false;
          break;
        }
        if (is_red) {
          dir ^= 1;
          mp2[nxt] = true;
        }

        pos = nxt;
      }
    }

    if (flag) {
      cout << "YES\n";
    }
  }
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