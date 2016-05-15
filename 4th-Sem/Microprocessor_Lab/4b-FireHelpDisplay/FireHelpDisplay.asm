; Assembly Level Program 4b
; Display messages FIRE and HELP alternately with flickering effects on a 7-segment display interface for a suitable period of time. Ensure a flashing rate that makes it easy to read both the messages (Examiner does not specify these delay values nor is it necessary for the student to compute these values).

.model SMALL

.data
	PA	EQU	0E400h
	PB	EQU	0E401h
	PC	EQU	0E402h
	CR	EQU	0E403h
	CW	dB	80h
	
	M1	dB	86h, 0AFh, 0F9h, 8Eh	; E, R, I, F
	M2	dB	8Ch, 0C7h, 86h, 89h		; P, L, E, H
	
.code
	; Initialize Data Segment
	MOV AX, @DATA
	MOV DS, AX
	
	; Set Control Word Format
	MOV DX, CR
	MOV AL, CW
	OUT DX, AL
	
Looper:
	; Point SI to First Position of M1
	LEA SI, M1
	
	CALL Display
	CALL Delay
	
	; Point SI to First Position of M2
	LEA SI, M2
	
	CALL Display
	CALL Delay
	
	; Wait for User Keyboard Input Interrupt
	MOV AH, 01h
	INT 16h
	JZ Looper
	
Exit:
	; Terminate the Program
	MOV AH, 4Ch
	INT 21h
	
Display PROC NEAR
	; Each Message Contains 4 Bytes
	MOV CX, 04h
	
	L2:
		; Each Character Contains 8 Bits
		MOV BL, 08h
		MOV AL, [SI]
		
		L1:
			; Rotate AL without Carry
			ROL AL, 01h
			MOV DX, PB
			OUT DX, AL
			
			PUSH AX
			
			; Toggle 0 to Port C
			MOV DX, PC
			MOV AL, 00h
			OUT DX, AL
			
			; Toggle 1 to Port C
			MOV DX, PC
			MOV AL, 01h
			OUT DX, AL
			
			POP AX
			
			DEC BL
		JNZ L1
		
		INC SI
	LOOP L2
	
	RET
Display ENDP

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