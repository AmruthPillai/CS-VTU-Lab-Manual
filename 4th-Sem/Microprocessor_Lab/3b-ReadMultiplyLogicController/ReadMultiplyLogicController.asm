; Assembly Level Program 3b
; Read the status of two 8-bit inputs (X & Y) from the Logic Controller Interface and display X*Y.

.model SMALL

.data
	PA	EQU	0E400h
	PB	EQU	0E401h
	PC	EQU	0E402h
	CR	EQU	0E403h
	CW	dB	80h
	M1	dB	10, 13, 'Enter the first 8-bit Number...$'
	M2	dB	10, 13, 'Enter the second 8-bit Number...$'
	
.code
	MOV AX, @DATA
	MOV DS, AX
	
	MOV DX, CR
	MOV AL, CW
	OUT DX, AL
	
	LEA DX, M1
	MOV AH, 09h
	INT 21h
	
	MOV AH, 08h
	INT 21h
	
	MOV DX, PB
	IN AL, DX
	
	MOV BL, AL
	
	LEA DX, M1
	MOV AH, 09h
	INT 21h
	
	MOV AH, 08h
	INT 21h
	
	MOV DX, PB
	IN AL, DX
	
	MUL BL
	
	MOV DX, PA
	OUT DX, AL
	
	CALL Delay
	
	MOV DX, PA
	MOV AL, AH
	OUT DX, AL
	
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