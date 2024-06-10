#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
using ll = long long;

int cs = 0;
void solve() {
  int p, l; cin >> p >> l;
  ll n = 1LL * p - l;
  vector<int> divisors;
  int lim = sqrt(n + 1);
  for(int i = 1; i <= lim; i++) {
    if((n % i) == 0) {
      divisors.push_back(i);
      if(i != (n / i)) {
        divisors.push_back(n / i);
      }
    }
  }
  cout << "Case " << ++cs << ": ";
  bool possible = false;
  sort(divisors.begin(), divisors.end());
  for(auto i: divisors) {
    if(i > l) {
      cout << i << ' ';
      possible = true;
    }
  }

  if(!possible) {
    cout << "impossible\n";
  }
  else {
    cout << '\n';
  }
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