
#ifndef TEST_H
# define TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dest, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fd, const void *buf, size_t count);
ssize_t		ft_read(int fd, void *buf, size_t count);
char		*ft_strdup(const char *s);
int			ft_atoi_base(char *str, char *base);
int			atoi_base(char *str, char *base);
int			ft_list_size(t_list *begin_list);
void		ft_list_push_front(t_list **begin_list, void *data);
void		fill_address(char *dst, char *src);
void 		ft_list_sort(t_list **begin_list, int (*cmp)());
void		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

#endif
