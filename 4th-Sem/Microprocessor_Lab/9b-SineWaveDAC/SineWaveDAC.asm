; Assembly Level Program 9b
; Generate the Sine Wave using DAC interface (The output of the DAC is to be displayed on the CRO). 

.model SMALL

.data
	PA	EQU	0E400h
	PB	EQU	0E401h
	PC	EQU	0E402h
	CR	EQU	0E403h
	CW	dB	80h
	
	TABLE	dB	127, 144, 161, 177, 191, 204, 214, 221, 225, 227, 225, 221, 214, 204, 191, 177, 161, 144, 127, 110, 93, 77, 63, 50, 40, 33, 29, 27, 29, 33, 40, 50, 63, 77, 93, 110, 127
	
.code
	; Initialize Data Segment
	MOV AX, @DATA
	MOV DS, AX
	
	; Set Control Word Format
	MOV DX, CR
	MOV AL, CW
	OUT DX, AL
	
Looper:
	; Number of Values in TABLE
	MOV CX, 37d
	
	; Point SI to the First Position of TABLE
	LEA SI, TABLE
	
	MOV DX, PA
	Repeater:
		; Clear Direction Flag
		CLD
		; Loads [SI] to AL and Auto-Advances SI
		LODSB
		; Send AL to DAC Interface
		OUT DX, AL
	LOOP Repeater
	
	; Wait for User Keyboard Input Interrupt
	MOV AH, 01h
	INT 16h
	JZ Looper
	
Exit:
	; Terminate the Program
	MOV AH, 4Ch
	INT 16h
END