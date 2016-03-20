; Assembly Level Program 15a
; Write an Assembly Level Program to create a file with a given File Name

.model SMALL

.data
	FNAME	dB	'SampleFile.txt', 00h
	SUCCESS	dB	10, 13, 'File has been created successfully!$'
	FAILURE	dB	10, 13, 'An Error Occured during File Creation!$'
	
.code
	MOV AX, @DATA
	MOV DS, AX
	
	MOV CX, 20h
	
	; Interrupt to Create a File
	LEA DX, FNAME
	MOV AH, 3Ch
	INT 21h
	JC ErrorOccured
	
	LEA DX, SUCCESS
	MOV AH, 09h
	INT 21h
	JMP Exit
	
ErrorOccured:
	LEA DX, FAILURE
	MOV AH, 09h
	INT 21h
	
Exit:
	MOV AH, 4Ch
	INT 21h
END