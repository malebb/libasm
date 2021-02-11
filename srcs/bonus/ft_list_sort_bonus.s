; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_list_sort.s                                     :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/02/05 18:43:41 by mlebrun           #+#    #+#              ;
;    Updated: 2021/02/08 13:57:11 by mlebrun          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global ft_list_sort

ft_list_sort:
	cmp rsi, 0
	je _end_prog
	cmp rdi, 0
	je _end_prog
	cmp qword [rdi], 0
	je _end_prog
	mov rcx, rsi
	mov r9, [rdi]
	mov r10, [rdi]
	call browse_lst
	ret

browse_lst:
	cmp qword [r9 + 8], 0
	jne _sort_data
	ret

_sort_data:
	mov rdi, [r9]
	mov rdx, [r9 + 8]
	mov rsi, [rdx]
	push rsi
	push r10
	push rdx
	call rcx
	cmp eax, 0
	pop rdx
	pop r10
	pop rsi
	jg _switch_data
	push qword [r9 + 8]
	pop r9
	jmp browse_lst

_switch_data:
	push qword rdi
	mov [r9], rsi
	pop rdi
	mov [rdx], rdi
	mov r9, r10
	jmp browse_lst

_end_prog:
	ret
