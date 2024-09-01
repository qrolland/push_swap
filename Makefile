NAME		= push_swap
CFLAGS		= -Wall -Wextra -Werror
LIBFT		= ./libft/libft.a
SRCS		= main.c \
				operations_push.c \
				operations_reverse_rotate.c \
				operations_rotate.c \
				operations_swap.c \
				sort.c \
				t_stack.c \
				stack_utils.c \
				positions.c \
				costs.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@ 

$(LIBFT):
	@make all -C libft
	@make bonus -C libft

$(NAME): $(LIBFT) $(OBJS) 
	gcc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

test2:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test1000:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

clean:
	rm -f $(OBJS) 
	@make clean -C libft

fclean: clean
	rm -f $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: clean fclean all re bonus
