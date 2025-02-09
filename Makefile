# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 20:39:53 by olarseni          #+#    #+#              #
#    Updated: 2025/02/09 02:07:49 by olarseni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                 DEFINITIONS                                  #
################################################################################

# Program name
NAME	=	push_swap


# Sources with VPATH
VPATH	=	srcs srcs/stack srcs/checker
SRCS	=	main.c				\
			stack_utils.c		\
			stack_helpers.c		\
			init_stack.c		\
			is_valid_input.c	\
			basic_movements.c	\
			double_movements.c	\
			move_stack.c		\
			sort_stack.c		\
			calculate_cost.c	\
			big_sort.c			\
			utils.c				\
			small_sorts.c

# Objects
ODIR	=	objects
OBJS	=	$(SRCS:%.c=$(ODIR)/%.o)

# Includes
IDIR	=	includes

# LIBFT
LDIR	=	libft
LIBFT	=	libft.a
LPRINTF	=	libft/ft_printf/includes

# Compiler
CC		=	cc

# Flags
CFLAGS	=	-Wall -Wextra -Werror -g
IFLAGS	=	-I$(IDIR) -I$(LDIR) -I$(LPRINTF)
LFLAGS	=	-L$(LDIR) -lft

################################################################################
#                                  COLORS                                      #
################################################################################

RESET	=	\033[0m
LGREEN	=	\033[38;5;150m
CYAN	=	\033[38;5;195m
DRED	=	\033[38;5;124m
RED		=	\033[38;5;160m
SAND	=	\033[38;5;222m
LPURPLE	=	\033[38;5;104m

################################################################################
#                                 FONT STYLES                                  #
################################################################################

BOLD	=	\033[1m
FAINT	=	\033[2m
ITALIC	=	\033[3m
UNDERL	=	\033[4m
BLINK	=	\033[5m

################################################################################
#                                   RULES                                      #
################################################################################

all: $(NAME)

$(ODIR)/%.o: %.c | $(ODIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@make --silent header
	@make --silent compile
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ $^ $(LFLAGS)
	@echo "$(LGREEN)$(BOLD)COMPILATION FINISHED $(RESET)🎉"
	@make --silent footer

$(LIBFT):
	@make --silent -C $(LDIR)

$(ODIR):
	@mkdir -p $@

clean:
	@rm -rf $(ODIR)
	@$(MAKE) --silent -C $(LDIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --silent -C $(LDIR) fclean

re: fclean all

header:
	@echo "$$push_swap_art"
	@sleep 0.2
	@echo "$(FAINT)$(CYAN)$(line)$(RESET)"
	@echo "\t\t\t$(SAND)$(FAINT)$(ITALIC)WELCOME TO $(DRED)$(BOLD)$(NAME)$(RESET) $(SAND)$(FAINT)$(ITALIC)PROGRAM$(RESET)"
	@echo "$(FAINT)$(CYAN)$(line)$(RESET)"
	
footer:
	@echo "$(FAINT)$(CYAN)$(line)$(RESET)"
	@echo "$(LPURPLE)$(BOLD)Compiled by:$(RESET) $(CYAN)$$USER$(RESET)"
	@echo "$(LPURPLE)$(BOLD)Compiled date:$(RESET) $(CYAN)$(shell date '+%d/%m/%Y %H:%M:%S')$(RESET)"
	@echo "$(FAINT)$(CYAN)$(line)$(RESET)"

compile:
	@echo "$(LGREEN)$(BOLD)$(FAINT)START COMPILATION: $(RESET)"
	@sleep 0.1
	@echo "$(LGREEN)$(FAINT)OBJS...$(RESET)"
	@sleep 0.1
	@echo "$(LGREEN)$(FAINT)LIBFT...$(RESET)"
	@make --silent -C $(LDIR) $(LIBFT)
	@sleep 0.1
	@echo "$(LGREEN)$(FAINT)$(NAME)...$(RESET)"
	@sleep 0.1

.PHONY: all clean fclean re header

################################################################################
#                                 VARIABLES                                    #
################################################################################

# A simple line made with '='
define line
================================================================================
endef

export line

# Footer ASCII art

define push_swap_art
\033[38;5;247m
              .... NO! ...                  ... MNO! ...
             ..... MNO!! ...................... MNNOO! ...
           ..... MMNO! ......................... MNNOO!! .
          .... MNOONNOO!   MMMMMMMMMMPPPOII!   MNNO!!!! .
           ... !O! NNO! MMMMMMMMMMMMMPPPOOOII!! NO! ....
              ...... ! MMMMMMMMMMMMMPPPPOOOOIII! ! ...
             ........ MMMMMMMMMMMMPPPPPOOOOOOII!! .....
             ........ MMMMMOOOOOOPPPPPPPPOOOOMII! ...  
              ....... MMMMM..    OPPMMP    .,OMI! ....
               ...... MMMM::   o.,OPMP,.o   ::I!! ...                
                   .... NNM:::.,,OOPM!P,.::::!! ....                 
                    .. MMNNNNNOOOOPMO!!IIPPO!!O! .....               
                   ... MMMMMNNNNOO:!!:!!IPPPPOO! ....                
                     .. MMMMMNNOOMMNNIIIPPPOO!! ......               
                    ...... MMMONNMMNNNIIIOO!..........
                 ....... MN MOMMMNNNIIIIIO! OO ..........
              ......... MNO! IiiiiiiiiiiiI OOOO ...........
            ...... NNN.MNO! . O!!!!!!!!!O . OONO NO! ........
             .... MNNNNNO! ...OOOOOOOOOOO .  MMNNON!........
             ...... MNNNNO! .. PPPPPPPPP .. MMNON!........
                ...... OO! ................. ON! .......
                   ................................

$(RED)@@@@@@@  @@@  @@@  @@@@@@ @@@  @@@     @@@@@@ @@@  @@@  @@@  @@@@@@  @@@@@@@$(RESET)
$(DRED)@@!  @@@ @@!  @@@ !@@     @@!  @@@    !@@     @@!  @@!  @@! @@!  @@@ @@!  @@@$(RESET)      
$(FAINT)$(RED)@!@@!@!  @!@  !@!  !@@!!  @!@!@!@!     !@@!!  @!!  !!@  @!@ @!@!@!@! @!@@!@!$(RESET)
$(FAINT)$(DRED)!!:      !!:  !!!     !:! !!:  !!!        !:!  !:  !!:  !!  !!:  !!! !!:$(RESET)   
$(FAINT)$(DRED) :        :.:: :  ::.: :   :   : :    ::.: :    ::.:  :::    :   : :  :$(RESET)

endef

export push_swap_art
