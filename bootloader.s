.segment "STARTUP"

.proc main
    lda #$4f
    sta $2ff
    lda #$4b
    sta $2ff
    lda #$21
    sta $2ff
    brk
.endproc
