#include <bits/stdc++.h>
using namespace std;

int ways;

void fun(int n, int k, int make) {
  if(k == 1) {
    if(n >= 0) ways++;
    return;
  }
  if(make - n > n) return;
  fun(make - n,  k - 1, n);
}

void solve() {
  int n, k; cin >> n >> k;
  ways = 0;
  int start = n / 2;
  for(int i = start; i <= n; i++) {
    fun(i, k - 1, n);
  }
  cout << ways << '\n';
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