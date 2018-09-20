NAME = libftprintf.a
SRCS = parser.c f_strings.c f_numerical.c ft_strcat.c ft_strchr.c ft_strlen.c ft_indexof.c \
		ft_strnew.c ft_bzero.c ft_isalpha.c ft_atoi.c ft_strjoin.c ft_itoa.c ft_strsub.c ft_isdigit.c \
		ft_memalloc.c ft_strdel.c ft_strdup.c ft_memdel.c ft_strcpy.c ft_strstr.c save_args.c save_more_args.c\
		struct_ini.c flags.c
OBJECTS = parser.o f_strings.o f_numerical.o ft_strcat.o ft_strchr.o ft_strlen.o ft_indexof.o \
		ft_strnew.o ft_bzero.o ft_isalpha.o ft_atoi.o ft_strjoin.o ft_itoa.o ft_strsub.o ft_isdigit.o \
		ft_memalloc.o ft_strdel.o ft_strdup.o ft_memdel.o ft_strcpy.o ft_strstr.o save_args.o save_more_args.o \
		struct_ini.o flags.o

.PHONY : fclean 
.PHONY: clean


all: $(NAME)

$(NAME): $(OBJECTS)
	ar -ru $(NAME) $(OBJECTS)

$(OBJECTS): $(SRCS)
	cc -c $(SRCS) -Wall -Wextra -Werror 

clean: 
	/bin/rm -f $(OBJECTS)
	/bin/rm -f ft_printf.h.gch

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all