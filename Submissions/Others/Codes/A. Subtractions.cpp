#include <bits/stdc++.h>
using namespace std;

int like_gcd(int a, int b) {
  if(a < b) swap(a, b);
  if(b == 0) return 0;
  return a / b + like_gcd(a % b, b);
}

void solve() {
  int a, b; cin >> a >> b;
  cout << like_gcd(a, b) << '\n';
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