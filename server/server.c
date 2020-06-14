#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "erproc.h"
/*
struct sockaddr_in {
    short int          sin_family;  // Семейство адресов
    unsigned short int sin_port;    // Номер порта
    struct in_addr     sin_addr;    // IP-адрес
    unsigned char      sin_zero[8]; // "Дополнение" до размера структуры sockaddr
};
*/

/*
int Socket(int domain, int type, int protocol){

	int res = socket(domain, type, protocol);
	if (res == -1){

		perror("ERROR!!! Failed create socket...");
		exit(EXIT_FAILURE);

	}
	return res;

}


int  Accept(int sockfd,  struct sockaddr *addr, socklen_t *addrlen){

        int res = accept(sockfd, addr, addrlen);
        if (res == -1){

                perror("ERROR!!! failed accept...");
                exit(EXIT_FAILURE);

        }
        return res;

}

int Listen(int sockfd, int backlog){

        int res = listen(sockfd, backlog);
        if (res == -1){

                perror("ERROR!!! failed listen socket...");
                exit(EXIT_FAILURE);

        }
        return res;

}



int  Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen){


	int res = bind(sockfd, addr, addrlen);
	if (res == -1){

		perror("ERROR!!! Failed bind socket...");
		exit(EXIT_FAILURE);

	}
	return res;
}
*/

int main(){

 	int Server =  Socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr = {0};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8001);
	Bind(Server,(const struct sockaddr *) &addr, sizeof(addr));
	Listen(Server, 5);
	while(1){
		socklen_t addr_len = sizeof addr;	
		int  file_descriptor = Accept(Server,( struct sockaddr *) &addr, &addr_len);
		ssize_t nread;
		char buf[1024];

		nread = read(file_descriptor, buf, 256);
		if (nread == -1){
			perror("ERROR!!! failed read data  buffer...");
                	exit(EXIT_FAILURE);
		}



		int res = write(STDOUT_FILENO, buf, nread);
		res = write(file_descriptor, buf, nread);

		if (res == -1)
		 printf("fail write in file decriptor...");
		close(file_descriptor);
	}
	return 0;
}
