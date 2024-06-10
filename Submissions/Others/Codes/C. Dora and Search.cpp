#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
  int n; cin >> n;
  map<int, int> mp;
  int a[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int l = 1, r = n;
  int mn = 1, mx = n;
  while(l <= r) {
    if(a[l] == mn) {
      l++;
      mn++;
    }
    else if(a[l] == mx) {
      l++;
      mx--;
    }
    else if(a[r] == mn) {
      r--;
      mn++;
    }
    else if(a[r] == mx) {
      r--;
      mx--;
    }
    else {
      cout << l << ' ' << r << '\n';
      return;
    }
  }
  cout << "-1\n";
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}