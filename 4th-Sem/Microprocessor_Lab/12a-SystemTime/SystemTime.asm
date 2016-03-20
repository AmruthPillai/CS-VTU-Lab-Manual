.model SMALL

DISPLAY MACRO
	AAM ; BCD Adjustment After Multiplication
	MOV BX, AX
	
	MOV DL, BH
	ADD DL, 30h
	MOV AH, 02h
	INT 21h
	
	MOV DL, BL
	ADD DL, 30h
	MOV AH, 02h
	INT 21h
ENDM

COLON MACRO
	MOV DL, ':'
	MOV AH, 02h
	INT 21h
ENDM

.data
	MSG1	dB	10, 13, 'The Current System Time is $'

.code
	MOV AX, @DATA
	MOV DS, AX
	
	LEA DX, MSG1
	MOV AH, 09h
	INT 21h

	; Interrupt to Fetch System Time
	; CH - Hours | CL - Minutes | DH - Seconds | DL - Miliseconds
	MOV AH, 2Ch
	INT 21h
	
	MOV AL, CH
	DISPLAY
	COLON
	
	MOV AL, CL
	DISPLAY
	COLON
	
	MOV AL, DH
	DISPLAY
	
	MOV AH, 4Ch
	INT 21h
END