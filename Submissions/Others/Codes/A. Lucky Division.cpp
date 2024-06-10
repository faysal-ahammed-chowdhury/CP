#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

bool is_lucky(int n) {
  stringstream ss;
  ss << n;
  string s; ss >> s;
  for(auto i: s) {
    if(i != '4' && i != '7') return false;
  }
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 4; i <= n; i++) {
    if(is_lucky(i)) {
      if(n % i == 0) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}