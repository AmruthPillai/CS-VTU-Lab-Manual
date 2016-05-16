; Assembly Level Program 8a
; Compute nCr using recursive procedure. Assume that ‘n’ and ‘r’ are non-negative integers.

.model SMALL

.data
	N	dB	21d
	R	dB	19d
	NCR	dW	?

.code
	; Initialize Data Segment
	MOV AX, @DATA
	MOV DS, AX
	
	; Clear NCR
	MOV AX, 00h
	MOV AL, N
	MOV BL, R
	MOV NCR, 00h
	
	CALL NCRProcedure
	
Exit:
	MOV AH, 4Ch
	INT 21h
	
NCRProcedure PROC NEAR
	CMP AX, BX
	JE IncrementBy1
	
	CMP BX, 00h
	JE IncrementBy1
	
	CMP BX, 01h
	JE IncrementByN
	
	DEC AX
	
	CMP AX, BX
	JE IncrementByNPlus1
	
	PUSHA
	CALL NCRProcedure
	POPA
	
	DEC BX
	
	PUSHA
	CALL NCRProcedure
	POPA
	RET
	
IncrementBy1:
	INC NCR
	RET
	
IncrementByN:
	ADD NCR, AX
	RET
	
IncrementByNPlus1:
	ADD NCR, AX
	INC NCR
	RET
NCRProcedure ENDP
END
