#include "stdafx.h"
#include "ConnectSock.h"

ConnectSock::ConnectSock(CString ipAddr, unsigned int port){
	m_ip = ipAddr;
	m_port = port;
	char c_ip[25];
	sin.sin_family = AF_INET;
	sin.sin_port = htons(m_port);
	strcpy(c_ip, (char*)LPCTSTR(m_ip));
	sin.sin_addr.S_un.S_addr = inet_addr(c_ip);
	m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//´´½¨SOCKET

}


CString ConnectSock::getIpAddr(){
	return m_ip;
}

unsigned int ConnectSock::getPort(){
	return m_port;
}

bool ConnectSock::isConnected(){
	if(m_socket < 0)
		return false;
	return true;
}

bool ConnectSock::connectSock(){
	if(!connect(m_socket, (sockaddr*)&sin, sizeof(sin)))
		return false;
	return true;
}
