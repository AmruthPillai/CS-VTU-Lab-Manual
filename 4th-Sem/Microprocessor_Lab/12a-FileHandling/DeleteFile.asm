; Assembly Level Program 12a
; Write an Assembly Level Program to delete an existing file

.model SMALL

.data
	FNAME	dB	'SampleFile.txt', 00h
	SUCCESS	dB	10, 13, 'File has been deleted successfully!$'
	FAILURE	dB	10, 13, 'An Error Occured during File Deletion!$'
	
.code
	; Initialize Data Segment
	MOV AX, @DATA
	MOV DS, AX
	
	; Set File Attribute
	MOV CX, 20h
	
	; Interrupt to Delete a File
	LEA DX, FNAME
	MOV AH, 41h
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