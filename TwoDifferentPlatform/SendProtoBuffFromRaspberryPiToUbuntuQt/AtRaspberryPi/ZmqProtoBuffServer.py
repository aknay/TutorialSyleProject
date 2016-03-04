import zmq

# !/usr/bin/env python
import subprocess
import os.path

# we generate 'file to be imported' if doesn't exist
if (os.path.exists("message_pb2.py") == False):
    subprocess.call("protoc message.proto --python_out='.'", shell=True)

import message_pb2

context = zmq.Context()
socket = context.socket(zmq.REP)
socket.bind("tcp://*:5556") # connect to it own local host address with port number 5556
print "Server started"

while True:
    #  Wait for next request from client
    message = socket.recv()
    addressBook = message_pb2.AddressBook()
    addressBook.ParseFromString(message)

    # check client message
    for person in addressBook.person:
        print " Hello ", person.name
        print " Your email will be ", person.email

    #  Send reply back to client
    socket.send(b"Hello Client")
