#include "tcp.h"


char *dispIp(struct addrinfo *res)
{
  char *address_text = malloc(INET_ADDRSTRLEN);
  return (char*)inet_ntop(AF_INET,
    &((struct sockaddr_in *)res->ai_addr)->sin_addr,address_text,INET_ADDRSTRLEN);
  }

int pingTCP(char *host)
{
	struct addrinfo *res;
	int sockfd;
	fd_set fdset;
	struct timeval tv;

	errno = 0;

	if (getaddrinfo(host,NULL,NULL,&res)==0)
	{

		sockfd = socket(PF_INET, SOCK_STREAM, 6);
		fcntl(sockfd, F_SETFL, O_NONBLOCK);
		connect(sockfd, res->ai_addr, res->ai_addrlen);


		FD_ZERO(&fdset);
		FD_SET(sockfd, &fdset);
		tv.tv_sec = 0;
		tv.tv_usec = 500*1000;

		int val=select(sockfd + 1, NULL, &fdset, NULL, &tv);
		close(sockfd);
		freeaddrinfo(res);
		if (val==0) { return 0;     }
		else {    return 1;    }
		//getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &so_error, &ret);
		//    printf("[%d] %s\n",errno,strerror(errno));
	}

	return -1;
}

/*
 int main(int argc,char **argv)
{
printf("%d ",pingTCP(argv[1]));
return 0;

}*/
