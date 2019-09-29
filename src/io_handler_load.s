	;; R: Handler loading routines

.export _io_handler_load

_io_handler_load:
	LDA #$50
	STA $0300
	LDA #$01
	STA $0301
	LDA #$3F
	STA $0302
	LDA #$40
	STA $0303
	LDA #$05
	STA $0306
	STA $0305
	LDA #$00
	STA $0304
	STA $0309
	STA $030A
	STA $030B
	LDA #$0C
	STA $0308
	JSR $E459
	BPL io_handler_load_success
	RTS
io_handler_load_success:
	LDX #$0B
io_handler_move_dcb:	
	LDA $0500,X
	STA $0300,X
	DEX
	BPL io_handler_move_dcb
	JSR $E459
	BMI io_handler_finish
	JSR $0506
	JMP ($000C)
io_handler_finish:
	RTS
