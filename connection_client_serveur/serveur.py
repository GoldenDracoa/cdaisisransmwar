#! /usr/bin/python2.7
# -*- coding:UTF-8 -*-

"""
    Projet Cryptolocker
    Partie Serveur Version1 communication entre le client et le serveur basique
    Auteur : Yohan Woittequand
    Date : 5Décembre 2017
"""

import socket
import sys 

# Information générale
host=''
port=60000

# Création de la socket du serveur
com_socket = socket.socket()
com_socket.bind((host,port))
com_socket.listen(1)

# Communication avec le client
client, ip = com_socket.accept()
client.send("vous êtes connecté au serveur principal")

data = client.recv(1024)
print data

