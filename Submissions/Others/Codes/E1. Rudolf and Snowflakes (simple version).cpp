#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 1e6 + 9;
int arr[N];

void solve() {
  int n; cin >> n;
  if(arr[n]) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int lim = sqrt(N);
  for(int k = 2; k < lim; k++) {
    int k_powers = k * k;
    int x = 1 + k + k_powers;
    while(x < N) {
      arr[x] = 1;
      k_powers *= k;
      x += k_powers;
    }
  }

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}