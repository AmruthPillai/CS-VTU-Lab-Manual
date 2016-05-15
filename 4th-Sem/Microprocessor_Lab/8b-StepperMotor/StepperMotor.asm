; Assembly Level Program 8b
; Drive a Stepper Motor interface to rotate the motor in specified direction (clockwise or counter-clockwise) by N steps (Direction and N are specified by the examiner). Introduce suitable delay between successive steps. (Any arbitrary value for the delay may be assumed by the student).  

.model SMALL

.data
	PA	EQU	0E400h
	PB	EQU	0E401h
	PC	EQU	0E402h
	CR	EQU	0E403h
	CW	dB	80h
	
.code
	; Initialize Data Segment
	MOV AX, @DATA
	MOV DS, AX
	
	; Set Control Word Format
	MOV DX, CR
	MOV AL, CW
	OUT DX, AL
	
	; 360 Degree Rotation (200x1.8)
	MOV CX, 200d
	MOV DX, PA
	MOV AL, 88h
	
Rotate:
	; Rotate Clockwise
	ROR AL, 01h
	
	; Rotate Counter-Clockwise
	; ROL AL, 01h
	
	OUT DX, AL	
	CALL Delay
	
	LOOP Rotate
	
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
	