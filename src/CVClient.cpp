#include <iostream>
#include <string.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include "CVClient.h"

CVRequest CVClient::autoAim() {
	CVRequest target = {0};

	// Write to Server
	n = write(sockfd,"AUTO_AIM\n",9);
	if (n < 0) {
		std::cout << "Write error!\n";
		target.local_error = -1;
		return target;
	}
	
	// Read from Server
	bzero(buffer,256);
	n = read(sockfd,buffer,255);
	if (n < 0) {
		std::cout << "Read error!\n";
		target.local_error = -2;
		return target;
	}
	
	// Slightly Less Evil String Splitting Solution
	int offset = 0;
	int count = 0;
	double values[10];
	for(n = 0; buffer[n] != '\00'; n++) {
		if(buffer[n]==' ') {
			values[count] = atof(buffer2);
			bzero(buffer2,32);
			offset = n+1;
			count++;
		} else {
			buffer2[n-offset] = buffer[n];
		}
	}
	values[count] = atof(buffer2);
	
	// Put Values Where They Belong
	target.angle_offset = values[0];

	return target;
}

CVRequest CVClient::customPayload(char* payload, int length) {
	CVRequest target = {0};

	// Write to Server
	n = write(sockfd,payload,length);
	if (n < 0) {
		std::cout << "Write error!\n";
		target.local_error = -1;
		return target;
	}

	// Read from Server
	bzero(buffer,256);
	n = read(sockfd,buffer,255);
	if (n < 0) {
		std::cout << "Read error!\n";
		target.local_error = -2;
		return target;
	}

	// Slightly Less Evil String Splitting Solution
	int offset = 0;
	int count = 0;
	double values[10];
	for(n = 0; buffer[n] != '\00'; n++) {
		if(buffer[n]==' ') {
			values[count] = atof(buffer2);
			bzero(buffer2,32);
			offset = n+1;
			count++;
		} else {
			buffer2[n-offset] = buffer[n];
		}
	}
	values[count] = atof(buffer2);

	// Put Values Where They Belong
	target.angle_offset = values[0];

	return target;
}

int CVClient::initialize() {
	
	// Open Socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		std::cout << "Couldn't open socket!\n";
		return -1;
	}

	// Get Host By Name
	server = gethostbyname("visionserver.local");
	if (server == NULL) {
		std::cout << "No such host!\n";
		return -2;
	}
	
	// Set Stuff for Connection
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy(
		(char *)server->h_addr,
		(char *)&serv_addr.sin_addr.s_addr,
		server->h_length
	);
	serv_addr.sin_port = htons(5800);
	
	// Open Connection
	if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
		std::cout << "Error connecting!\n";
		return -3;
	}
	
	return 0;
}
