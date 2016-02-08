#ifndef CVCLIENT_H
#define CVCLIENT_H

#include <netdb.h>

struct Target {
	int x;
	int y;
	int error;
};

class CVClient
{
  private:
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[32];
	char buffer2[32];

  public:
	int initialize();
	Target getData();
};

#endif /*CVCLIENT_H*/
