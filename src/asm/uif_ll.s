.export _uif_reset
.importzp ptr1

.proc _uif_reset
    sta ptr1
    stx ptr1+1

    ; Read once to abort any incoming data
    lda (ptr1)
    ; Docs says to write so...
    sta (ptr1)

loop:
    ; Read until V is set
    clv
    lda (ptr1)
    bvc loop

done:
    rts
.endproc
