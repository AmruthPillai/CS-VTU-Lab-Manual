; Assembly Level Program 12b
; Drive an elevator interface in the following way:  
; i. Initially the elevator should be in the ground floor, with all requests in OFF state.  
; ii. When a request is made from a floor, the elevator should move to that floor, wait there for a couple of seconds (approximately), and then come down to ground floor and stop. If some requests occur during going up or coming down they should be ignored.  

.model SMALL

.data
	PA	EQU	0E400h
	PB	EQU	0E401h
	PC	EQU	0E402h
	CR	EQU	0E403h
	CW	dB	82h
	
	CLEAR	dB	0E0h, 0D0h, 0B0h, 70h
	
.code
	; Initialize Data Segment
	MOV AX, @DATA
	MOV DS, AX
	
	; Set Control Word Format
	MOV DX, CR
	MOV AL, CW
	OUT DX, AL
	
	; Move to Ground Floor Initially
	MOV DX, PA
	MOV AL, 0Fh
	OUT DX, AL
	
	; Point SI to First Position of CLEAR
	LEA SI, CLEAR
	
NoRequest:
	CALL Request
	JZ NoRequest
	
	SHR AL, 01h
	JNC GroundFloor
	SHR AL, 01h
	JNC FirstFloor
	SHR AL, 01h
	JNC SecondFloor
	JMP ThirdFloor
	
GroundFloor:
	CALL Delay
	CALL Reset
	JMP Exit

FirstFloor:
	MOV CX, 03h
	LEA SI, CLEAR+1
	
	CALL MoveUp
	CALL Delay
	CALL Reset
	
	MOV CX, 03h
	CALL MoveDown
	JMP Exit
	
SecondFloor:
	MOV CX, 06h
	LEA SI, CLEAR+2
	
	CALL MoveUp
	CALL Delay
	CALL Reset
	
	MOV CX, 06h
	CALL MoveDown
	JMP Exit
	
ThirdFloor:
	MOV CX, 09h
	LEA SI, CLEAR+3
	
	CALL MoveUp
	CALL Delay
	CALL Reset
	
	MOV CX, 09h
	CALL MoveDown
	
Exit:
	MOV AH, 4Ch
	INT 21h
	
Request PROC NEAR
	; Wait for Key Press from User
	MOV DX, PB
	IN AL, DX
	; Logical AND with Lower Nibble of AL
	AND AL, 0Fh
	CMP AL, 0Fh
	RET
Request ENDP

Reset PROC NEAR
	PUSH AX
	MOV DX, PA
	; Fetch Value from CLEAR Table
	MOV AL, [SI]
	OUT DX, AL
	POP AX
	RET
Reset ENDP

MoveUp PROC NEAR
	MOV AL, 0F0H
	MOV DX, PB
	
	GoUp:
		OUT DX, AL
		CALL Delay
		INC AL
	Loop GoUp
	
	OUT DX, AL
	RET
MoveUp ENDP

MoveDown PROC NEAR
	MOV DX, PB
	
	GoDown:
		OUT DX, AL
		CALL Delay
		DEC AL
	Loop GoDown
	
	OUT DX, AL
	RET
MoveDown ENDP

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