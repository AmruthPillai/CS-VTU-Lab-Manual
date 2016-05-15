; Assembly Level Program 6a
; Read two strings, store them in locations STR1 and STR2. Check whether they are equal or not and display appropriated messages. Also display the length of the stored strings.

.model SMALL

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
	; Initialize Data & Extra Segment
	MOV AX, @DATA
	MOV DS, AX
	MOV ES, AX
	
	; Display Message
	LEA DX, MSG1
	MOV AH, 09h
	INT 21h
	
	; Read String from Keyboard
	READSTR BUF1
	
	; Display Message
	LEA DX, MSG2
	MOV AH, 09h
	INT 21h
	
	; Read String from Keyboard
	READSTR BUF2
	
	; Display Message
	LEA DX, MSG3
	MOV AH, 09h
	INT 21h
	
	; Display Length of First String
	MOV AL, LEN1
	ADD AL, 30h
	MOV AH, 02h
	INT 21h
	
	; Display Message
	LEA DX, MSG4
	MOV AH, 09h
	INT 21h
	
	; Display Length of Second String
	MOV AL, LEN2
	ADD AL, 30h
	MOV AH, 02h
	INT 21h
	
	; Compare Size of Both Strings
	MOV CL, LEN1
	CMP CL, LEN2
	JNE NotEqual
	
	; Point SI to First Position of STR1
	LEA SI, STR1
	; Point DI to First Position of STR2
	LEA DI, STR2
	
	; Clear and Set Counter Register
	MOV CH, 00h
	MOV CL, LEN1
	
	; Clear Direction Flag
	CLD
	
	; Repeatedly Compare String Byte-by-Byte
	REPE CMPSB
	JE Equal
	
NotEqual:
	; Display Message
	LEA DX, MSG6
	MOV AH, 09h
	INT 21h
	JMP Exit
	
Equal:
	; Display Message
	LEA DX, MSG5
	MOV AH, 09h
	INT 21h
	
Exit:
	; Terminate the Program
	MOV AH, 4Ch
	INT 21h
END