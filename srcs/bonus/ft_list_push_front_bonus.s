; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_list_push_front.s                               :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/02/04 14:27:45 by mlebrun           #+#    #+#              ;
;    Updated: 2021/02/08 14:14:26 by mlebrun          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

extern malloc

section .text
	global ft_list_push_front

ft_list_push_front:
	jmp _check_arg

_check_arg:
	cmp rdi, 0
	je _end
	cmp rsi, 0
	je _end

_create_elem:
	push rdi
	mov rdi, 16
	push rsi
	call malloc
	pop rsi
	mov [rax], rsi
	pop r10
	mov r11, [r10]
	mov [rax + 8], r11

_update_first_elem:
	mov [r10], rax
	ret

_end:
	ret
