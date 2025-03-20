# Değişkenler
NAME            = push_swap
LIBFT           = ./libft/libft.a
PRINTF          = ./printf/libftprintf.a
INC             = inc/
SRC_DIR         = push_swap_main/
AUX_DIR         = auxiliary/
OBJ_DIR         = obj/
CC              = gcc
CFLAGS          = -Wall -Werror -Wextra -I ./inc -I ./srcs/libft -I ./srcs/printf
RM              = rm -f

# Kaynak dosyaları
SRC_FILES       = handle_error_a.c \
                  init_a_to_b.c \
                  init_b_to_a.c \
                  push_swap.c \
                  free_stack_arg.c \
                  stack_setup.c \
                  add_node.c

AUX_FILES       = move_b_to_a.c \
                  push.c \
                  rev_rotate.c \
                  rotate.c \
                  setup_three.c \
                  sort_stacks.c \
                  stack_utils.c \
                  swap_a_b.c

# SRC ve AUX dosyalarını birleştir
SRCS            = $(addprefix $(SRC_DIR), $(SRC_FILES)) \
                  $(addprefix $(AUX_DIR), $(AUX_FILES))

# Nesne dosyalarını oluştur
OBJ             = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))

# Derleme işlemi
all: $(NAME)

# İlgili dosyaları birleştirerek çalıştırılabilir dosyayı oluştur
$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

# LIBFT'yi derle
$(LIBFT):
	@make -C ./libft

# PRINTF'yi derle
$(PRINTF):
	@make -C ./printf

# Nesne dosyalarını derle
$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)  # Her dosyanın bulunduğu dizini oluştur
	@$(CC) $(CFLAGS) -c $< -o $@

# Temizlik işlemi
clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./libft
	@make clean -C ./printf

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@$(RM) $(PRINTF)

# Yeniden derleme
re: fclean all

# Makefile hedefleri
.PHONY: all clean fclean re
