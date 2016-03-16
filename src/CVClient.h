#ifndef CVCLIENT_H
#define CVCLIENT_H

#include <netdb.h>

struct CVRequest {
	double angle_offset;
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
	CVRequest customPayload(char* payload, int length);
};

#endif /*CVCLIENT_H*/
