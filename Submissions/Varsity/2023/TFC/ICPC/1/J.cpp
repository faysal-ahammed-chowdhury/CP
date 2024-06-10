#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury


// wrong
#define ull long long
const ull N = 1e5 + 9;
ull n, a[N], b[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(ull i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(ull i = 1; i <= n; i++) {
    cin >> b[i];
  }

  vector<bool> visited(n + 5, false);

  vector<vector<ull>> v;
  for(ull i = 2; i <= n; i++) {
    if(visited[i]) continue;
    vector<ull> all;
    for(ull j = i; j <= n; j *= i) {
      all.push_back(j);
      visited[j] = true;
    }
    v.push_back(all);
  }

  ull ans = a[1];

  for(auto i: v) {
    ull x = i.size();
    ull mx = 0;
    for(ull mask = 1; mask < (1 << x); mask++) {
      ull calc = 0;
      for(ull j = 0; j < x; j++) {
        if(mask & (1 << j)) {
          calc += a[i[j]]; // add
          if(j != 0) {
            int cnt = 0;
            for(int k = 0; k < j; k++) {
              if(mask & (1 << k)) cnt++;
            }
            calc -= (b[i[j]]) * cnt;
          }
        }
      }
      mx = max(0LL, max(mx, calc));
    }
    ans += mx;
  }

  cout << ans << '\n';


  return 0;
}