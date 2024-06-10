#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c; cin >> a >> b >> c;
  int eq1 = a * b * c;
  int eq2 = a + b + c;
  int eq3 = a + (b * c);
  int eq4 = a * (b + c);
  int eq5 = (a * b) + c;
  int eq6 = (a + b) * c;
  cout << max({eq1, eq2, eq3, eq4, eq5, eq6}) << '\n';
        
  return 0;
}