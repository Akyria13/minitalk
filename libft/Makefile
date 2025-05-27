########################################################################################################################
#                                                      VARIABLES                                                       #
########################################################################################################################\

AUTHOR			:=		jowagner
NAME			:=		libft.a

AR				:=		ar rcs
CC				:=		cc
CFLAGS			:=		-Wall -Wextra -Werror -MD -MP -Iinc/

########################################################################################################################
#                                                      DIRECTORY                                                       #
########################################################################################################################

DIR_LIBFT 		:= 		src/
OBJ_DIR			:=		obj_libft/
DIR_PRINTF		:= 		./ft_printf
DIR_GNL			:=		./get_next_line
INC_LIBFT 		:= 		./inc/libft.h
INC_PRINTF		:=		./inc/ft_printf.h
INC_GNL			:= 		./inc/get_next_line.h

LIBFT_SRC		:=		$(addprefix src/, $(addsuffix .c, \
						ft_bzero \
						ft_calloc \
						ft_isalnum \
						ft_isalpha \
						ft_isascii \
						ft_atoi \
						ft_isdigit \
						ft_isprint \
						ft_memchr \
						ft_memcmp \
						ft_memcpy \
						ft_memmove \
						ft_memset \
						ft_strchr \
						ft_strdup \
						ft_strlcat \
						ft_strlcpy \
						ft_strncmp \
						ft_strnstr \
						ft_strrchr \
						ft_tolower \
						ft_toupper \
						ft_substr \
						ft_strjoin \
						ft_strtrim \
						ft_split \
						ft_itoa \
						ft_strmapi \
						ft_striteri \
						ft_putchar_fd \
						ft_putstr_fd \
						ft_putendl_fd \
						ft_putnbr_fd \
						ft_lstnew \
						ft_lstadd_front \
						ft_lstsize \
						ft_lstlast \
						ft_lstadd_back \
						ft_lstdelone \
						ft_lstclear \
						ft_lstiter \
						ft_lstmap))
PRINTF_SRC		:= 		$(addsuffix .c, \
				 		ft_printf \
						ft_printint \
						ft_printptr \
						ft_printstr)
GNL_SRC			:=		$(addsuffix .c, \
						get_next_line \
						get_next_line_utils)

LIBFT_OBJ		:=		$(LIBFT_SRC:%.c=$(OBJ_DIR)%.o)
PRINTF_OBJ		:=		$(addprefix $(DIR_PRINTF)/, $(PRINTF_SRC:.c=.o))
GNL_OBJ			:=		$(addprefix $(DIR_GNL)/, $(GNL_SRC:.c=.o))
DEP				:=		$(LIBFT_OBJ:.o=.d)

########################################################################################################################
#                                                      TARGETS                                                         #
########################################################################################################################

all : 					$(NAME)

clean :
							@rm -rf $(OBJ_DIR) $(PRINTF_OBJ) $(GNL_OBJ)
							@rm -f ft_printf/*.d
							@rm -f get_next_line/*.d

fclean : 				clean
							@rm -f $(NAME)

debug :
							@echo "Current directory : $(PWD)"
							@echo "Checking libft files : "
							@ls -l $(DIR_LIBFT)

re : 					fclean all

########################################################################################################################
#                                                       COMMANDS                                                       #
########################################################################################################################

$(NAME)				:	$(OBJ_DIR) $(LIBFT_OBJ) $(PRINTF_OBJ) $(GNL_OBJ)
								$(AR) $(NAME) $(LIBFT_OBJ) $(PRINTF_OBJ) $(GNL_OBJ)
								$(call SMALL_SEPARATOR)

$(OBJ_DIR)%.o		:		%.c  | $(OBJ_DIR)
								$(CC) $(CFLAGS) -I$(DIR_LIBFT) -o $@ -c $<

$(DIR_PRINTF)/%.o	:		$(DIR_PRINTF)/%.c $(INC_PRINTF)
								$(CC) $(CFLAGS) -c $< -o $@

$(DIR_GNL)/%.o		:		$(DIR_GNL)/%.c $(INC_GNL)
								@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) 			:
								mkdir -p $(OBJ_DIR)src/

-include $(DEPS)

########################################################################################################################
#                                                      DISPLAY                                                         #
########################################################################################################################

YELLOW 				:=		\033[1;93m

RESET 				:=		\033[0m

define	SMALL_SEPARATOR
						@echo "$(YELLOW)---$(RESET)";
endef

########################################################################################################################
#                                                       PHONY TARGETS                                                  #
########################################################################################################################

.PHONY : 				all bonus clean fclean re
