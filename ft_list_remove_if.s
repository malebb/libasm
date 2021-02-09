; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_list_remove_if.s                                :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/02/08 14:25:08 by mlebrun           #+#    #+#              ;
;    Updated: 2021/02/09 17:42:12 by mlebrun          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global ft_list_remove_if

ft_list_remove_if:
	cmp rdi, 0
	je _end_function	
	cmp qword [rdi], 0
	je _end_function	
	cmp rsi, 0
	je _end_function	
	cmp rdx, 0
	je _end_function	
	cmp rcx, 0
	je _end_function	
	mov r8, rdi
	mov r9, [rdi]
	mov r10, 0
	call _browse_list
	ret


_browse_list:
	cmp qword r9, 0
	jne _check_data
	ret

_check_data:
	mov rdi, [r9]
	push rsi
	push rdi
	push rcx
	push rdx
	call rdx
	pop rdx
	pop rcx
	pop rdi
	pop rsi
	cmp dword eax, 0
	je _delete_elem
	mov r10, r9
	mov r11, [r9 + 8]
	mov r9, r11
	jmp _browse_list

_delete_elem:
	cmp r10, 0
	jne _update_previous
	je _update_first_elem

_update_first_elem:
	mov r11, [r9 + 8]
	mov [r8], r11
	jmp _free_elem

_update_previous:
	push qword [r9 + 8]
	pop r11
	mov [r10 + 8], r11
	jmp _free_elem

_free_elem:
	mov r11, [r9 + 8]
	mov rdi, [r9]
	push rcx
	push rsi
	push rdx
	call rcx
	pop rdx
	pop rsi
	pop rcx
	mov rdi, r9
	push rsi
	push rdx
	push rcx
	call rcx
	pop rcx
	pop rdx
	pop rsi
	mov r9, r11
	jmp _browse_list

_end_function:
	ret
