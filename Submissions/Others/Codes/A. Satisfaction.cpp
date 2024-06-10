#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e6 + 9;
int a[N];

ll fun(int l, int r) { // return number of inversions in subarray a[l....r]
  if (l >= r) return 0;

  // divide part
  int mid = (l + r) / 2;
  ll ans = fun(l, mid);
  ans += fun(mid + 1, r);

  // conquer part
  vector<int> v;
  for (int i = mid + 1; i <= r; i++) {
    v.push_back(a[i]);
  }
  sort(v.begin(), v.end());
  for (int i = l; i <= mid; i++) {
    ans += (lower_bound(v.begin(), v.end(), a[i]) - v.begin());
  }
  return ans;
}

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int arr[n];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    if(s[i] == 'C') {
      a[i] = arr[i];
    }
    else {
      a[i] = INT_MAX;
    }
  }
  for(int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << endl;
  vector<int> stopage;
  int c_cnt = 0, p_cnt = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'P') {
      p_cnt++;
    }
    else {
      c_cnt++;
    }
    if(p_cnt == c_cnt) {
      stopage.push_back(i);
    }
  }

  deque<int> dq;
  if(stopage.size() == 0) {
    for(int i = 0; i < n; i++) {
      if(s[i] == 'P') {
        dq.push_back(a[i]);
      }
      else {
        cout << a[i] << ' ';
        int pos = fun(i, n - 1) - fun(i + 1, n - 1);
        cout << pos << '\n';
      }
    }
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