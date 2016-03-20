; Assembly Level Program 11a
; Generate the first ‘n’ Fibonacci numbers.

.MODEL SMALL
.STACK
.DATA
ARR DB 20 DUP(?)
COUNT DB 0Ah
msg db "The fibonacci series : ",13,10,"$"
.CODE
MOV AX,@DATA
MOV DS,AX
MOV SI,00H
MOV AX,00H
MOV ARR[SI],AL
INC SI
mov bx,01h
MOV ARR[SI],bl
INC SI
MOV CH,COUNT
SUB CH,02H
BACK: ADD AX,BX
MOV ARR[SI],AL
INC SI
xchg ax,bx
DEC CH
JNZ BACK
lea dx,msg
mov ah,9
int 21h
call disp
MOV AH,4CH
INT 21H
disp proc near
mov si,00h
mov ch,count
loop1: mov al,arr[si]
mov ah,0
aam
add ax,3030h
mov dl,ah
mov ah,2
push ax
int 21h
pop ax
mov dl,al
int 21h
mov ah,2
mov dl, ' '
int 21h
inc si
dec ch
jnz loop1
ret
disp endp
END