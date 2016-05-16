; Assembly Level Program 12a
; Write an Assembly Level Program to create a file with a given File Name

.model SMALL

.data
	FNAME	dB	'SampleFile.txt', 00h
	SUCCESS	dB	10, 13, 'File has been created successfully!$'
	FAILURE	dB	10, 13, 'An Error Occured during File Creation!$'
	
.code
	; Initialize Data Segment
	MOV AX, @DATA
	MOV DS, AX
	
	; Set File Attribute
	MOV CX, 20h
	
	; Interrupt to Create a File
	LEA DX, FNAME
	MOV AH, 3Ch
	INT 21h
	JC ErrorOccured
	
	; Display Success Message
	LEA DX, SUCCESS
	MOV AH, 09h
	INT 21h
	JMP Exit
	
ErrorOccured:
	; Display Error Message
	LEA DX, FAILURE
	MOV AH, 09h
	INT 21h
	
Exit:
	; Terminate the Program
	MOV AH, 4Ch
	INT 21h
END