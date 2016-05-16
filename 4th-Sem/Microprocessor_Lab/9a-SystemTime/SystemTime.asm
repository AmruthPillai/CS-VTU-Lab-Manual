; Assembly Level Program 9a
; Read the current time from the system and display it in the standard format on the screen. 

.model SMALL

DISPLAY MACRO
	; ASCII Adjust after Multiplication
	AAM
	MOV BX, AX
	
	; Print Higher Nibble
	MOV DL, BH
	ADD DL, 30h
	MOV AH, 02h
	INT 21h
	
	; Print Lower Nibble
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
	; Initialize Data Segment
	MOV AX, @DATA
	MOV DS, AX
	
	; Display Message
	LEA DX, MSG1
	MOV AH, 09h
	INT 21h

	; Interrupt to Fetch System Time
	MOV AH, 2Ch
	INT 21h
	
	; CH -> Hours
	MOV AL, CH
	DISPLAY
	COLON
	
	; CL -> Minutes
	MOV AL, CL
	DISPLAY
	COLON
	
	; DH -> Seconds
	MOV AL, DH
	DISPLAY
	
Exit:
	; Terminate the Program
	MOV AH, 4Ch
	INT 21h
END