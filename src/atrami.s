.if 1
;AMIGA_MOUSE = 1
;.include "atrst.s"

        .include        "mouse-kernel.inc"

	.import	INSTALL, UNINSTALL, HIDE, SHOW, SETBOX, GETBOX
	.import	MOVE, BUTTONS, POS, INFO, IOCTL, IRQ

;	.export	CHIDE, CSHOW, CPREP, CDRAW, CMOVEX, CMOVEY
	.import	IRQ_WORKER, IRQ_WORKER_RETURN
	.import	XPosWrk, YPosWrk
	.import	dumx, dumy

        .macpack        module

        module_header   _atrami_mou

; Driver signature

        .byte   $6d, $6f, $75           ; "mou"
        .byte   MOUSE_API_VERSION       ; Mouse driver API version number

; Library reference

libref: .addr   $0000

; Jump table

        .addr   INSTALL_ami
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

.if 0
CHIDE:  jmp     $0000                   ; Hide the cursor
CSHOW:  jmp     $0000                   ; Show the cursor
CPREP:  jmp     $0000                   ; Prepare to move the cursor
CDRAW:  jmp     $0000                   ; Draw the cursor
CMOVEX: jmp     $0000                   ; Move the cursor to X coord
CMOVEY: jmp     $0000                   ; Move the cursor to Y coord
.else
	.res	6*3, $ff
.endif

	.rodata

; Amiga mouse lookup table

AmiTab: .byte $FF,$01,$00,$FF
        .byte $00,$FF,$FF,$01
        .byte $01,$FF,$FF,$00
        .byte $FF,$00,$01,$FF


	.code

INSTALL_ami:
	lda	#<irq_worker
	sta	IRQ_WORKER
	lda	#>irq_worker
	sta	IRQ_WORKER + 1
	jmp	INSTALL

irq_worker:
        lsr
        and     #%00000101
        ora     dumx
        tax
        lda     AmiTab,x
        bmi     nxami

        bne     xiami

        dec     XPosWrk
        lda     XPosWrk
        cmp     #255
        bne     nxami
        dec     XPosWrk+1
        jmp     nxami

xiami:  inc     XPosWrk
        bne     nxami
        inc     XPosWrk+1

nxami:  tya

        and     #%00000101
        ora     dumy
        tax
        lda     AmiTab,x
        bmi     nyami

        bne     yiami

        dec     YPosWrk
        lda     YPosWrk
        cmp     #255
        bne     nyami
        dec     YPosWrk+1
        jmp     nyami

yiami:  inc     YPosWrk
        bne     nyami
        inc     YPosWrk+1

; store old readings

nyami:  tya
        and     #%00001010
        sta     dumx
        tya
        and     #%00000101
        asl
        sta     dumy

	jmp	IRQ_WORKER_RETURN

.endif