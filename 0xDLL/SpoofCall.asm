	.code
	PUBLIC _spoofer_stub

    _spoofer_stub PROC
        pop r11
        add rsp, 8
        mov rax, [rsp + 24]
        
        mov r10, [rax]
        mov [rsp], r10
        
        mov r10, [rax + 8]
        mov [rax + 8], r11
     
        mov [rax + 16], rbx
        lea rbx, fixup
        mov [rax], rbx
        mov rbx, rax
        
        jmp r10
     
    fixup:
        sub rsp, 16
        mov rcx, rbx
        mov rbx, [rcx + 16]
        jmp QWORD PTR [rcx + 8]
    _spoofer_stub ENDP

	PUBLIC _checksum_fake
	_checksum_fake PROC
	mov rax, 0
	ret
   _checksum_fake ENDP

   	PUBLIC _screenshot_bypass
	_screenshot_bypass PROC
	mov eax,00000018
	ret
   _screenshot_bypass ENDP
     
    END



