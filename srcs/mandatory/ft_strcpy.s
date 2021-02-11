; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/27 10:28:29 by mlebrun           #+#    #+#              ;
;    Updated: 2021/02/11 18:50:33 by mlebrun          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

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
