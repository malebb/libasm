; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_write.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/28 10:59:18 by mlebrun           #+#    #+#              ;
;    Updated: 2021/02/11 18:56:37 by mlebrun          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

extern __errno_location

section .text
	global ft_write

ft_write:
	mov rax, 1
	syscall
	cmp rax, 0
	jl error
	ret

error:
	neg rax
	push rax
	call __errno_location
	pop qword [rax]
	mov rax, -1
	ret
