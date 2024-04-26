#include <bits/stdc++.h>

#ifndef cpheader
#define F0R(i,a,b) for (int i = a; i < b; ++i)
#define f0r(i,b) F0R(i,0,b)
#define F0Rd(i,a,b) for (int i = a; i >= b; --i)
typedef long long ll;
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

  int n, x, t, c = -1;
  cin >> n >> x;
  for(int i = 0; i < n; ++i) {
    cin >> t;
    if (t > x) {
    c++;
    } else if (t < x){
      c--;
    }
  }
  if (c < 0) {
    c*=-1;
  }
  cout << c;

  return 0;
}
