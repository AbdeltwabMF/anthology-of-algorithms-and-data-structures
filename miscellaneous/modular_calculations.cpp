/*
  - It also has important applications in many tasks unrelated to arithmetic, since it can be used with any operations that have the property of associativity:
*/

// 1. Modular Exponentiation

i64 binExp(i64 a, i64 b, i64 p) {
  i64 res;
  for (res = 1; b; b >>= 1) {
    if (b & 1ll)
      res = res * a % p;
    a = a * a % p;
  }
  return res;
}

// 2. Modular Multiplication

i64 binMul(i64 a, i64 b, i64 p) {
  i64 res;
  a %= p;
  for (res = 0; b; b >>= 1) {
    if (b & 1ll)
      res = (res + a) % p;
    a = (a + a) % p;
  }
  return res;
}

// 3. Modular Multiplicative Inverse

i64 modInv(i64 b, i64 p) {
  return binExp(b, p - 2, p); // Guaranteed that p is a Prime Number
}

