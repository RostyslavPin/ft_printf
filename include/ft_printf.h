#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int					ft_printf(const char *format, ...);
void				ft_putchar_unicode(unsigned int c);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putnbr(int n);
size_t				ft_strlen(const char *s);
int					ft_isdigit(int c);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strnew(size_t size);
void				ft_putstr(char const *s);

#endif
