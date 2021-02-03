; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_list_size.s                                     :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/02/03 14:58:26 by mlebrun           #+#    #+#              ;
;    Updated: 2021/02/03 21:34:25 by mlebrun          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global ft_list_size

ft_list_size:
	cmp rdi, 0
	je _empty_lst
	mov r11, 0
	jmp _browse_lst

_empty_lst:
	mov rax, 0
	ret

_browse_lst:
	inc r11
	push qword [rdi + 8]
	pop r10
	cmp r10, 0
	mov rdi, r10
	je _ret
	jmp _browse_lst

_ret:
	mov rax, r11
	ret
