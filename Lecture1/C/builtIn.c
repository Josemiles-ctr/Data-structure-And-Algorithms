#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>
#include <wchar.h>
#include <stddef.h>
#include <complex.h>

int main(void)
{
    puts("=== Built-in C datatypes (sizes and ranges/examples) ===\n");

    /*character types */
    {
        char ch = 'A';
        signed char sch = -5;
        unsigned char uch = 200;
        printf("char demo: ch='%c' (as int=%d), signed char=%d, unsigned char=%u\n\n", ch, (int)ch, sch, uch);
    }

    /*integer types */
    {
        short s = -12345;
        unsigned short us = 54321u;
        int i = 123456789;
        unsigned int ui = 3000000000u;
        long l = 123456789L;
        long long ll = 123456789012345LL;
        unsigned long long ull = 18446744073709551615ull;
        printf("short=%d, unsigned short=%u\n", s, us);
        printf("int=%d, unsigned int=%u\n", i, ui);
        printf("long=%ld, long long=%lld\n", l, ll);
        printf("unsigned long long=%llu\n\n", ull);
    }

    /*fixed-width integers */
    {
        int8_t i8 = -12;
        uint8_t u8 = 250u;
        int16_t i16 = -32000;
        int32_t i32 = 2000000000;
        int64_t i64 = (int64_t)9000000000000000000LL / 10; /* example large value */
        printf("int8_t=%" PRId8 ", uint8_t=%" PRIu8 "\n", i8, u8);
        printf("int16_t=%" PRId16 ", int32_t=%" PRId32 "\n", i16, i32);
        printf("int64_t=%" PRId64 "\n\n", i64);
    }

    /*size_t and ptrdiff_t */
    {
        size_t sz = 42;
        ptrdiff_t pd = (ptrdiff_t)(&sz - (size_t *)NULL); /* just an example expression (implementation-defined) */
        printf("size_t example=%zu, ptrdiff_t example=%td\n\n", sz, pd);
    }

    /*floating-point types */
    {
        float f = 3.14159f;
        double d = 2.718281828;
        long double ld = 1.41421356237L;
        printf("float=%f, double=%f, long double=%Lf\n\n", f, d, ld);
    }

    /*boolean */
    {
        _Bool b1 = 0;
        bool b2 = true;
        printf("_Bool b1=%d, bool b2=%d\n\n", b1, b2);
    }

    /*wide character */
    {
        wchar_t w = L'Ω';
        printf("wchar_t example: %lc (code=%u)\n\n", w, (unsigned)(wint_t)w);
    }

    /* Complex types (C99)*/
#if defined(__STDC_NO_COMPLEX__)
    printf("complex types: not supported by this implementation\n\n");
#else
    {
        /* initializing using the imaginary unit I */
        double complex z = 1.0 + 2.0 * I;
        printf("double complex: sizeof=%zu, example z=1+2i -> real=%.2f imag=%.2f\n\n", sizeof(double complex), creal(z), cimag(z));
    }
#endif

    /* Void and pointers */
    printf("void*: sizeof=%zu (pointer size)\n", sizeof(void *));
    printf("int*: sizeof=%zu, NULL pointer prints as %p\n\n", sizeof(int *), (void *)NULL);

    /* Sign of plain char on this implementation */
    printf("plain char is %ssigned on this implementation\n", ((char)-1) < 0 ? "" : "un");

    puts("\n=== End ===");
    return 0;
}