#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
int n, d;
int a[N];
vector<int> pos[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> d;
  set<int> missing_numbers;
  for (int i = 0; i <= n + 2; i++) {
    missing_numbers.insert(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    missing_numbers.erase(a[i]);
    pos[a[i]].push_back(i);
  }

  int ans = *missing_numbers.begin();

  for (int mex = 0; mex <= n; mex++) {
    vector<int> v;
    if (pos[mex].size() == 0) {
      ans = min(ans, mex);
      break;
    }
    else {
      v.push_back(pos[mex][0]);
    }
    int lim = 1;
    bool ok = true;
    for (int j = 1; j < pos[mex].size(); j++) {
      int dis = pos[mex][j] - v.back() + 1;
      if (dis <= d) continue;
      else {
        v.pop_back();
        int last = pos[mex][j - 1];
        int end = last;
        int start = max(lim, end - d + 1);
        end = start + d - 1;

        lim = end + d + 1;
        ok &= pos[mex][j] >= lim;
        v.push_back(pos[mex][j]);
      }
    }
    if (ok) {
      ans = min(ans, mex);
      break;
    }
  }

  cout << ans << '\n';

  return 0;
}