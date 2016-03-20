; Assembly Level Program 6a
; Read two strings, store them in locations STR1 and STR2. Check whether they are equal or not and display appropriated messages. Also display the length of the stored strings.

.model SMALL

PRINTSTR MACRO MSG
	LEA DX, MSG
	MOV AH, 09h
	INT 21h
ENDM

READSTR MACRO BUF
	LEA DX, BUF
	MOV AH, 0Ah
	INT 21h
ENDM

.data
	BUF1	dB	20d
	LEN1	dB	?
	STR1	dB	20d DUP(0)
	
	BUF2	dB	20d
	LEN2	dB	?
	STR2	dB	20d DUP(0)
	
	MSG1	dB	10, 13, 'Enter String 1: $'
	MSG2	dB	10, 13, 'Enter String 2: $'
	
	MSG3	dB	10, 13, 'Length of String 1: $'
	MSG4	dB	10, 13, 'Length of String 2: $'
	
	MSG5	dB	10, 13, 'Strings are Equal!$'
	MSG6	dB	10, 13, 'Strings are Not Equal!$'
	
.code
	MOV AX, @DATA
	MOV DS, AX
	MOV ES, AX
	
	PRINTSTR MSG1
	READSTR BUF1
	
	PRINTSTR MSG2
	READSTR BUF2
	
	MOV CL, LEN1
	CMP CL, LEN2
	JNE NotEqual
	
	LEA SI, STR1
	LEA DI, STR2
	
	MOV CH, 00h
	MOV CL, LEN1
	CLD ; Clear Direction Flag
	
	REPE CMPSB ; Compare String Byte-by-Byte
	JE Equal
	
NotEqual:
	PRINTSTR MSG6
	JMP Exit
	
Equal:
	PRINTSTR MSG5
	
Exit:
	MOV AH, 4Ch
	INT 21h
END