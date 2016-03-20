.model SMALL

.data
	LOC		dB	04h
	FACT	dW	?
	
.code
	MOV AX, @DATA
	MOV DS, AX
	
	MOV BL, LOC
	MOV AX, 01h
	
	CALL Factorial
	MOV FACT, AX
	
	MOV AH, 4Ch
	INT 21h
	
	Factorial PROC
		CMP BX, 00h
		JE Return
		
		MUL BX
		DEC BX
		CALL Factorial
		
	Return:
		RET
	Factorial ENDP
END

