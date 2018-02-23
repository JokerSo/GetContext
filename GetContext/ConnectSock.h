#ifndef CONNECTSOCK_H
#define CONNECTSOCK_H

#include <WinSock2.h>

class ConnectSock{
public:
	ConnectSock(CString, unsigned int);

public: //action
	void closeSock();
public:
	SOCKET m_socket;
	CString getIpAddr();
	unsigned int getPort();
	bool isConnected();
	bool connectSock();
	char* getDataFromRemote();
	char* sendDataToRemote(char *);


private:
	CString m_ip;
	unsigned int m_port;
	sockaddr_in sin;

};

#endif