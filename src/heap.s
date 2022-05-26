.export _kernel_heap

.segment "HEAP"

_kernel_heap:
    .word $f000 - _kernel_heap
    .byte 0
