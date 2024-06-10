#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int D = 1e4 + 9;
bool flag[D];

void solve() {
  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int ans1 = a[n - 1], ans2;
  for(int i = n - 1; i >= 0; i--) {
    if(ans1 % a[i] == 0) {
      if(flag[a[i]]) {
        ans2 = a[i];
        break;
      }
      else {
        flag[a[i]] = true;
      }
    }
    else {
      ans2 = a[i];
      break;
    }
  }
  cout << ans1 << ' ' << ans2 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  while(t--) {
    solve();
  }

  return 0;
}