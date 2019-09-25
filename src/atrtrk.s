.if 1
;TRAK_MOUSE = 1
;.include "atrst.s"

        .include        "mouse-kernel.inc"

	.import	INSTALL, UNINSTALL, HIDE, SHOW, SETBOX, GETBOX
	.import	MOVE, BUTTONS, POS, INFO, IOCTL, IRQ

;	.export	CHIDE, CSHOW, CPREP, CDRAW, CMOVEX, CMOVEY
	.import	IRQ_WORKER, IRQ_WORKER_RETURN
	.import	XPosWrk, YPosWrk

        .macpack        module

        module_header   _atrtrk_mou

; Driver signature

        .byte   $6d, $6f, $75           ; "mou"
        .byte   MOUSE_API_VERSION       ; Mouse driver API version number

; Library reference

libref: .addr   $0000

; Jump table

        .addr   INSTALL_trak
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

	.bss

oldval:	.res	1

	.code

INSTALL_trak:
	lda	#<irq_worker
	sta	IRQ_WORKER
	lda	#>irq_worker
	sta	IRQ_WORKER + 1
	jmp	INSTALL

irq_worker:
        eor     oldval
        and     #%00001000
        beq     horiz

        tya
        and     #%00000100
        beq     mmup

        inc     YPosWrk
        bne     horiz
        inc     YPosWrk+1
        bne     horiz

mmup:   dec     YPosWrk
        lda     YPosWrk
        cmp     #255
        bne     horiz
        dec     YPosWrk+1

horiz:  tya
        eor     oldval
        and     #%00000010
        beq     mmexit

        tya
        and     #%00000001
        beq     mmleft

        inc     XPosWrk
        bne     mmexit
        inc     XPosWrk+1
        bne     mmexit

mmleft: dec     XPosWrk
        lda     XPosWrk
        cmp     #255
        bne     mmexit
        dec     XPosWrk+1

mmexit: sty     oldval

	jmp	IRQ_WORKER_RETURN

.endif
