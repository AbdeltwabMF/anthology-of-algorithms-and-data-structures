/*
  - It also has important applications in many tasks unrelated to arithmetic, since it can be used with any operations that have the property of associativity:
*/

// 1. Modular Exponentiation

ll binExp(ll a, ll b, ll p) {
  ll res = 1;
  while (b) {
    if (b & 1ll)
      res = res * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return res;
}

// 2. Modular Multiplication

ll binMul(ll a, ll b, ll p) {
  ll res = 0;
  a %= p;
  while (b) {
    if (b & 1ll)
      res = (res + a) % p;
    a = (a + a) % p;
    b >>= 1;
  }
  return res;
}

// 3. Modular Multiplicative Inverse

ll modInv(ll b, ll p) {
  return binExp(b, p - 2, p); // Guaranteed that p is a Prime Number
}

