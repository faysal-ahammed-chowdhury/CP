#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n,x ; cin >> n >> x;
  int level = min(n - 1, x);
  for (int i = 1; i <= level; i++) {
    int taken = i + 1;
    int score = i;
    int need = x - score;
    int rem_node = n - taken;
    int x = need / i;
    if (x <= rem_node) {
      rem_node -= x;
      need -= (x * i);
      if (rem_node == 0 and need == 0) {
        for (int j = 1; j <= i; j++) {
          cout << j << ' ' << j + 1 << '\n';
        }
        for (int j = 1, cur = i + 2; j <= x; j++, cur++) {
          cout << i << ' ' << cur << '\n';
        }
        return;
      }
      else if (rem_node != 0 and rem_node <= need) {
        for (int j = 1; j <= i; j++) {
          cout << j << ' ' << j + 1 << '\n';
        }
        int cur = i + 2;
        for (int j = 1; j <= x; j++, cur++) {
          cout << i << ' ' << cur << '\n';
        }
        for (int j = 1; j <= rem_node - 1; j++, cur++) {
          cout << 1 << ' ' << cur << '\n';
          need--;
        }
        cout << need << ' ' << cur << '\n';
        return;
      }
    }
  }

  cout << -1 << '\n';
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