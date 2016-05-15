; Assembly Level Program 7a
; Read your name from the keyboard and display it at a specified location on the screen in front of the message What is your name? You must clear the entire screen before display.

.model SMALL

.data
	MSG1	dB	10, 13, 'Enter your name: $'
	MSG2	dB	10, 13, 'What is your name? $'
	
	ARRAY	dB	40h	DUP(?)
	
.code
	; Initialize Data Segment
	MOV AX, @DATA
	MOV DS, AX
	
	; Point SI to First Position of ARRAY
	MOV SI, ARRAY
	
	; Display Message
	LEA DX, MSG1
	MOV AH, 09h
	INT 21h
	
ReadName:
	; Read Input from Keyboard
	MOV AH, 01h
	INT 21h
	
	; Copy Input to ARRAY
	MOV [SI], AL
	INC SI
	
	; Check for Return/Enter Key
	CMP AL, 0Dh
	JNZ ReadName
	
	; Add Terminating Character at End of String
	MOV [SI], '$'
	
	; Clear Screen
	MOV AH, 00h
	MOV AL, 03h
	INT 10h
	
	; Set Cursor to 2x20
	MOV AH, 02h
	MOV BH, 00h
	MOV DH, 2d
	MOV DL, 20d
	INT 10h
	
	; Display Message
	LEA DX, MSG2
	MOV AH, 09h
	INT 21h
	
DisplayName:
	; Display Message
	LEA DX, ARRAY
	MOV AH, 09h
	INT 21h
	
Exit:
	; Terminate the Program
	MOV AH, 4Ch
	INT 21h
END
	