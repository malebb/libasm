; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_read.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/28 17:32:04 by mlebrun           #+#    #+#              ;
;    Updated: 2021/02/11 18:59:08 by mlebrun          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

extern __errno_location

section .text
	global ft_read

ft_read:
	mov rax, 0
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
