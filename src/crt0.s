.export __STARTUP__
.import _main
.importzp sp

.segment "STARTUP"

.proc __STARTUP__
    ; Yank the interrupt vectors from the BIOS. We don't want the BIOS to process them.
    lda #<int_handler
    ldx #>int_handler

    sta $fffe ; IRQ/BRK
    stx $ffff
    
    sta $fffa ; NMI
    stx $fffb

    ; Set up C stack
    lda #<stack_end
    ldx #>stack_end
    sta sp
    stx sp+1

    ; Beep before we start
    lda #$07
    sta $2ff

    jsr _main
hang: jmp hang
.endproc

stack_begin: .res 128
stack_end:

.proc int_handler
    rti ; Do nothing
.endproc
