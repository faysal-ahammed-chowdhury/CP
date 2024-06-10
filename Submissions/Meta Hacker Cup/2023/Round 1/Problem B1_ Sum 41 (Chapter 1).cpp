#include <bits/stdc++.h>
using namespace std;

#define int long long
int cs = 0;
void solve() {
  int n; cin >> n;
  vector<int> prime_factors;
  int lim = sqrt(n + 1);
  for(int i = 2; i <= lim; i++) {
    while(n % i == 0) {
      prime_factors.push_back(i);
      n /= i;
    }
  }
  if(n > 1) prime_factors.push_back(n);

  int sum = 0;
  for(auto p: prime_factors) {
    sum += p;
  }
  cout << "Case #" << ++cs << ": ";
  if(sum > 41) {
    cout << -1 << '\n';
    return;
  }
  int x = (41 - sum);
  cout << (int) prime_factors.size() + x << ' ';
  for(int i = 1; i <= x; i++) {
    cout << 1 << ' ';
  }
  for(auto p: prime_factors) {
    cout << p << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}