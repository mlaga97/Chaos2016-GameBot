#ifndef CVCLIENT_H
#define CVCLIENT_H

#include <netdb.h>

struct CVRequest {
	double forward;
	double rotation;
	double roller;
	int local_error;
};

class CVClient
{
  private:
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[256];
	char buffer2[32];

  public:
	int initialize();
	CVRequest autoAim();
	CVRequest autoFire();
	CVRequest autoBall();
};

#endif /*CVCLIENT_H*/
