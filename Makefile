########################################################################################################################
#                                                      VARIABLES                                                       #
########################################################################################################################

AUTHOR			:=		jowagner
NAME			:= 		minitalk
NAME_BONUS		:= 		minitalk bonus

NAME_C			:=		client
NAME_S			:=		server
NAME_C_S		:=		$(NAME_C) $(NAME_S)
NAME_C_BONUS	:=		client_bonus
NAME_S_BONUS	:=		server_bonus
NAME_C_S_BONUS	:=		$(NAME_C_BONUS) $(NAME_S_BONUS)

AR				:= 		ar -rcs
CC				:= 		cc
CFLAGS			:= 		-Wall -Wextra -Werror -MD -MP -Iinc/ -g3

########################################################################################################################
#                                                      DIRECTORY                                                       #
########################################################################################################################

INC_PATH		:=		inc/
SRC_PATH		:=		src/
OBJ_DIR			:= 		obj/
LIBFT_DIR		:=		libft/
LIBFT			:= 		$(LIBFT_DIR)libft.a

CLIENT_SRC		:=		src/client.c
SERVER_SRC		:=		src/server.c
CLIENT_SRC_B	:=		src/client_bonus.c
SERVER_SRC_B	:=		src/server_bonus.c
OBJ_C			:= 		$(CLIENT_SRC:$(SRC_PATH)%.c=$(OBJ_DIR)%.o)
OBJ_S			:= 		$(SERVER_SRC:$(SRC_PATH)%.c=$(OBJ_DIR)%.o)
OBJ_C_BONUS		:= 		$(CLIENT_SRC_B:$(SRC_PATH)%.c=$(OBJ_DIR)%.o)
OBJ_S_BONUS		:= 		$(SERVER_SRC_B:$(SRC_PATH)%.c=$(OBJ_DIR)%.o)
OBJ				:=		$(OBJ_C) $(OBJ_S) $(OBJ_C_BONUS) $(OBJ_S_BONUS)

DEP				:=		$(OBJ:%.o=%.d)
override DIRS	:=		$(sort $(dir $(NAME_C_S) $(OBJ) $(DEP)))

########################################################################################################################
#                                                      TARGETS                                                         #
########################################################################################################################

all : 					.print_header lib $(NAME_C_S)

lib :
							$(MAKE) -C $(LIBFT_DIR)

bonus :					.print_header_bonus lib $(NAME_C_S_BONUS)

clean :					.print_header
							@printf "%-50b%b" "$(YELLOW)[minitalk/$(OBJ_DIR)] :$(RESET)" "\n"
							rm -rf $(OBJ_DIR)
							@printf "%-50b%b" "=> $(BOLD_RED)Clean$(RESET)" $(call PROGRESS_BAR) "$(BOLD_GREEN)[✓]$(RESET)\n"
							@printf "\n"
							@printf "%-50b%b" "$(YELLOW)[$(LIBFT_DIR)obj] :$(RESET)" "\n"
							$(MAKE) --silent -C $(LIBFT_DIR) clean
							@printf "%-50b%b" "=> $(BOLD_RED)Clean$(RESET)" $(call PROGRESS_BAR) "$(BOLD_GREEN)[✓]$(RESET)\n"
							@printf "\n"

fclean : 				clean
							@printf "%-50b%b" "$(YELLOW)[$(NAME)] :$(RESET)" "\n"
							$(MAKE) --silent -C $(LIBFT_DIR) fclean
							rm -f $(NAME_C_S) $(NAME_C_S_BONUS)
							@printf "%-50b%b" "=> $(BOLD_RED)Clean$(RESET)" $(call PROGRESS_BAR) "$(BOLD_GREEN)[✓]$(RESET)\n"
							$(call SEPARATOR)

re : 					.print_header fclean all

.print_header :
							$(call TITLE)
							$(call SEPARATOR)
							$(call BUILD)
							$(call SEPARATOR)

.print_header_bonus :
							$(call TITLE)
							$(call SEPARATOR)
							$(call BUILD)
							$(call SEPARATOR)

########################################################################################################################
#                                                       COMMANDS                                                       #
########################################################################################################################

$(NAME_C) 			: 	$(OBJ_C)
							$(CC) -o $(NAME_C) $(OBJ_C) $(LIBFT)

