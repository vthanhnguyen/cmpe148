
from socket import *
import sys # In order to terminate the program
serverSocket = socket(AF_INET, SOCK_STREAM)

#Prepare a sever socket
serverPort = 80 # assign a port number
serverSocket.bind(("10.0.0.5" , serverPort)) # bind the socket to ip and port
serverSocket.listen(1)

while True:
    #Establish the connection
    print('Ready to serve...')
    connectionSocket, addr = serverSocket.accept()

    try:
        message = connectionSocket.recv(1024)
        filename = message.split()[1]
        f = open(filename[1:])
        outputdata = f.read()
        #Send one HTTP header line into socket
        connectionSocket.send("HTTP/1.1 200 OK\r\n\r\n")
        #Send the content of the requested file to the client
        for i in range(0, len(outputdata)):
            connectionSocket.send(outputdata[i].encode())

        connectionSocket.send("\r\n".encode())
        #close the connection
        connectionSocket.close() 
    except IOError:
        #Send response message for file not found
        connectionSocket.send("HTTP/1.1 404 NOT FOUND\r\n\r\n")
        
        #Close client socket
        serverSocket.close()
sys.exit()#Terminate the program after sending the corresponding data