; Assembly Level Program 1a
; Search a key element in a list of ‘n’ 16-bit numbers using the binary search algorithm.

.model SMALL

.data
	ARRAY	dW	1234h, 2345h, 3456h, 4567h, 5678h, 6789h
	LEN		dW	($-ARRAY)/2
	KEY		dW	6789h
	
	STR1	dB	10, 13, 'Element Found at Position '
	POS		dB	?, 10, 13, '$'
	STR2	dB	10, 13, 'Element Not Found!$'
	
.code
	; Initialize Data Segment
	MOV AX, @DATA
	MOV DS, AX
	
	; Clear AX Register
	MOV AX, 00h
	
	MOV CX, LEN
	MOV DX, KEY
	
Search:
	CMP CX, AX
	JB NotFound
	
	MOV BX, CX
	ADD BX, AX
	SHR BX, 01h ; Divides by 2
	
	MOV SI, BX
	SHL SI, 01h ; Multiply with 2
	
	CMP ARRAY[SI], DX
	JB newLow
	JE Found
	
	CMP BX, 00h
	JE NotFound
	
	DEC BX
	MOV CX, BX
	JMP Search
	
newLow:
	INC BX
	MOV AX, BX
	JMP Search
	
Found:
	INC BL
	; Convert BL to ASCII
	ADD BL, 30h
	MOV POS, BL
	LEA DX, STR1
	JMP Display
	
NotFound:
	LEA DX, STR2
	
Display:
	; Display Message
	MOV AH, 09h
	INT 21h
	
Exit:
	; Terminate the Program
	MOV AH, 4Ch
	INT 21h
END