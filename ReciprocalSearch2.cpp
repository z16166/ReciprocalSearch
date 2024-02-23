#include <stdio.h>
#include <chrono>

#pragma warning(disable:4146)
#include <gmpxx.h>

#define min(a,b) (((a)<(b))?(a):(b))

inline bool check(int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8, int i9, int i10) {
    int a[10];

    a[0] = i1;
    a[1] = i2;
    a[2] = i3;
    a[3] = i4;
    a[4] = i5;
    a[5] = i6;
    a[6] = i7;
    a[7] = i8;
    a[8] = i9;
    a[9] = i10;

    for (int k = 8; k >= 0; --k)
    {
        if (i10 <= a[k])
            return false;
    }

    mpz_class s1 = 1;
    for (int k = 0; k < 10; ++k) {
        s1 *= a[k];
    }

    mpz_class s2 = 0;
    for (int k = 0; k < 10; ++k) {
        s2 += s1 / a[k];
    }

    return s1 == s2;
}

inline int ceil(const mpq_class& m) {
    const mpz_class num = m.get_num();
    const mpz_class den = m.get_den();
    const mpz_class quotient = num / den;
    if (quotient >= 100)
        return 100;

    int r = quotient.get_si();
    if ((num % den) != 0)
        ++r;

    return r;
}

int main() {
    const auto start = std::chrono::steady_clock::now();

    int total = 0;

    mpq_class ii[101];

    for (int i = 1; i <= 100; i++) {
        mpz_class num(1);
        mpz_class den(i);
        ii[i] = mpq_class(num, den);
    }

    for (int i1 = 2; i1 <= 10; i1++) {
        const mpq_class m1 = 1 - ii[i1];

        const int u2 = min(92, ceil(9 / m1));
        for (int i2 = i1 + 1; i2 <= u2; i2++) {
            const mpq_class m2 = m1 - ii[i2];

            const int u3 = min(93, ceil(8 / m2));
            for (int i3 = i2 + 1; i3 <= u3; i3++) {
                const mpq_class m3 = m2 - ii[i3];
                if (m3 <= 0) continue;

                const int u4 = min(94, ceil(7 / m3));
                for (int i4 = i3 + 1; i4 <= u4; i4++) {
                    const mpq_class m4 = m3 - ii[i4];
                    if (m4 <= 0) continue;

                    const int u5 = min(95, ceil(6 / m4));
                    for (int i5 = i4 + 1; i5 <= u5; i5++) {
                        const mpq_class m5 = m4 - ii[i5];
                        if (m5 <= 0) continue;

                        const int u6 = min(96, ceil(5 / m5));
                        for (int i6 = i5 + 1; i6 <= u6; i6++) {
                            const mpq_class m6 = m5 - ii[i6];
                            if (m6 <= 0) continue;

                            const int u7 = min(97, ceil(4 / m6));
                            for (int i7 = i6 + 1; i7 <= u7; i7++) {
                                const mpq_class m7 = m6 - ii[i7];
                                if (m7 <= 0) continue;

                                const int u8 = min(98, ceil(3 / m7));
                                for (int i8 = i7 + 1; i8 <= u8; i8++) {
                                    const mpq_class m8 = m7 - ii[i8];
                                    if (m8 <= 0) continue;

                                    const int u9 = min(99, ceil(2 / m8));
                                    for (int i9 = i8 + 1; i9 <= u9; i9++) {
                                        const mpq_class m9 = m8 - ii[i9];
                                        if (m9 <= 0) continue;

                                        const mpq_class last = 1 / m9;

                                        const mpz_class num = last.get_num();
                                        const mpz_class den = last.get_den();
                                        if ((num % den) != 0) continue;

                                        const mpz_class quotient = num / den;
                                        if (quotient > 100) continue;

                                        int i10 = quotient.get_si();
                                        if (i10 <= i9) continue;

                                        if (check(i1, i2, i3, i4, i5, i6, i7, i8, i9, i10)) {
                                            ++total;
                                            printf("%5d: %d %d %d %d %d %d %d %d %d %d\n", total, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    const auto end = std::chrono::steady_clock::now();
    printf("%.3f seconds\n", std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / 1000.0);
}