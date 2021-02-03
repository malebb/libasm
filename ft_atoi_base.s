; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_atoi_base.s                                     :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/30 09:46:25 by mlebrun           #+#    #+#              ;
;    Updated: 2021/02/02 18:35:20 by mlebrun          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global ft_atoi_base

ft_atoi_base:
	call _check_base

_check_base:
	mov rax, 0
	call _str_in_base
	cmp rax, 0
	je _ret
	ret

_ret:
	ret

_str_in_base:
	cmp byte [rdi], 0
	jne _in_str
	ret

_in_str:
	cmp byte [rsi], 0
	jne _cmpstr

_cmpstr:
	mov bl, byte [rdi]
	cmp byte [rsi], bl
	jne _not_equal

_not_equal:
	inc rsi, 
