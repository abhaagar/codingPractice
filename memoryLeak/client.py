#!/usr/bin/python
import socket
import sys
import time
# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect the socket to the port where the server is listening
server_address = ('localhost', 10002)
print >>sys.stderr, 'connecting to %s port %s' % server_address
sock.connect(server_address)
try:
    # Send data
    message = 'This is the message.  It will be repeated.'*90
    #print >>sys.stderr, 'sending "%s"' % message
    sock.sendall(message)

    time.sleep(500000)

finally:
    print >>sys.stderr, 'closing socket'
    sock.close()

