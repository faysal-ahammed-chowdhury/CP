#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 22;
int a[N];
long long ans = INT_MAX;

void func(int pos, long long w1, long long w2) {
  if(pos == 0) {
    ans = min(ans, abs(w1 - w2));
    return;
  }
  func(pos - 1, w1 + a[pos], w2);
  func(pos - 1, w1, w2 + a[pos]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  func(n, 0, 0);
  cout << ans << '\n';

  return 0;
}