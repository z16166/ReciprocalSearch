#include <chrono>
#include <stdio.h>

using bigint = uint64_t;

__forceinline bigint ceil(bigint d, bigint n)
{
    bigint q = n / d;
    if (q >= 100)
        return 100;

    if (n % d)
        ++q;

    return q;
}

__forceinline void subdiv(bigint n1, bigint d1, bigint n2, bigint d2, int k, bigint &n3, bigint &d3,
                          bigint &n4, bigint &d4)
{
    d3 = d1 * d2;
    n3 = n1 * d2 - n2 * d1;

    n4 = n3;
    d4 = d3 * k;
}

int main()
{
    const auto start = std::chrono::steady_clock::now();

    int total = 0;
    int valid = 0;

    for (bigint i1 = 2; i1 <= 10; i1++)
    {
        bigint n20, d20, n2, d2;
        subdiv(1, 1, 1, i1, 9, n20, d20, n2, d2);
        const bigint u2 = (std::min)((bigint)92, ceil(n2, d2));
        for (bigint i2 = i1 + 1; i2 <= u2; i2++)
        {
            const bigint s2 = i1 * i2;
            if (s2 <= (i2 + i1))
                continue;

            bigint n30, d30, n3, d3;
            subdiv(n20, d20, 1, i2, 8, n30, d30, n3, d3);
            const bigint u3 = (std::min)((bigint)93, ceil(n3, d3));
            for (bigint i3 = i2 + 1; i3 <= u3; i3++)
            {
                const bigint s3 = s2 * i3;
                if (s3 <= (i2 * i3 + i1 * i3 + s2))
                    continue;

                bigint n40, d40, n4, d4;
                subdiv(n30, d30, 1, i3, 7, n40, d40, n4, d4);
                const bigint u4 = (std::min)((bigint)94, ceil(n4, d4));
                for (bigint i4 = i3 + 1; i4 <= u4; i4++)
                {
                    const bigint s4 = s3 * i4;
                    if (s4 <= (i2 * i3 * i4 + i1 * i3 * i4 + i1 * i2 * i4 + s3))
                        continue;

                    bigint n50, d50, n5, d5;
                    subdiv(n40, d40, 1, i4, 6, n50, d50, n5, d5);
                    const bigint u5 = (std::min)((bigint)95, ceil(n5, d5));
                    for (bigint i5 = i4 + 1; i5 <= u5; i5++)
                    {
                        const bigint s5 = s4 * i5;
                        if (s5 <= (i2 * i3 * i4 * i5 + i1 * i3 * i4 * i5 + i1 * i2 * i4 * i5 +
                                   i1 * i2 * i3 * i5 + s4))
                            continue;

                        bigint n60, d60, n6, d6;
                        subdiv(n50, d50, 1, i5, 5, n60, d60, n6, d6);
                        const bigint u6 = (std::min)((bigint)96, ceil(n6, d6));
                        for (bigint i6 = i5 + 1; i6 <= u6; i6++)
                        {
                            const bigint s6 = s5 * i6;
                            if (s6 <=
                                ((i2 * i3 * i4 * i5 * i6 + i1 * i3 * i4 * i5 * i6 + i1 * i2 * i4 * i5 * i6 +
                                  i1 * i2 * i3 * i5 * i6 + i1 * i2 * i3 * i4 * i6 + s5)))
                                continue;

                            bigint n70, d70, n7, d7;
                            subdiv(n60, d60, 1, i6, 4, n70, d70, n7, d7);
                            const bigint u7 = (std::min)((bigint)97, ceil(n7, d7));
                            for (bigint i7 = i6 + 1; i7 <= u7; i7++)
                            {
                                const bigint s7 = s6 * i7;
                                if (s7 <= ((i2 * i3 * i4 * i5 * i6 * i7 + i1 * i3 * i4 * i5 * i6 * i7 +
                                            i1 * i2 * i4 * i5 * i6 * i7 + i1 * i2 * i3 * i5 * i6 * i7 +
                                            i1 * i2 * i3 * i4 * i6 * i7 + i1 * i2 * i3 * i4 * i5 * i7 + s6)))
                                    continue;

                                bigint n80, d80, n8, d8;
                                subdiv(n70, d70, 1, i7, 3, n80, d80, n8, d8);
                                const bigint u8 = (std::min)((bigint)98, ceil(n8, d8));
                                for (bigint i8 = i7 + 1; i8 <= u8; i8++)
                                {
                                    const bigint s8 = s7 * i8;
                                    if (s8 <=
                                        (i2 * i3 * i4 * i5 * i6 * i7 * i8 + i1 * i3 * i4 * i5 * i6 * i7 * i8 +
                                         i1 * i2 * i4 * i5 * i6 * i7 * i8 + i1 * i2 * i3 * i5 * i6 * i7 * i8 +
                                         i1 * i2 * i3 * i4 * i6 * i7 * i8 + i1 * i2 * i3 * i4 * i5 * i7 * i8 +
                                         i1 * i2 * i3 * i4 * i5 * i6 * i8 + s7))
                                        continue;

                                    bigint n90, d90, n9, d9;
                                    subdiv(n80, d80, 1, i8, 2, n90, d90, n9, d9);
                                    const bigint u9 = (std::min)((bigint)99, ceil(n9, d9));
                                    for (bigint i9 = i8 + 1; i9 <= u9; i9++)
                                    {
                                        const bigint s9 = s8 * i9;
                                        if (s9 <= (i2 * i3 * i4 * i5 * i6 * i7 * i8 * i9 +
                                                   i1 * i3 * i4 * i5 * i6 * i7 * i8 * i9 +
                                                   i1 * i2 * i4 * i5 * i6 * i7 * i8 * i9 +
                                                   i1 * i2 * i3 * i5 * i6 * i7 * i8 * i9 +
                                                   i1 * i2 * i3 * i4 * i6 * i7 * i8 * i9 +
                                                   i1 * i2 * i3 * i4 * i5 * i7 * i8 * i9 +
                                                   i1 * i2 * i3 * i4 * i5 * i6 * i8 * i9 +
                                                   i1 * i2 * i3 * i4 * i5 * i6 * i7 * i9 + s8))
                                            continue;

                                        bigint n100, d100, n10, d10;
                                        subdiv(n90, d90, 1, i9, 1, n100, d100, n10, d10);
                                        const bigint u10 = (std::min)((bigint)100, ceil(n10, d10));
                                        for (bigint i10 = i9 + 1; i10 <= u10; i10++)
                                        {
                                            const bigint s10 = s9 * i10;
                                            if (s10 == (i2 * i3 * i4 * i5 * i6 * i7 * i8 * i9 * i10 +
                                                        i1 * i3 * i4 * i5 * i6 * i7 * i8 * i9 * i10 +
                                                        i1 * i2 * i4 * i5 * i6 * i7 * i8 * i9 * i10 +
                                                        i1 * i2 * i3 * i5 * i6 * i7 * i8 * i9 * i10 +
                                                        i1 * i2 * i3 * i4 * i6 * i7 * i8 * i9 * i10 +
                                                        i1 * i2 * i3 * i4 * i5 * i7 * i8 * i9 * i10 +
                                                        i1 * i2 * i3 * i4 * i5 * i6 * i8 * i9 * i10 +
                                                        i1 * i2 * i3 * i4 * i5 * i6 * i7 * i9 * i10 +
                                                        i1 * i2 * i3 * i4 * i5 * i6 * i7 * i8 * i10 + s9))
                                            {
                                                ++valid;

                                                printf("%5d: %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld\n", valid, i1, i2,
                                                       i3, i4, i5, i6, i7, i8, i9, i10);
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

    const auto end = std::chrono::steady_clock::now();
    printf("%.3f seconds\n",
           std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / 1000.0);
}