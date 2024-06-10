#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// @author: faysalahammedchowdhury

const int N = 1e6 + 9;
int a[N], freq[N], freq_1_to_i[N], freq_i_to_n[N];

struct ST {
  int tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = 0; // change here
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r]; // change here
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] += x; // change here
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = tree[l] + tree[r]; // change here
  }
  int query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return 0; // return appropriate value
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L + R); // change this
  }
} st;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  map<int, int> mp;
  int id = 0;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]] = ++id; 
  }

  for(int i = 1; i <= n; i++) {
    a[i] = mp[a[i]];
  }

  for(int i = 1; i <= n; i++) {
    freq[a[i]]++;
    freq_1_to_i[i] = freq[a[i]];
  }

  for(int i = 1; i <= n; i++) {
    freq_i_to_n[i] = freq[a[i]] - freq_1_to_i[i] + 1;
  }

  st.build(1, 1, n);

  long long ans = 0;
  for(int i = n; i > 0; i--) {
    ans += st.query(1, 1, n, 1, freq_1_to_i[i] - 1);
    st.upd(1, 1, n, freq_i_to_n[i], 1);
  }

  cout << ans << '\n';

  return 0;
}