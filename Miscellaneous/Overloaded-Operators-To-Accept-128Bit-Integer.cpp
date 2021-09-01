typedef __uint128_t       ui128;
typedef __int128           i128;

template <class T> string to_string(T x)
{
  int sn = 1; if(x < 0) sn = -1, x *= sn; string s = "";
  do { s = "0123456789"[x % 10] + s, x /= 10; } while(x);
  return (sn == -1 ? "-" : "") + s;
}

auto str_to_int(string x)
{
  ui128 ret = (x[0] == '-' ? 0 : x[0] - '0');
  for(int i = 1; i < x.size(); ++i) ret = ret * 10 + (x[i] - '0');
  return (x[0] == '-' ? -1 * (i128)ret : ret);
}

istream & operator >> (istream & in, i128 & i) noexcept { string s; in >> s; i = str_to_int(s); return in; }
ostream & operator << (ostream & os, const i128 i) noexcept { os << to_string(i); return os; }
istream & operator >> (istream & in, ui128 & i) noexcept { string s; in >> s; i = str_to_int(s); return in; }
ostream & operator << (ostream & os, const ui128 i) noexcept { os << to_string(i); return os; }

