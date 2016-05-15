; Assembly Level Program 3a
; Sort a given set of 'n' numbers in ascending and descending orders using the Bubble Sort algorithm.

.model SMALL

.data
	ARRAY	dB	05h, 07h, 06h, 04h, 10h, 09h
	LEN		dB	$-ARRAY
	
.code
	; Initialize Data Segment
	MOV AX, @DATA
	MOV DS, AX
	
	; Clear Counter Register
	MOV CX, 00h
	
	MOV CL, LEN
	DEC CL
	
OuterLoop:
	MOV BX, CX
	
	; Point SI to First Position of ARRAY
	LEA SI, ARRAY
	
InnerLoop:
	MOV AL, [SI]
	INC SI
	CMP [SI], AL
	JAE NoSwap
	
	XCHG [SI], AL
	MOV [SI-1], AL
	
NoSwap:
	DEC BX
	JNZ InnerLoop
	
	LOOP OuterLoop
	
Exit:
	; Terminate the Program
	MOV AH, 4Ch
	INT 21h
END