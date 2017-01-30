#!/usr/bin/env python
import socket
import os

def send(socket, string):
	socket.send(str.encode(string))

host=""
port=1240
server=socket.socket()
server.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR, 1)
server.bind((host, port))
server.listen(1)



client,addr=s.accept()

def newTarget(ipAddr, host=""):
	id=ipAddr+host
	ip=ipAddr
	host
	newRepository(ipAddr, host)


def newRepository(ipAddr, host=""):
	if (os.path.exists("../"+ipAddr)) :
		os.system("mkdir ../"+ipAddr+"/"+host)
	else if (host==""):
		os.system("mkdir ../"+ipAddr)
	else :
		os.system("mkdir ../"+ipAddr)
		os.system("mkdir ../"+ipAddr+"/"+host)
	
