NAME		=	poker

DIR		=	src_poker/

CC		=	clang++

RM		=	rm -f

SRCS		=	$(DIR)main.cpp \
			$(DIR)GameMain.cpp \
			$(DIR)Board.cpp \
			$(DIR)Player.cpp \
			$(DIR)dat_Output.cpp \
			$(DIR)Card.cpp \
			$(DIR)Human.cpp \
			$(DIR)bot_Ai.cpp

OBJS		=	$(SRCS:.cpp=.o)

CXXFLAGS	=	-Wextra -Wall -Wextra -ansi -g3 -I inc_poker/ -std=c++11 -Werror

$(NAME)		:	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) 

all		:	$(NAME)

clean		:	
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
