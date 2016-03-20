; Assembly Level Program 5a
; Reverse a given string and check whether it is a palindrome or not. 

.model SMALL

PRINTSTR MACRO MSG
	LEA DX, MSG
	MOV AH, 09h
	INT 21h
ENDM

READSTR	MACRO BUF
	LEA DX, BUF
	MOV AH, 0Ah
	INT 21h
ENDM

.data
	BUF1	dB	20d
	LEN1	dB	?
	STR1	dB	20d	DUP(0)
	
	RSTR	dB	20d	DUP(0)
	
	MSG1	dB	10, 13, 'Enter a String: $'
	MSG2	dB	10, 13, 'String is a Palindrome!$'
	MSG3	dB	10, 13, 'String is not a Palindrome!$'
	
.code
	MOV AX, @DATA
	MOV DS, AX
	MOV ES, AX
	
	PRINTSTR MSG1
	READSTR BUF1
	
	LEA SI, STR1
	DEC SI
	
	MOV CX, 00h
	MOV CL, LEN1
	
	ADD SI, CX
	MOV DI, SI
	
	LEA SI, RSTR
	
CopyString:
	MOV AL, [DI]
	MOV [SI], AL
	INC SI
	DEC DI
	LOOP CopyString
	
	LEA SI, STR1
	LEA DI, RSTR
	
	MOV CX, 00h
	MOV CL, LEN1
	CLD ; Clear Direction Flag
	
	REPE CMPSB
	JE Palindrome
	
	PRINTSTR MSG3
	JMP Exit
	
Palindrome:
	PRINTSTR MSG2
	
Exit:
	MOV AH, 4Ch
	INT 21h
END