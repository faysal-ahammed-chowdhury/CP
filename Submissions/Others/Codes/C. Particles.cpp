#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const long long INF = 2e18;

void solve() {
  int n; cin >> n;
  vector<int> odd, even;
  bool has_pos = false;
  long long ans = -INF;
  for(int i = 1; i <= n; i++) {
    int x; cin >> x;
    if(i & 1) {
      odd.push_back(x);
    }
    else {
      even.push_back(x);
    }
    if(x > 0) {
      has_pos = true;
    }
    ans = max(ans, 1LL * x);
  }

  if(!has_pos) {
    cout << ans << '\n';
    return;
  }

  long long sum_odd = 0, sum_even = 0;
  for(auto i: odd) {
    if(i > 0) {
      sum_odd += i;
    }
  }
  for(auto i: even) {
    if(i > 0) {
      sum_even += i;
    }
  }
  ans = max(sum_odd, sum_even);
  cout << ans << '\n';
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