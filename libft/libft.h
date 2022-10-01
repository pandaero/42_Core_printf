/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:26:47 by pandalaf          #+#    #+#             */
/*   Updated: 2022/06/03 11:18:40 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//Function determines whether input character is alphabetic.
int		ft_isalpha(int ch);
//Function takes a lowercase letter character and makes it an uppercase letter.
int		ft_toupper(int ch);
//Function determines whether input character is a digit.
int		ft_isdigit(int ch);
//Function takes an uppercase letter character and makes it a lowercase letter.
int		ft_tolower(int ch);
//Function determinse whether input character is alphanumeric.
int		ft_isalnum(int ch);
//Function determines whether input is in the standard ASCII table.
int		ft_isascii(int ch);
//Function determines whether input is a printing character.
int		ft_isprint(int ch);
//Function determines length of the character string.
size_t	ft_strlen(const char *str);
//Function looks for a character within a character string pointer.
char	*ft_strchr(const char *str, int ch);
//Function looks for the last instance of a character within a string pointer.
char	*ft_strrchr(const char *str, int ch);
//Function compares two strings, gives difference when not equal.
int		ft_strncmp(const char *str1, const char *str2, size_t n);
//Function writes a value to a determined length of bytes to a memory location.
void	*ft_memset(void *byte, int ch, size_t n);
//Function sets determined length of memory in a memory location to zero.
void	ft_bzero(void *str, size_t len);
//Function locates the first instance of a character within n bytes of a string.
void	*ft_memchr(const void *str, int ch, size_t n);
//Function compares two memory strings for equality within n bytes of a string.
int		ft_memcmp(const void *str1, const void *str2, size_t n);
//Function copies n bytes (char 8-bits) from a string to a different string.
void	*ft_memcpy(void *dst, const void *src, size_t n);
//Function moves n bytes (char 8-bits) from source string to dest string.
void	*ft_memmove(void *dst, const void *src, size_t n);
//Function writes to n bytes of a char string from a source to a destination.
size_t	ft_strlcpy(char *dst, const char *src, size_t sizedst);
//Function appends n bytes of a source character string to a destination string.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
//Function locates string within n in another string. Returns ptr to location.
char	*ft_strnstr(const char *srch, const char *term, size_t srlen);
//Function interprets a character string to return an integer type.
int		ft_atoi(const char *str);
//Function allocates memory for a number of objects of a certain size in bytes.
void	*ft_calloc(size_t count, size_t size);
//Function duplicates a string to a new memory location.
char	*ft_strdup(const char *str);
//Function creates new character string from another character string's content.
char	*ft_substr(char const *s, unsigned int start, size_t len);
//Function concatenates two character strings, creates a new char string.
char	*ft_strjoin(char const *s1, char const *s2);
//Function creates a new char string with chars from the input removed.
char	*ft_strtrim(char const *s1, char const *set);
//Function splits a char string into char strings between delimeter chars.
char	**ft_split(char const *str, char ch);
//Function writes an integer value to a character string.
char	*ft_itoa(int n);
//Function maps a function to an input character string.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
//Function applies another function to the entered string.
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
//Function writes character to input file descriptor.
void	ft_putchar_fd(char c, int fd);
//Function writes a string to the input file descriptor.
void	ft_putstr_fd(char *s, int fd);
//Function writes a string to the input file descriptor and an end-of-line char.
void	ft_putendl_fd(char *s, int fd);
//Function writes an integer as character to the input file descriptor.
void	ft_putnbr_fd(int n, int fd);
//Function creates a new node in the linked list.
t_list	*ft_lstnew(void *content);
//Function sets a new node to the beginning of a linked list.
void	ft_lstadd_front(t_list **lst, t_list *new);
//Function determines the number of nodes in the linked list.
int		ft_lstsize(t_list *lst);
//Function finds the last node of the linked list.
t_list	*ft_lstlast(t_list *lst);
//Function sets a new node to the end of a linked list.
void	ft_lstadd_back(t_list **lst, t_list *new);
//Function deletes a node from a linked list.
void	ft_lstdelone(t_list *lst, void (*del)(void *));
//Function clears an entire linked list.
void	ft_lstclear(t_list **lst, void (*del)(void *));
//Function applies a function to each of the linked list's nodes.
void	ft_lstiter(t_list *lst, void (*f)(void *));
//Function maps a function to every node's content in a linked list.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif
