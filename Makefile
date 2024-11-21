# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 20:39:53 by olarseni          #+#    #+#              #
#    Updated: 2024/11/20 23:31:17 by olarseni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                 DEFINITIONS                                  #
################################################################################

# Program name
NAME	=	push_swap

# Sources
SDIR	=	srcs
SRCS	=	

# Objects
ODIR	=	objects
OBJS	=	$(SRCS:%.c=%.o)

# Includes
IDIR	=	includes
INCL	=	push_swap.h		\
			stack_oper.h	\
			list_utils.h

# LIBFT
LDIR	=	libft
LIBFT	=	libft.a

# Compiler
CC		=	cc

# Flags
CFLAGS	=	-Wall -Wextra -Werror
IFLAGS	=	-I$(IDIR) -I$(LDIR)
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

$(NAME):
	@make --silent header
	@make --silent compile
	@echo "$(LGREEN)$(BOLD)COMPILATION FINISHED $(RESET)🎉"
	@sleep 1.5
	@make --silent footer

clean:
	rm -rf $(ODIR)
	$(MAKE) -C --no-print-directory --silent $(LDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C --no-print-directory --silent $(LDIR) fclean

re: fclean all

header:
	@sleep 0.5
	@echo "$$push_swap_art"
	@sleep 1.5
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
	@sleep 1
	@echo "$(LGREEN)$(FAINT)OBJS...$(RESET)"
	@sleep 1
	@echo "$(LGREEN)$(FAINT)LIBFT...$(RESET)"
	@sleep 1
	@echo "$(LGREEN)$(FAINT)$(NAME)...$(RESET)"
	@sleep 1

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
