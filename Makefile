SRCS=ft_alloca.c ft_alloca_raw_memory.c ft_alloca_thread.c
OBJS=$(patsubst %.c,%.o, $(SRCS))

libft_alloca.a: ft_alloca.h $(OBJS)
	ar rc libft_alloca.a $(OBJS)

%.o: %.c
	gcc -Wall -Werror -Wextra -c $< -o $@
