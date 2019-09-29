        .include        "mouse-kernel.inc"

	.import	INSTALL, UNINSTALL, HIDE, SHOW, SETBOX, GETBOX
	.import	MOVE, BUTTONS, POS, INFO, IOCTL, IRQ
	.import	XPosWrk, YPosWrk

	.export	CHIDE, CSHOW, CPREP, CDRAW, CMOVEX, CMOVEY
	.export	IRQ_WORKER
	.import	IRQ_WORKER_RETURN
	.export	dumx, dumy

        .macpack        module

        module_header   _atrst_mou

; Driver signature

        .byte   $6d, $6f, $75           ; "mou"
        .byte   MOUSE_API_VERSION       ; Mouse driver API version number

; Library reference

libref: .addr   $0000

; Jump table

        .addr   INSTALL_st
        .addr   UNINSTALL
        .addr   HIDE
        .addr   SHOW
        .addr   SETBOX
        .addr   GETBOX
        .addr   MOVE
        .addr   BUTTONS
        .addr   POS
        .addr   INFO
        .addr   IOCTL
        .addr   IRQ

; Mouse driver flags

        .byte   MOUSE_FLAG_LATE_IRQ

; Callback table, set by the kernel before INSTALL is called

CHIDE:  jmp     $0000                   ; Hide the cursor
CSHOW:  jmp     $0000                   ; Show the cursor
CPREP:  jmp     $0000                   ; Prepare to move the cursor
CDRAW:  jmp     $0000                   ; Draw the cursor
CMOVEX: jmp     $0000                   ; Move the cursor to X coord
CMOVEY: jmp     $0000                   ; Move the cursor to Y coord

	.rodata

; ST mouse lookup table

STTab:  .byte $FF,$01,$00,$01
        .byte $00,$FF,$00,$01
        .byte $01,$00,$FF,$00
        .byte $01,$00,$01,$FF


	.bss

IRQ_WORKER:	.res	2
dumx:           .res    1
dumy:           .res    1

	.code

INSTALL_st:
	lda	#<irq_worker
	sta	IRQ_WORKER
	lda	#>irq_worker
	sta	IRQ_WORKER + 1
	jmp	INSTALL

irq_worker:
        and     #%00000011
        ora     dumx
        tax
        lda     STTab,x
        bmi     nxst

        beq     xist

        dec     XPosWrk
        lda     XPosWrk
        cmp     #255
        bne     nxst
        dec     XPosWrk+1
        jmp     nxst

xist:   inc     XPosWrk
        bne     nxst
        inc     XPosWrk+1

nxst:   tya
        and     #%00001100
        ora     dumy
        tax
        lda     STTab,x
        bmi     nyst

        bne     yst

        dec     YPosWrk
        lda     YPosWrk
        cmp     #255
        bne     nyst
        dec     YPosWrk+1
        jmp     nyst

yst:    inc     YPosWrk
        bne     nyst
        inc     YPosWrk+1

; store old readings

nyst:   tya
        and     #%00000011
        asl
        asl
        sta     dumx
        tya
        and     #%00001100
        lsr
        lsr
        sta     dumy
	jmp	IRQ_WORKER_RETURN
