NAME = server

CC = clang
FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

SRCDIR = src
INCDIR = inc
OBJDIR = obj

SRCFILES = $(wildcard $(SRCDIR)/*.c)
OBJFILES = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCFILES))

all: $(NAME)

$(NAME): $(OBJFILES)
	$(CC) $(OBJFILES) -L. -lmx -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJDIR)/*.o $(NAME)

uninstall:
	rm -f $(NAME)

reinstall:
	make uninstall
	make
