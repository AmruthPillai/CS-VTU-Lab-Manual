; Assembly Level Program 10a
; Program to simulate a Decimal Up Counter to display 00 to 99.

.model SMALL

.code
	; Load 0 (in ASCII) to AL
	MOV AL, 30h
	
FirstLoop:
	; Print Lower Digit on Screen
	MOV DL, AL
	MOV AH, 02h
	INT 21h
	
	PUSH AX
	
	; Load 0 (in ASCII) to BL
	MOV BL, 30h
	
	SecondLoop:
		; Print Higher Digit on Screen
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
	
	; Check if Digit has exceeded 9
	CMP AL, 039h
	JLE FirstLoop
	
Exit:
	; Terminate the Program
	MOV AH, 4Ch
	INT 21h
END