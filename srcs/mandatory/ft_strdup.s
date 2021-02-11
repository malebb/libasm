; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/28 18:52:43 by mlebrun           #+#    #+#              ;
;    Updated: 2021/02/11 18:45:15 by mlebrun          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

extern malloc
extern ft_strlen
extern ft_strcpy

section .text
	global ft_strdup

ft_strdup:
	mov rdx, rdi
	push rdx
	call ft_strlen
	mov rdi, rax
	inc rdi
	call malloc
	pop rsi
	mov rdi, rax
	push rax
	call ft_strcpy
	pop rax
	ret
