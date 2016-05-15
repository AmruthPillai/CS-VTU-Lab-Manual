; Assembly Level Program 11a
; Read a pair of input co-ordinates in BCD and move the cursor to the specified location on the screen.

.model SMALL

.data
	MSGX	dB	10, 13 ,'Enter X Coordinates: $'
	MSGY	dB	10, 13 ,'Enter Y Coordinates: $'
	X		dB	?
	Y		dB	?
	
.code
	; Initialize Data Segment
	MOV AX, @DATA
	MOV DS, AX
	
	; Display Message
	LEA DX, MSGX
	MOV AH,09h
	INT 21h
	
	CALL ReadBCD
	MOV X, BH
	
	; Display Message
	LEA DX, MSGY
	MOV AH,09h
	INT 21h
	
	CALL ReadBCD
	MOV Y, BH
	
	; Clear Screen
	MOV AH, 00h
	MOV AL, 03h
	INT 10h
	
	; Set Cursor Interrupt
	MOV AH, 02h
	MOV DH, X ; Row Position
	MOV DL, Y ; Column Position
	MOV BH, 00h ; Page Number
	INT 10h

	; Direct Console Output
	MOV DL, '-'
	MOV AH, 06h
	INT 21h
	
Exit:
	; Terminate the Program
	MOV AH, 4Ch
	INT 21h

ReadBCD PROC NEAR
	; Read 1st Digit from User
	MOV AH, 01h
	INT 21h
	MOV BH, AL
	
	; Read 2nd Digit from User
	MOV AH, 01h
	INT 21h
	MOV BL, AL
	
	MOV CL, 04h
	; Convert ASCII to BCD
	SUB BH, 30h
	SUB BL, 30h
	
	SHL BH, CL
	OR BH, BL
	RET
ReadBCD ENDP

END