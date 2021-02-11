; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_atoi_base.s                                     :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/30 09:46:25 by mlebrun           #+#    #+#              ;
;    Updated: 2021/02/11 18:10:25 by mlebrun          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

extern ft_strlen

section .text
	global ft_atoi_base

ft_atoi_base:
	mov r8, rdi
	mov r9, rsi
	call _check_base
	cmp rax, 0
	je _return
	mov rdi, r8
	mov r10, 0
	call _skip_ws
	mov r10, 0
	mov r11, 1
	call _is_neg
	push rdi
	push r11
	mov rdi, r9
	call ft_strlen
	pop r11
	pop rdi
	mov r10, 0
	mov rdx, 0
	mov rsi, r9
	mov r8, 0
	call _read_nbr
	mul r11
	ret

_read_nbr:
	cmp qword [rdi], 0
	jne _is_in_base
	mov rax, r10
	ret

_is_in_base:
	cmp byte [rsi], 0
	jne _browse_base
	mov rax, r10
	ret

_browse_base:
	push rax
	mov al, byte [rdi]
	cmp byte [rsi], al
	pop rax
	je _add_nbr
	inc rsi
	inc r8
	jmp _is_in_base

_add_nbr:
	push rax
	mov rcx, rax
	mov rax, r10
	mul rcx
	add rax, r8
	mov r10, rax
	pop rax
	mov rsi, r9
	mov r8, 0
	inc rdi
	jmp _read_nbr

_is_neg:
	cmp r10, 1
	jne _is_char_neg
	ret
	
_is_char_neg:
	cmp byte [rdi], 45
	je _change_sign
	cmp byte [rdi], 43
	je _next_sign
	jmp _end_sign

_next_sign:
	inc rdi
	jmp _is_neg

_end_sign:
	mov r10, 1
	jmp _is_neg

_change_sign:
	neg r11
	inc rdi
	jmp _is_neg

_skip_ws:
	cmp r10, 1
	jne _is_char_space
	ret

_is_char_space:
	cmp byte [rdi], 9
	je _next_space
	cmp byte [rdi], 10
	je _next_space
	cmp byte [rdi], 11
	je _next_space
	cmp byte [rdi], 12
	je _next_space
	cmp byte [rdi], 13
	je _next_space
	cmp byte [rdi], 32
	je _next_space
	jmp _end_space

_next_space:
	inc rdi
	jmp _skip_ws

_end_space:
	mov r10, 1
	jmp _skip_ws

_check_base:
	call _empty_size_one
	cmp rax, 0
	je _return
	mov rsi, r9
	call _minus_plus_ws
	cmp rax, 0
	je _return
	mov rdi, r9
	mov rsi, r9
	mov r10, 0
	call _already_here
	cmp rax, 0
	je _return
	ret

_already_here:
	cmp byte [rsi], 0
	jne _browse_already_here
	mov rax, 1
	ret

_browse_already_here:
	mov r11, 0
	mov rdi, r9
	call _in_str_from
	cmp rax, 1
	je _inc_and_loop
	ret

_inc_and_loop:
	inc r10
	jmp _already_here

_in_str_from:
	cmp r11, r10
	jne _in_str
	mov rax, 1
	inc rsi
	ret

_in_str:
	mov al, byte [rsi]
	cmp byte [rdi], al
	je _char_here
	inc rdi
	inc r11
	jmp _in_str_from

_minus_plus_ws:
	cmp byte [rsi], 0
	jne _check_char
	mov rax, 1
	ret

_check_char:
	call _check_unexpected_char
	cmp rax, 1
	je _minus_plus_ws
	mov rax, 0
	ret

_check_unexpected_char:
	cmp byte [rsi], 43
	je _wrong_char
	cmp byte [rsi], 45
	je _wrong_char
	cmp byte [rsi], 9
	je _wrong_char
	cmp byte [rsi], 10
	je _wrong_char
	cmp byte [rsi], 11
	je _wrong_char
	cmp byte [rsi], 12
	je _wrong_char
	cmp byte [rsi], 13
	je _wrong_char
	cmp byte [rsi], 32
	je _wrong_char
	inc rsi
	mov rax, 1
	ret

_return:
	ret

_empty_size_one:
	mov rsi, r9
	cmp byte [rsi], 0
	je _wrong_size
	cmp byte [rsi + 1], 0
	je _wrong_size
	mov rax, 1
	ret

_wrong_size:
	mov rax, 0
	ret
_wrong_char:
	mov rax, 0
	ret
_char_here:
	mov rax, 0
	ret
