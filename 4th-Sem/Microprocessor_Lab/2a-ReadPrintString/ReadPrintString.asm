; Assembly Level Program 2a
; Write ALP Macros:
; i) 	To read a character from the keyboard in the module
; ii) 	To display a character in module 
; iii) 	Use the above two modules to read a string of characters from the keyboard terminated by the carriage return and print the string on the display in the next line.

.model SMALL

Include ReadCharacter.inc
Include PrintCharacter.inc

.data
	LOC		dB	100	DUP(0)
	STR1	dB	10, 13, 'Enter a String: $'
	STR2	dB	10, 13, 'Entered String is: $'
	
.code
	MOV AX, @DATA
	MOV DS, AX
	
	MOV CX, 00h
	
	LEA DX, STR1
	MOV AH, 09h
	INT 21h
	
	LEA SI, LOC
	
Read:
	READCH
	CMP AL, 0Dh
	JE Display
	
	MOV [SI], AL
	INC SI
	INC CL
	JMP Read
	
Display:
	LEA DX, STR2
	MOV AH, 09h
	INT 21h
	
	LEA SI, LOC
	
Print:
	PRINTCH [SI]
	INC SI
	Loop Print
	
	MOV AH, 4Ch
	INT 21h
END
	