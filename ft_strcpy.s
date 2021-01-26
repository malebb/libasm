section .text
	global ft_strcpy
ft_strcpy:
	mov rax, rdi
	call _browse
	ret
_browse:
	cmp byte [rsi], 0
	jne cpy_char
	mov byte [rdi], 0
	ret
cpy_char:
	mov cl, byte [rsi]
	mov [rdi], cl
	inc rdi
	inc rsi
	jmp _browse
