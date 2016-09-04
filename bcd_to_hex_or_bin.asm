org 100h
mov ax,b_in
call con
mov b_out,ax
nop
nop
con proc near
    mov bx,ax 
    mov ax,bx  
    mov cx,0000h
    and ax,000fh
    add cx,ax
    mov ax,bx
    and ax,00f0h
    ror ax,0004h
    mov dx,000Ah
    mul dx
    add cx,ax 
    mov ax,bx
    and ax,0f00h
    ror ax,0008h
    mov dx,0064h
    mul dx
    add cx,ax
    mov ax,bx
    and ax,0f000h
    ror ax,000Ch
    mov dx,03E8h
    mul dx
    add cx,ax
    mov ax,cx 
    ret
con endp    
          

b_in dw 4596h
b_out dw ?