section .text
	global ft_strlen
ft_strlen:
	mov rax, 0
	call _browse_str
_browse_str:
	cmp byte [rdi], 0
	jne _update
	ret
_update:
	inc rax
	inc rdi
	jmp _browse_str
