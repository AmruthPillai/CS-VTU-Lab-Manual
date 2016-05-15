; Assembly Level Program 4a
; Read an alphanumeric character and display its equivalent ASCII code at the center of the screen.

.model SMALL

.data
	MSG1	dB	10, 13, 'Enter an alphanumeric character: $'

.code
	; Initialize Data Segment
	MOV AX, @DATA
	MOV DS, AX

	; Clear Screen
	MOV AH, 00h
	MOV AL, 03h
	INT 10h
	
	; Print Message in Data Segment
	LEA DX, MSG1
	MOV AH, 09h
	INT 21h
	
	; Read Character from User
	MOV AH, 01h
	INT 21h
	
	MOV AH, 00h
	MOV BX, 10d
	PUSH BX

Conversion:
	MOV DX, 00h
	DIV BX
	PUSH DX
	
	CMP AX, 00h
	JNE Conversion
	
	; Set Cursor to Center of the Screen
	MOV AH, 02h
	MOV BH, 00h
	MOV DH, 12d
	MOV DL, 39d
	INT 10H

Display:
	POP DX
	CMP DX, 10
	JE Exit
	
	ADD DL, 30h
	MOV AH, 02h
	INT 21h
	JMP Display

Exit:
	; Terminate the Program
	MOV AH, 4Ch
	INT 21h
END