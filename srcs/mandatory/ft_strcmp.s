; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/27 10:27:55 by mlebrun           #+#    #+#              ;
;    Updated: 2021/02/11 18:53:54 by mlebrun          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global ft_strcmp

ft_strcmp:
	cmp byte [rdi], 0
	jne _cmpchar
	cmp byte [rsi], 0
	jne _inferior
	mov rax, 0
	ret

_cmpchar:
	cmp byte [rsi], 0
	je _superior
	mov al, byte [rsi]
	cmp byte [rdi], al
	jl _inferior
	jg _superior
	inc rdi
	inc rsi
	jmp ft_strcmp

_inferior:
	mov rax, -1
	ret
	
_superior:
	mov rax, 1
	ret
