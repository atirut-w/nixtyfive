.org $1000

    jmp main

.org $103e

.proc main
    ldy #0
loop:
    lda text, y
    cmp #0
    beq hang
    sta $2ff
    iny
    bra loop

hang: bra hang

text:
    .byte "This is not a bootable disk.", $d
    .byte "Please insert a bootable floppy and restart the system to try again ...", $d, $0
.endproc
