#include <bits/stdc++.h>

#ifndef cpheader
#define F0R(i,a,b) for (int i = a; i < b; ++i)
#define f0r(i,b) F0R(i,0,b)
#define F0Rd(i,a,b) for (int i = a; i >= b; --i)
typedef long long ll;
typedef std::vector<int> vi;
template <class T, class U>
constexpr bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}
#define cpheader
#endif


using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  vi ps(s.size(), 0); 

  for (int i = 1, m = s.size(); i < m; ++i) {
    ps[i] = ps[i-1] + (s[i] == s[i-1]);
  }

  int n, l, r;

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> l >> r;
    cout << ps[r-1]-ps[l-1] << '\n';
  }

  return 0;
}
