; Assembly Level Program 7a
; Read your name from the keyboard and display it at a specified location on the screen in front of the message What is your name? You must clear the entire screen before display.

READCH MACRO LOC
	MOV AH, 01h
	INT 21h
	MOV LOC, AL
ENDM

.model SMALL

CLRSCR MACRO
	MOV AH, 00h
	MOV AL, 03h
	INT 10h
ENDM

SETCURSOR MACRO
	MOV AH, 02h
	MOV BH, 00h
	MOV DH, 2
	MOV DL, 20
	INT 10h
ENDM

.data
	MSG1	dB	10, 13, 'Enter your name: $'
	MSG2	dB	10, 13, 'What is your name? $'
	
	ARRAY	dB	40h	DUP(?)
	
.code
	MOV AX, @DATA
	MOV DS, AX
	
	MOV SI, 00h
	
	LEA DX, MSG1
	MOV AH, 09h
	INT 21h
	
ReadName:
	READCH ARRAY[SI]
	INC SI
	CMP AL, 13
	JNZ ReadName
	
	MOV ARRAY[SI], '$'
	
	CLRSCR
	SETCURSOR
	
	LEA DX, MSG2
	MOV AH, 09h
	INT 21h
	
	MOV SI, 00h
	
DisplayName:
	LEA DX, ARRAY[SI]
	MOV AH, 09h
	INT 21h
	
	MOV AH, 4Ch
	INT 21h
END
	