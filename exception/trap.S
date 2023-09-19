.balign 4

.global trap_entry

trap_entry:

    csrr a0, scause
    csrrc a1, stval, zero
    csrr  a2, sepc
    mv    a3, s0

    call  diff_exception


