

EXTERN  FuncIndex : DD; 引用外部变量
.CODE
Asm_SysCall PROC
mov r10,rcx
mov eax,dword ptr[FuncIndex]
syscall
ret
Asm_SysCall ENDP

END