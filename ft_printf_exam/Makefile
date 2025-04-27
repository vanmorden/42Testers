#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

# Special variables
DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all clean fclean re bonus


#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
INCDIR	=	headers/
OBJDIR	=	obj/
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -rf
ARFLAGS	=	-rcs
AR		=	ar

# Dir and file names
LIB_NAME	=	ftprintf
NAME		=	libftprintf.a
LIB_SRCS	=	ft_printf.c
#$(info LIB_SRCS is $(LIB_SRCS))
LIB_OBJS	=	$(LIB_SRCS:%.c=$(OBJDIR)%.o)

$(info LIB_OBJS is $(LIB_OBJS))
INC			=	$(INCDIR)lib$(LIB_NAME).h
TEST_NAME	=	libtest.out
OBJS		=	$(OBJDIR)main.o

# Norminette vars
NORM := norminette
NORM_FLAGS := -R CheckForbiddenSourceHeader -R CheckDefine

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

dirs:
	@mkdir -p $(OBJDIR)

$(OBJS): $(OBJDIR)main%.o: main.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_OBJS): $(OBJDIR)%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_NAME): $(OBJS) $(NAME)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIB_OBJS) -L. -l$(LIB_NAME)

$(NAME): $(LIB_OBJS)
	$(AR) $(ARFLAGS) $@ $^

all: dirs $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all clean

norm: $(LIB_SRCS) $(BONUS_SRC) $(INC)
	@$(NORM) $(NORM_FLAGS) $^

test: dirs $(LIB_OBJS) $(OBJS) $(TEST_NAME)
