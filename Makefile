SERVER = server
CLIENT = client

CC = cc

FLAGS = -Wall -Wextra -Werror

CLIENT_SRC = client.c
SERVER_SRC = server.c

CLIENT_OBJ = ${CLIENT_SRC:.c=.o}
SERVER_OBJ = ${SERVER_SRC:.c=.o}

all: $(CLIENT) $(SERVER)

client: ${CLIENT_OBJS}
		${CC} ${FLAGS} ${CLIENT_OBJ} -o ${CLIENT}

server: ${SERVER_OBJS}
		${CC} ${FLAGS} ${SERVER_OBJ} -o ${SERVER}

clean:
	rm -f ${CLIENT_OBJ} ${SERVER_OBJ}

fclean: clean
	rm -f ${CLIENT} ${SERVER}

re: fclean all