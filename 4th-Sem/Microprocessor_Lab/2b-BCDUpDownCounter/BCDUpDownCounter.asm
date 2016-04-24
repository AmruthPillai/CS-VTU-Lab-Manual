; Assembly Level Program 2b
; Implement a BCD Up-Down Counter on the Logic Controller Interface.

.model SMALL

.data
	PA		EQU	0E400h
	PB		EQU	0E401h
	PC		EQU	0E402h
	CR		EQU	0E403h
	CW		dB	80h
	COUNT	dB	00h
	
.code
	MOV AX, @DATA
	MOV DS, AX
	
	MOV DX, CR
	MOV AL, CW
	OUT DX, AL
	
	MOV DX, PA
	MOV AL, 00h
	
UpCounter:
	OUT DX, AL
	CALL Delay
	
	INC AL
	DAA
	
	CMP AL, 00h
	JNZ UpCounter
	
	MOV DX, PA
	MOV AL, 99h
	
DownCounter:
	OUT DX, AL
	CALL Delay
	
	DEC AL
	DAS
	
	CMP AL, 99h
	JNZ DownCounter
	
Exit:
	MOV AH, 4Ch
	INT 21h
	
Delay PROC NEAR
	MOV SI, 0FFFFh
	Loop1:
	MOV DI, 04FFFh
	Loop2:
	DEC DI
	JNZ Loop2
	DEC SI
	JNZ Loop1
	RET
Delay ENDP
END