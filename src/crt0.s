.export __STARTUP__, _boot_device_addr
.import _main
.importzp sp, ptr1, ptr2

.segment "STARTUP"

.proc __STARTUP__
    ; Beep to let the user know the kernel loaded successfully
    lda #$07
    sta $2ff

    rmb0 $00 ; Unmap the ROM

    ; Set up a dummy IRQ and NMI handler
    lda #<int_handler
    ldx #>int_handler

    sta $fffe ; IRQ/BRK
    stx $ffff
    
    sta $fffa ; NMI
    stx $fffb

    ; Save the address of the boot device.
    lda #$00 ; Source address
    ldx #$20
    sta ptr1
    stx ptr1+1

    lda #<_boot_device_addr ; Destination address
    ldx #>_boot_device_addr
    sta ptr2
    stx ptr2+1

    ldy #0

loop:
    lda (ptr1),y
    sta (ptr2),y
    iny
    cpy #16
    bne loop

    ; Set up C stack
    lda #<stack_end
    ldx #>stack_end
    sta sp
    stx sp+1

    jsr _main
hang: jmp hang
.endproc

.proc int_handler
    rti ; Do nothing
.endproc

stack_begin: .res 128
stack_end:

_boot_device_addr: .res 16
