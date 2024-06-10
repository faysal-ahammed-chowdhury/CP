#include <bits/stdc++.h>
using namespace std;

const int N = 1009;
int n, k, a[N];

bool ok(int max_val) {
  for(int i = 1; i <= n; i++) {
    if(a[i] >= max_val) return true;
  }
  for(int i = 1; i < n; i++) {
    long long op = 0;
    int need = max_val;
    bool possible = false;
    for(int j = i; j < n; j++) {
      if(a[j] >= need) {
        possible = true; 
        break;
      }
      int diff = need - a[j];
      op += diff;
      need--;
    }
    if(possible) {
      if(op <= k) return true;
    }
    else if(need <= a[n] && op <= k) return true;
  }
  return false;
}

void solve() {
  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int l = 0, r = 1e9, ans = -1;
  while(l <= r) {
    int mid = (l + r) / 2;
    if(ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}