; Assembly Level Program 5b
; Assume any suitable message of 12 characters length and display it in the rolling fashion on a 7-segment display interface for a suitable period of time. Ensure a flashing rate that makes it easy to read both the messages. (Examiner does not specify these delay values nor is it necessary for the student to compute these values).

.model SMALL

.data
	PA	EQU	0E400h
	PB	EQU	0E401h
	PC	EQU	0E402h
	CR	EQU	0E403h
	CW	dB	80h
	
	MSG	dB	0FFh, 0FFh, 0FFh, 0FFh, 8Eh, 0F9h, 88h, 86h, 89h, 86h, 0C7h, 8Ch
	
.code
	; Initialize Data Segment
	MOV AX, @DATA
	MOV DS, AX
	
	; Set Control Word Format
	MOV DX, CR
	MOV AL, CW
	OUT DX, AL
	
Looper:
	; Message Contains 12 Bytes
	MOV CX, 12d
	
	; Point SI to First Position of Message
	LEA SI, MSG
	
	RepeatDisplay:
		CALL Display
		CALL Delay
		
		INC SI
	LOOP RepeatDisplay
	
	; Wait for User Keyboard Input Interrupt
	MOV AH, 01h
	INT 16h
	JZ Looper
	
Exit:
	; Terminate the Program
	MOV AH, 4Ch
	INT 21h
	
Display PROC NEAR
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