$(NAME_S) 			: 	$(OBJ_S)
							$(CC) -o $(NAME_S) $(OBJ_S) $(LIBFT)
							$(call SMALL_SEPARATOR)

$(NAME_C_BONUS) 	: 	$(OBJ_C_BONUS)
							$(CC) -o $(NAME_C_BONUS) $(OBJ_C_BONUS) $(LIBFT)

$(NAME_S_BONUS) 	: 	$(OBJ_S_BONUS)
							$(CC) -o $(NAME_S_BONUS) $(OBJ_S_BONUS) $(LIBFT)
							$(call SMALL_SEPARATOR)

$(OBJ)				:	| $(DIRS)

$(DIRS):
							mkdir -p $@
							$(call SMALL_SEPARATOR)

$(OBJ_DIR)%.o		:	 $(SRC_PATH)%.c $(INC_PATH)minitalk.h
							$(CC) $(CFLAGS) -c -o $@ $<

-include $(DEP)

########################################################################################################################
#                                                      DISPLAY                                                         #
########################################################################################################################

MAGENTA			:=		\033[0;95m
YELLOW			:=		\033[1;93m
GREEN 			:=		\033[0;32m
BLUE			:=		\033[0;94m
RED 			:=		\033[0;31m

BOLD_YELLOW 	:=		\e[1;33m
BOLD_PURPLE		:=		\e[1;35m
BOLD_GREEN		:= 		\e[1;32m
BOLD_WHITE		:=		\e[1;37m
BOLD_CYAN 		:= 		\e[1;36m
BOLD_BLUE 		:= 		\e[1;34m
BOLD_RED 		:=		\e[1;31m

RESET 			:=		\033[0m

define	TITLE
						@echo "$(MAGENTA)---------------------------------------------------$(RESET)";
						@echo "     $(BOLD_RED) ____ ____ ____ ____ ____ ____ ____ ____ "
						@echo "     $(BOLD_YELLOW)||$(BOLD_WHITE)m$(BOLD_YELLOW) |||$(BOLD_WHITE)i$(BOLD_YELLOW) |||$(BOLD_WHITE)n$(BOLD_YELLOW) |||$(BOLD_WHITE)i$(BOLD_YELLOW) |||$(BOLD_WHITE)t$(BOLD_YELLOW) |||$(BOLD_WHITE)a$(BOLD_YELLOW) |||$(BOLD_WHITE)l$(BOLD_YELLOW) |||$(BOLD_WHITE)k$(BOLD_YELLOW) ||"
						@echo "     $(BOLD_GREEN)||__|||__|||__|||__|||__|||__|||__|||__||"
						@echo "     $(BOLD_BLUE)|/__\|/__\|/__\|/__\|/__\|/__\|/__\|/__\|"
endef

define PROGRESS_BAR

						@echo -n "$(BOLD_YELLOW)["
						@i=1; while [ $$i -le 3 ]; do echo -n "$(BOLD_WHITE)."; sleep 0.2; i=$$((i + 1)); done
						@echo -n "$(BOLD_YELLOW)]"
endef


define	BUILD
						@printf "%-32b%b" "  $(BOLD_CYAN)AUTHOR :$(RESET)" "$(BOLD_WHITE)$(AUTHOR)$(RESET)\n";
						@printf "%-32b%b" "  $(BOLD_CYAN)NAME   :$(RESET)" "$(BOLD_WHITE)$(NAME_BONUS)$(RESET)\n";
						@printf "%-32b%b" "  $(BOLD_CYAN)CC     :$(RESET)" "$(BOLD_WHITE)$(CC)$(RESET)\n";
						@printf "%-32b%b" "  $(BOLD_CYAN)FLAGS  :$(RESET)" "$(BOLD_WHITE)$(CFLAGS)$(RESET)\n";
endef

define	SEPARATOR
						@printf "\n"
						@echo "$(MAGENTA)---------------------------------------------------$(RESET)";
						@printf "\n"
endef

define	SMALL_SEPARATOR
						@echo "$(YELLOW)---$(RESET)";
endef

########################################################################################################################
#                                                       PHONY TARGETS                                                  #
########################################################################################################################

.PHONY : 				all lib bonus clean fclean re .print_header .print_header_bonus
