NAME = 			push_swap

FILES = 				pushswap.c \
				init.c \
				fill_stack.c \
				build_n_edit_stack.c \
				find_values.c \
				master_sort.c \
				small_sort.c \
				quarter_sort.c \
				rotation.c \
				clean.c \
				push.c \
				reverse_rotate.c \
				rotate.c \
				swap.c \

CFLAGS = -Wall -Wextra -Werror

CC = gcc

OBJS_DIR	= objs
SRCS_DIR 	= srcs
INCS_DIR 	= includes
LIBFT 		= libft

SRC			=	$(addprefix $(SRCS_DIR)/,$(FILES))
OBJS		=	$(SRC:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

.SILENT:

all:			colour	$(NAME)
				echo "\\n\033[32;1m PUSH_SWAP READY TO BOOGIE \033[0m \\n"

$(OBJS_DIR):
				mkdir -p $(OBJS_DIR)

$(OBJS): $(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c $(OBJS_DIR)
				$(CC) $(CFLAGS) -I $(INCS_DIR) -I $(LIBFT) -c $< -o $@

$(NAME):		libft $(OBJS)
				$(CC) $(OBJS) -o $@

libft:
				make -C $(LIBFT)
				echo "\\n\033[32;1m making libft... \033[0m \\n"
				echo "\\n\033[32;1m libft made. \033[0m \\n"

colour:
				echo "\x1b[36m""\x1b[1A\x1b[M"

clean:
				rm -rf $(OBJS_DIR)
				make -C $(LIBFT) clean
				echo "\\n\033[32;1m cleaning up your shit... \033[0m \\n"
				echo "\\n\033[32;1m cleaned up, your welcome you slob. \033[0m \\n"

fclean:			
				rm -rf $(OBJS_DIR)
				make -C $(LIBFT) clean
				rm -rf $(NAME)
				make -C $(LIBFT) fclean
				echo "\\n\033[32;1m spring cleaning.. \033[0m \\n"
				echo "\\n\033[32;1m okay done. god im gonna need therapy after that. the things i found... \033[0m \\n"

re:				fclean	all
				echo "\\n\033[32;1m god let that be the last time. im serious, im tired. \033[0m \\n"