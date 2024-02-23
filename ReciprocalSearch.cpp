#include <stdio.h>
#include <math.h>

#pragma warning(disable:4146)
#include <gmp.h>

#define min(a,b) (((a)<(b))?(a):(b))

bool check(int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8, int i9, int i10) {
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

    mpz_t t;
    mpz_init(t);
    mpz_set_ui(t, 1);
    for (int k = 0; k < 10; ++k) {
        mpz_mul_ui(t, t, a[k]);
    }

    mpz_t s;
    mpz_init(s);
    mpz_set_ui(s, 0);

    mpz_t t1;
    mpz_init(t1);
    for (int k = 0; k < 10; ++k) {
        mpz_div_ui(t1, t, a[k]);
        mpz_add(s, s, t1);
    }

    bool valid = (mpz_cmp(s, t) == 0);

    mpz_clear(t);
    mpz_clear(s);
    mpz_clear(t1);

    return valid;
}

int main() {
    int total = 0;
    int valid = 0;

    double ii[101];

    for (int i = 1; i <= 100; i++) { ii[i] = 1.0 / i; }

    for (int i1 = 2; i1 <= 10; i1++) {
        double m1 = 1 - ii[i1];

        for (int i2 = i1 + 1; i2 < min(92, (int)(9.0 / m1) + 1); i2++) {
            double m2 = m1 - ii[i2];

            for (int i3 = i2 + 1; i3 < min(93, (int)(8.0 / m2) + 1); i3++) {
                double m3 = m2 - ii[i3];
                if (m3 <= 0) { continue; }

                for (int i4 = i3 + 1; i4 < min(94, (int)(7.0 / m3) + 1); i4++) {
                    double m4 = m3 - ii[i4];
                    if (m4 <= 0) { continue; }

                    for (int i5 = i4 + 1; i5 < min(95, (int)(6.0 / m4) + 1); i5++) {
                        double m5 = m4 - ii[i5];
                        if (m5 <= 0) { continue; }

                        for (int i6 = i5 + 1; i6 < min(96, (int)(5.0 / m5) + 1); i6++) {
                            double m6 = m5 - ii[i6];
                            if (m6 <= 0) { continue; }

                            for (int i7 = i6 + 1; i7 < min(97, (int)(4.0 / m6) + 1); i7++) {
                                double m7 = m6 - ii[i7];
                                if (m7 <= 0) { continue; }

                                for (int i8 = i7 + 1; i8 < min(98, (int)(3.0 / m7) + 1); i8++) {
                                    double m8 = m7 - ii[i8];
                                    if (m8 <= 0) { continue; }

                                    for (int i9 = i8 + 1; i9 < min(99, (int)(2.0 / m8) + 1); i9++) {
                                        double m9 = m8 - ii[i9];

                                        if (m9 <= 0.01) { continue; }
                                        double i10 = 1.0 / m9;

                                        if (fabs(i10 - round(i10)) < 0.000001) {
                                            ++total;                                            

                                            if (check(i1, i2, i3, i4, i5, i6, i7, i8, i9, (int)i10)) {
                                                ++valid;
                                                printf("%d %d %d %d %d %d %d %d %d %.4f(%d)\n", i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, (int)i10);
                                            } else if (check(i1, i2, i3, i4, i5, i6, i7, i8, i9, (int)i10 + 1)) {
                                                ++valid;
                                                printf("%d %d %d %d %d %d %d %d %d %.4f(%d)\n", i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, (int)i10 + 1);
                                            } else if (check(i1, i2, i3, i4, i5, i6, i7, i8, i9, (int)i10 - 1)) {
                                                ++valid;
                                                printf("%d %d %d %d %d %d %d %d %d %.4f(%d)\n", i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, (int)i10 - 1);
                                            }
                                            else {
                                                printf("%d %d %d %d %d %d %d %d %d %.4f    INVALID\n", i1, i2, i3, i4, i5, i6, i7, i8, i9, i10);
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
    }

    printf("total %d, valid = %d\n", total, valid);
}