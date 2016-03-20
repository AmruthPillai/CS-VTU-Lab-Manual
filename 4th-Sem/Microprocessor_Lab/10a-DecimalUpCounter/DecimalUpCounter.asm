; Assembly Level Program 13a
; Program to simulate a Decimal Up Counter to display 00 to 99.

.model SMALL

.code
	MOV AL, 30h
FirstLoop:
	MOV DL, AL
	MOV AH, 02h
	INT 21h
	PUSH AX
	
	MOV BL, 30h
SecondLoop:
	MOV DL, BL
	MOV AH, 02h
	INT 21h
	
	INC BL
	
	; Get Current Cursor Position
	MOV AH, 03h
	INT 10h
	
	; Set Cursor to 2nd Column
	MOV AH, 02h
	MOV DL, 01h
	INT 10h
	
	CMP BL, 039h
	JLE SecondLoop
	
	; Set Cursor to 1st Column
	MOV AH, 02h
	MOV DL, 00h
	INT 10h
	
	POP AX
	INC AL
	
	CMP AL, 039h
	JLE FirstLoop
	
	MOV AH, 4Ch
	INT 21h
END