#ifndef __RISCV_STDINT_H__
#define __RISCV_STDINT_H__

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef long int64_t;
typedef unsigned long uint64_t;

typedef unsigned long u64;

typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;
typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;

typedef int8_t int_fast8_t;
typedef int64_t int_fast16_t;
typedef int64_t int_fast32_t;
typedef int64_t int_fast64_t;
typedef uint8_t uint_fast8_t;
typedef uint64_t uint_fast16_t;
typedef uint64_t uint_fast32_t;
typedef uint64_t uint_fast64_t;

typedef long intptr_t;
typedef unsigned long uintptr_t;

typedef long intmax_t;
typedef unsigned long uintmax_t;

#define __INT64_C(c)	c ## L
#define __UINT64_C(c)	c ## UL

/* Limits of integral types.  */

/* Minimum of signed integral types.  */
#define INT8_MIN		(-128)
#define INT16_MIN		(-32767-1)
#define INT32_MIN		(-2147483647-1)
#define INT64_MIN		(-__INT64_C(9223372036854775807)-1)
/* Maximum of signed integral types.  */
#define INT8_MAX		(127)
#define INT16_MAX		(32767)
#define INT32_MAX		(2147483647)
#define INT64_MAX		(__INT64_C(9223372036854775807))

/* Maximum of unsigned integral types.  */
#define UINT8_MAX		(255)
#define UINT16_MAX		(65535)
#define UINT32_MAX		(4294967295U)
#define UINT64_MAX		(__UINT64_C(18446744073709551615))

/* Minimum of signed integral types having a minimum size.  */
#define INT_LEAST8_MIN		(-128)
#define INT_LEAST16_MIN	(-32767-1)
#define INT_LEAST32_MIN	(-2147483647-1)
#define INT_LEAST64_MIN	(-__INT64_C(9223372036854775807)-1)
/* Maximum of signed integral types having a minimum size.  */
#define INT_LEAST8_MAX		(127)
#define INT_LEAST16_MAX	(32767)
#define INT_LEAST32_MAX	(2147483647)
#define INT_LEAST64_MAX	(__INT64_C(9223372036854775807))

/* Maximum of unsigned integral types having a minimum size.  */
#define UINT_LEAST8_MAX	(255)
#define UINT_LEAST16_MAX	(65535)
#define UINT_LEAST32_MAX	(4294967295U)
#define UINT_LEAST64_MAX	(__UINT64_C(18446744073709551615))


/* Minimum of fast signed integral types having a minimum size.  */
#define INT_FAST8_MIN		(-128)
#define INT_FAST16_MIN	(-9223372036854775807L-1)
#define INT_FAST32_MIN	(-9223372036854775807L-1)
#define INT_FAST64_MIN		(-__INT64_C(9223372036854775807)-1)
/* Maximum of fast signed integral types having a minimum size.  */
#define INT_FAST8_MAX		(127)
#define INT_FAST16_MAX	(9223372036854775807L)
#define INT_FAST32_MAX	(9223372036854775807L)
#define INT_FAST64_MAX		(__INT64_C(9223372036854775807))

/* Maximum of fast unsigned integral types having a minimum size.  */
#define UINT_FAST8_MAX		(255)
#define UINT_FAST16_MAX	(18446744073709551615UL)
#define UINT_FAST32_MAX	(18446744073709551615UL)
#define UINT_FAST64_MAX	(__UINT64_C(18446744073709551615))

/* Values to test for integral types holding `void *' pointer.  */
#define INTPTR_MIN		(-9223372036854775807L-1)
#define INTPTR_MAX		(9223372036854775807L)
#define UINTPTR_MAX		(18446744073709551615UL)

/* Minimum for largest signed integral type.  */
#define INTMAX_MIN		(-__INT64_C(9223372036854775807)-1)
/* Maximum for largest signed integral type.  */
#define INTMAX_MAX		(__INT64_C(9223372036854775807))

/* Maximum for largest unsigned integral type.  */
#define UINTMAX_MAX		(__UINT64_C(18446744073709551615))

/* Limits of other integer types.  */

/* Limits of `ptrdiff_t' type.  */
#define PTRDIFF_MIN		(-9223372036854775807L-1)
#define PTRDIFF_MAX		(9223372036854775807L)

/* Limits of `sig_atomic_t'.  */
#define SIG_ATOMIC_MIN		(-2147483647-1)
#define SIG_ATOMIC_MAX		(2147483647)

/* Limit of `size_t' type.  */
#define SIZE_MAX		(18446744073709551615UL)

/* Limits of `wchar_t'.  */
#if L'\0' - 1 > 0
# define __WCHAR_MAX	(0xffffffffu + L'\0')
#else
# define __WCHAR_MAX	(0x7fffffff + L'\0')
#endif

#if L'\0' - 1 > 0
# define __WCHAR_MIN	(L'\0' + 0)
#else
# define __WCHAR_MIN	(-__WCHAR_MAX - 1)
#endif

#define WCHAR_MIN		__WCHAR_MIN
#define WCHAR_MAX		__WCHAR_MAX

/* Limits of `wint_t'.  */
# define WINT_MIN		(0u)
# define WINT_MAX		(4294967295u)

/* Signed.  */
#define INT8_C(c)	c
#define INT16_C(c)	c
#define INT32_C(c)	c
#define INT64_C(c)	c ## L

/* Unsigned.  */
#define UINT8_C(c)	c
#define UINT16_C(c)	c
#define UINT32_C(c)	c ## U
#define UINT64_C(c)	c ## UL

/* Maximal type.  */
#define INTMAX_C(c)	c ## L
#define UINTMAX_C(c)	c ## UL

#endif /* __RISCV_STDINT_H__ */