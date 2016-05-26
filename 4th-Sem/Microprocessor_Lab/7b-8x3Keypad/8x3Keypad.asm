; Assembly Level Program 7b
; Scan a 8 x 3 keypad for key closure and to store the code of the key pressed in a memory location or display on screen. Also display row and column numbers of the key pressed.  

.model SMALL

PRINTMSG MACRO MSG
	LEA DX, MSG
	MOV AH, 09h
	INT 21h
ENDM

PRINTNUM MACRO NUM
	MOV DL, NUM
	MOV AH, 02h
	INT 21h
ENDM

.data
	PA	EQU	0E400h
	PB	EQU	0E401h
	PC	EQU	0E402h
	CR	EQU	0E403h
	CW	dB	90h
	
	MSG1	dB	10, 13, 'Row Number: $'
	MSG2	dB	10, 13, 'Column Number: $'
	MSG3	dB	10, 13, 'Code: $'
	
	ROW		dB	?
	COL		dB	?
	KEYS	dB	'0123456789ABCDEFGHIJKLMN'
	
.code
	; Initialize Data Segment
	MOV AX, @DATA
	MOV DS, AX
	
	; Set Control Word Format
	MOV DX, CR
	MOV AL, CW
	OUT DX, AL
	
Looper:
	; Listen for Key Press at First Row
	MOV DX, PC
	MOV AL, 01h
	OUT DX, AL
	
	; Scan for User Input from Keypad
	MOV DX, PA
	IN AL, DX
	
	CMP AL, 00h
	JNZ FirstRow
	
	; Listen for Key Press at Second Row
	MOV DX, PC
	MOV AL, 02h
	OUT DX, AL
	
	; Scan for User Input from Keypad
	MOV DX, PA
	IN AL, DX
	
	CMP AL, 00h
	JNZ SecondRow
	
	; Listen for Key Press at Third Row
	MOV DX, PC
	MOV AL, 04h
	OUT DX, AL
	
	; Scan for User Input from Keypad
	MOV DX, PA
	IN AL, DX
	
	CMP AL, 00h
	JNZ ThirdRow
	
	JMP Looper

FirstRow:
	; Move to First Row, First Column
	MOV ROW, 31h
	MOV COL, 31h
	LEA SI, KEYS
	
	Loop1:
		; Divide By 2
		SHR AL, 01h
		JC Display
		
		; Move to Next Column
		INC COL
		; Move to Next Key in Table
		INC SI
	JMP Loop1
	
SecondRow:
	; Move to Second Row, First Column
	MOV ROW, 32h
	MOV COL, 31h
	LEA SI, KEYS+8
	
	Loop2:
		; Divide By 2
		SHR AL, 01h
		JC Display
		
		; Move to Next Column
		INC COL
		; Move to Next Key in Table
		INC SI
	JMP Loop2
	
ThirdRow:
	; Move to Third Row, First Column
	MOV ROW, 33h
	MOV COL, 31h
	LEA SI, KEYS+16
	
	Loop3:
		; Divide By 2
		SHR AL, 01h
		JC Display
		
		; Move to Next Column
		INC COL
		; Move to Next Key in Table
		INC SI
	JMP Loop3
	
Display:
	PRINTMSG MSG1
	PRINTNUM ROW
	
	PRINTMSG MSG2
	PRINTNUM COL
	
	PRINTMSG MSG3
	PRINTNUM [SI]
	
Exit:
	; Terminate the Program
	MOV AH, 4Ch
	INT 21h
END
	
