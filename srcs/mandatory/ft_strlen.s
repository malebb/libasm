; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/27 10:28:45 by mlebrun           #+#    #+#              ;
;    Updated: 2021/02/11 18:43:00 by mlebrun          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

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
