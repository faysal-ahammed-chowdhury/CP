#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int ans[N];

void sieve() {
  memset(ans, 0, sizeof ans);
  int cnt = 1;
  for(int i = 2; i < N; i++) {
    if(ans[i] == 0) {
      ans[i] = cnt;
      cnt++;
      for(int j = i; j < N; j += i) {
        ans[j] = ans[i];
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();

  int n; cin >> n;
  for (int i = 2; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';

  return 0;
}