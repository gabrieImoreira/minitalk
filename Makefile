CLIENT 		=	client
SERVER 		=	server

SRC_PATH	=	./src
HEADER_PATH =	./inc
OBJ_PATH	=	./obj

SRC_CLIENT	=	client.c
SRC_SERVER	=	server.c
SRC_UTILS	=	utils.c
HEADER		=	minitalk.h

OBJ_CLIENT 	=	$(addprefix $(OBJ_PATH)/, $(SRC_CLIENT:.c=.o))
OBJ_SERVER 	=	$(addprefix $(OBJ_PATH)/, $(SRC_SERVER:.c=.o))
OBJ_UTILS 	=	$(addprefix $(OBJ_PATH)/, $(SRC_UTILS:.c=.o))

CC			=	clang
FLAGS		=	-Wall -Werror -Wextra
RM			= 	rm -rf

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT) $(OBJ_UTILS)
	$(CC) $(FLAGS) $(OBJ_CLIENT) $(OBJ_UTILS) -o $(CLIENT)

$(SERVER): $(OBJ_SERVER) $(OBJ_UTILS)
	$(CC) $(FLAGS) $(OBJ_SERVER) $(OBJ_UTILS) -o $(SERVER)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER_PATH)/$(HEADER)
	@mkdir -p $(dir $@)
	$(CC) -c $(FLAGS) -o $@  $<

clean:
	@$(RM) $(OBJ_PATH)

fclean: clean
	@$(RM) $(CLIENT) $(SERVER)

re: fclean all	