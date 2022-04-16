##
## EPITECH PROJECT, 2020
## B-NWP-400-LYN-4-1-myteams-maxime.simon
## File description:
## Makefile
##

NAMESERV	=	myteams_server
NAMECLI		=	myteams_cli

SRCSSERV	=	$(wildcard $(addprefix src/server/cmd/, *).c $(addprefix src/server/, *).c	\
				$(addprefix src/server/data_parsing/, *).c $(addprefix src/server/lib/, *).c	\
				$(addprefix src/server/manage_data/, *).c)

SRCSCLI		=	$(wildcard $(addprefix src/client/, *).c $(addprefix src/client/cmd_execute/, *).c)

CFLAGS	+=	-W -Wall -Wextra -g3
CFLAGS	+=	-Iinclude
LDFLAGS +=	-L ./libs/myteams/
LDLIBS	+=	-lmyteams

CC	=	@gcc

RM	=	rm -f

END			=	\033[0m
BOLD		=	\033[1m
GREY		=	\033[30m
RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
PURPLE		=	\033[35m
CYAN		=	\033[36m
WHITE		=	\033[37m

OBJSSERV	=	$(SRCSSERV:.c=.o)
OBJSCLI		=	$(SRCSCLI:.c=.o)

all:		serv cli

serv:		$(NAMESERV)

cli:	$(NAMECLI);

$(NAMESERV):	$(OBJSSERV)
		@$(CC) -o $(NAMESERV) $(OBJSSERV) $(LDFLAGS) $(LDLIBS) -luuid
		@echo "$(GREEN)ooooooooooooooooooooooooooooooooooooooooooooooooooo$(END)"
		@echo "$(GREEN)---------->$(BOLD) DONE FOR : $(NAMESERV) $(END) $(GREEN)<-----------$(END)"
		@echo "$(GREEN)ooooooooooooooooooooooooooooooooooooooooooooooooooo$(END)"

$(NAMECLI):	$(OBJSCLI)
		@$(CC) -o $(NAMECLI) $(OBJSCLI) $(LDFLAGS) $(LDLIBS) -luuid
		@echo "$(GREEN)ooooooooooooooooooooooooooooooooooooooooooooooooooo$(END)"
		@echo "$(GREEN)------------>$(BOLD) DONE FOR : $(NAMECLI) $(END) $(GREEN)<------------$(END)"
		@echo "$(GREEN)ooooooooooooooooooooooooooooooooooooooooooooooooooo$(END)"

clean:
		@$(RM) $(OBJSSERV)
		@$(RM) $(OBJSCLI)
		@echo "$(BLUE)ooooooooooooooooooooooooooo$(END)"
		@echo "$(BLUE)-------->$(BOLD) CLEANED$(END) $(BLUE)<--------$(END)"
		@echo "$(BLUE)ooooooooooooooooooooooooooo$(END)"

fclean:		clean
		@$(RM) $(NAMESERV)
		@$(RM) $(NAMECLI)

re:		fclean all

.PHONY:		all clean fclean re
