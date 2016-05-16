; Assembly Level Program 3b
; Read the status of two 8-bit inputs (X & Y) from the Logic Controller Interface and display X*Y.

.model SMALL

.data
	PA	EQU	0E400h
	PB	EQU	0E401h
	PC	EQU	0E402h
	CR	EQU	0E403h
	CW	dB	80h
	
	M1	dB	10, 13, 'Enter the first 8-bit Number...$'
	M2	dB	10, 13, 'Enter the second 8-bit Number...$'
	
.code
	; Initialize Data Segment
	MOV AX, @DATA
	MOV DS, AX
	
	; Set Control Word Format
	MOV DX, CR
	MOV AL, CW
	OUT DX, AL
	
	; Display Message
	LEA DX, M1
	MOV AH, 09h
	INT 21h
	
	; Read Input from Keyboard, without Echo
	MOV AH, 08h
	INT 21h
	
	; Read Input from Logic Controller Interface
	MOV DX, PB
	IN AL, DX
	
	MOV BL, AL
	
	; Display Message
	LEA DX, M1
	MOV AH, 09h
	INT 21h
	
	; Read Input from Keyboard, without Echo
	MOV AH, 08h
	INT 21h
	
	; Read Input from Logic Controller Interface
	MOV DX, PB
	IN AL, DX
	
	; Multiply BL x AL
	MUL BL
	
	; Display First Byte of AX (AL)
	MOV DX, PA
	OUT DX, AL
	
	CALL Delay
	
	; Display Last Byte of AX (AH)
	MOV DX, PA
	MOV AL, AH
	OUT DX, AL
	
Exit:
	; Terminate the Program
	MOV AH, 4Ch
	INT 21h
	
Delay PROC NEAR
	MOV SI, 0FFFFh
	Loop1:
	MOV DI, 04FFFh
	Loop2:
	DEC DI
	JNZ Loop2
	DEC SI
	JNZ Loop1
	RET
Delay ENDP

END