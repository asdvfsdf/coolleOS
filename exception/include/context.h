#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#define REGS_PUSH(n) sd x##n, (n*8)(sp)

#define REGS_POP(n) sd x##n, (n*8)(sp)

#define SL_REGS(f) f(1) f(3) f(4) f(5) f(6) f(7) f(8) f(9) f(10) \
                   f(11) f(12) f(13) f(14) f(15) f(16) f(17) f(18)\
                   f(19) f(20) f(21) f(22) f(23) f(24) f(25) f(26)\
                   f(27) f(28) f(29) f(30) f(31)


#endif