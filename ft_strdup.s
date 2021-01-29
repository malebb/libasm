; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/28 18:52:43 by mlebrun           #+#    #+#              ;
;    Updated: 2021/01/29 11:11:34 by mlebrun          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

extern malloc
extern ft_strlen
extern ft_strcpy

section .data
	text db "Hello"

section .text
	global ft_strdup
	global _browse_strs

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
