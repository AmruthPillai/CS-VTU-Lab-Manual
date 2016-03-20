; Assembly Level Program 3a
; Sort a given set of 'n' numbers in ascending and descending orders using the Bubble Sort algorithm.

.model SMALL

.data
	ARRAY	dB	05h, 07h, 06h, 04h, 10h, 09h
	LEN		dB	$-ARRAY
	
.code
	MOV AX, @DATA
	MOV DS, AX
	
	MOV CX, 00h
	MOV CL, LEN
	DEC CL
	
OuterLoop:
	MOV BX, CX
	LEA SI, ARRAY
	
InnerLoop:
	MOV AL, [SI]
	INC SI
	CMP [SI], AL
	JBE NoSwap
	
	XCHG [SI], AL
	MOV [SI-1], AL
	
NoSwap:
	DEC BX
	JNZ InnerLoop
	
	LOOP OuterLoop
	
Exit:
	MOV AH, 4Ch
	INT 21h
END