#include <bits/stdc++.h>
using namespace std;

const int mod = 100000007;

int solve_greater_or_equal(vector<int> e, int t) {
  int ans = 1;
  for(auto i: e) {
    ans = 1LL * ans * (i / t + 1) % mod;
  }
  return ans;
}

int solve_equal(vector<int> e, int t) {
  return (solve_greater_or_equal(e, t) - solve_greater_or_equal(e, t + 1) + mod) % mod;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, t, cs = 0;
  while(cin >> n >> m >> t and n != 0) {
    vector<int> e;
    for(int i = 2; i * i <= n; i++) {
      if(n % i == 0) {
        int ex = 0;
        while(n % i == 0) {
          ex++;
          n /= i;
        }
        e.push_back(ex * m);
      }
    }
    if(n > 1) e.push_back(m);
    cout << "Case " << ++cs << ": " << solve_equal(e, t) << '\n';
  }

  return 0;
}