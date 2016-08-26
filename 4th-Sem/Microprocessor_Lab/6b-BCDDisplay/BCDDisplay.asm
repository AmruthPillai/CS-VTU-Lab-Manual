; Assembly Level Program 6b
; Convert a 16-bit binary value (assumed to be an unsigned integer) to BCD and display it from left to right and right to left for specified number of times on a 7-segment display interface.

.model SMALL

.data
	PA	EQU	0E400h
	PB	EQU	0E401h
	PC	EQU	0E402h
	CR	EQU	0E403h
	CW	dB	80h
	
	BCD		dB	5	DUP(0)
	NUM 	dB	0FFFFh ; 65535 in Hexadecimal
	TABLE	dB	0C0h, 0FPh, 0A4h, 0B0h, 99h, 92h, 82h, 0F8h, 80h, 98h
	LIST	dB	0FFh, 0FFh, 0FFh, 0FFh, ?, ?, ?, ?, ?, 0FFh, 0FFh, 0FFh, 0FFh

.code
	; Initialize Data Segment
	MOV AX, @DATA
	MOV DS, AX

	; Set Control Word Format
	MOV DX, CR
	MOV AL, CW
	OUT DX, AL

	; Point SI to First Position of BCD
	LEA SI, BCD
	MOV AX, NUM
	
	MOV BX, 10000d
	CALL Convert
	
	MOV BX, 1000d
	CALL Convert
	
	MOV BX,100d
	CALL Convert

	MOV BX,10d
	CALL Convert
	
	MOV [SI], DL
	MOV CX, 05h
	
	; Point SI to First Position of BCD
	LEA SI, BCD
	LEA DI, LIST+8
	
Loop1:
	MOV AL, [SI]
	LEA BX, TABLE
	XLAT
	MOV [DI], AL
	INC SI
	DEC DI
	LOOP Loop1

	MOV BH, 10h
	LEA DI, LIST
	
Loop2:
	MOV SI, DI
	CALL Display
	CALL Delay
	
	INC DI
	DEC BH
	JMP Loop2

	MOV BH, 09H
	LEA DI, LIST + 8
	
Loop3:
	MOV SI,DI
	CALL Display
	CALL Delay
	
	DEC DI
	DEC BH
JNZ L3

Exit:
	; Terminate the Program
	MOV AH, 4Ch
	INT 21h

Convert PROC NEAR
	MOV DX, 00h
	DIV BX
	
	MOV [SI], AL
	MOV AX, DX
	INC SI
	RET
Convert ENDP

Display PROC NEAR 
	; Each Message Contains 4 Bytes
	MOV CX, 04h
	
	L2:
		; Each Character Contains 8 Bits
		MOV BL, 08h
		MOV AL, [SI]
		
		L1:
			; Rotate AL without Carry
			ROL AL, 01h
			MOV DX, PB
			OUT DX, AL
			
			PUSH AX
			
			; Toggle 0 to Port C
			MOV DX, PC
			MOV AL, 00h
			OUT DX, AL
			
			; Toggle 1 to Port C
			MOV DX, PC
			MOV AL, 01h
			OUT DX, AL
			
			POP AX
			
			DEC BL
		JNZ L1
		
		INC SI
	LOOP L2
	
	RET
Display ENDP

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
