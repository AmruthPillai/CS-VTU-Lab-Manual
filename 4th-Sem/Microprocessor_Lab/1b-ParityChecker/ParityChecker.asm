; Assembly Level Program 1b
; Read the status of eight input bits from the Logic Controller Interface and display 'FF' if it is the parity of the input read is even; otherwise display 00.

.model SMALL

.data
	PA	EQU	0E400h
	PB	EQU	0E401h
	PC	EQU	0E402h
	CR	EQU	0E403h
	CW	dB	82h
	M1	dB	10, 13, 'Select an 8-bit Number from the Logic Controller Interface...$'
	
.code
	MOV AX, @DATA
	MOV DS, AX
	
	MOV DX, CR
	MOV AL, CW
	OUT DX, AL
	
	LEA DX, M1
	MOV AH, 09h
	INT 21h
	
	MOV DX, PB
	IN AL, DX
	
	OR AL, AL
	JPO OddParity
	
	MOV DX, PA
	MOV AL, 0FFh
	OUT DX, AL
	JMP Exit
	
OddParity:
	MOV DX, PA
	MOV AL, 00h
	OUT DX, AL
	
Exit:
	MOV AH, 4Ch
	INT 21h
END