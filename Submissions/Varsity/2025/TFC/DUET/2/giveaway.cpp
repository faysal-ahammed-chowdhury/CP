#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1005;
string mat[N], pat[N];
bool need[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k; cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> mat[i] >> pat[i];
    bool flag = false;
    for (auto c : pat[i]) {
      if (c == '*') flag = true;
    }
    need[i] = flag;
  }

  for (int i = 1; i <= n; i++) {
    if (need[i]) {
      for (auto c : mat[i]) {
        if (c == '-') {
          cout << "N\n";
          return 0;
        }
      }
    }
  }

  cout << "Y\n";

  return 0;
}