#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, a, b, c; cin >> n >> a >> b >> c;
  vector<int> divisors;
  int lim = sqrt(n + 1);
  for(int i = 1; i <= lim; i++) {
    if(n % i == 0) {
      divisors.push_back(i);
      if(i != (n / i)) {
        divisors.push_back(n / i);
      }
    }
  }

  sort(divisors.begin(), divisors.end());
  long long ways = 0;
  for(auto i: divisors) {
    if(i > a) break;
    for(auto j: divisors) {
      if(j > b) break;
      double need = double(n) / (i * j);
      if(need <= c && binary_search(divisors.begin(), divisors.end(), need)) {
        ways++;
      }
    }
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