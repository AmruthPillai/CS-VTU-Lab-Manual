; Assembly Level Program 5a
; Reverse a given string and check whether it is a palindrome or not. 

.model SMALL

.data
	BUF1	dB	20d
	LEN1	dB	?
	STR1	dB	20d	DUP(0)
	
	RSTR	dB	20d	DUP(0)
	
	MSG1	dB	10, 13, 'Enter a String: $'
	MSG2	dB	10, 13, 'String is a Palindrome!$'
	MSG3	dB	10, 13, 'String is not a Palindrome!$'
	
.code
	; Initialize Data & Extra Segment
	MOV AX, @DATA
	MOV DS, AX
	MOV ES, AX
	
	; Display Message
	LEA DX, MSG1
	MOV AH, 09h
	INT 21h
	
	; Read String from Keyboard
	LEA DX, BUF1
	MOV AH, 0Ah
	INT 21h
	
	; Point SI to First Position of STR1
	LEA SI, STR1
	; Decrement to Skip Reading 0Dh
	DEC SI
	
	; Clear and Set Counter Register
	MOV CX, 00h
	MOV CL, LEN1
	
	; Point DI to Last Position of STR1
	ADD SI, CX
	MOV DI, SI
	
	; Point SI to First Position of RSTR
	LEA SI, RSTR
	
CopyString:
	MOV AL, [DI]
	MOV [SI], AL
	INC SI
	DEC DI
	LOOP CopyString
	
	; Point SI to First Position of STR1
	LEA SI, STR1
	; Point DI to First Position of STR1
	LEA DI, RSTR
	
	; Clear and Set Counter Register
	MOV CX, 00h
	MOV CL, LEN1
	
	; Clear Direction Flag
	CLD
	
	; Repeatedly Compare String Byte-by-Byte
	REPE CMPSB
	JE Palindrome
	
	; Display Message
	LEA DX, MSG3
	MOV AH, 09h
	INT 21h
	JMP Exit
	
Palindrome:
	; Display Message
	LEA DX, MSG2
	MOV AH, 09h
	INT 21h
	
Exit:
	; Terminate the Program
	MOV AH, 4Ch
	INT 21h
END