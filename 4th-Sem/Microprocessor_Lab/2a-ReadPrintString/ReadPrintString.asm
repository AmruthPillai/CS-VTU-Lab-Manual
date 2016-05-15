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
	; Initialize Data Segment
	MOV AX, @DATA
	MOV DS, AX
	
	; Clear Counter Register
	MOV CX, 00h
	
	; Display Message
	LEA DX, STR1
	MOV AH, 09h
	INT 21h
	
	; Point SI to First Position of LOC
	LEA SI, LOC
	
Read:
	; Call READCH Macro
	READCH
	
	; Check if Return/Enter Key was pressed
	CMP AL, 0Dh
	JE Display
	
	MOV [SI], AL
	INC SI
	INC CL
	JMP Read
	
Display:
	; Display Message
	LEA DX, STR2
	MOV AH, 09h
	INT 21h
	
	; Point SI to First Position of LOC
	LEA SI, LOC
	
Print:
	; Call PRINTCH Macro
	PRINTCH [SI]
	INC SI
	Loop Print
	
Exit:
	; Terminate the Program
	MOV AH, 4Ch
	INT 21h
END
