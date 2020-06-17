"""
    Description: Client file to send signal
                to Raspberry pi and display it on lcd panel
    Author: Hanbyul Park
    Date: May 5, 2019
"""
import socket
import sys

def main():
    '''This function manages the mainline logic of the program'''
    
    #HOST = ' ' #Available for every interface
    HOST = '192.168.0.24'
    PORT = 8888

    # 1. Instantiation of the socket class
    ClientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    ClientSocket.connect((HOST, PORT))

    # 2. Sending Signals to be displayed
    msg = input()
    ClientSocket.send(msg.encode(encoding='utf_8', errors='strict'))

    # 3. Receiving returned values
    return_data = ClientSocket.recv(1024)
    print('result: ' + return_data.decode())
    
    # 4. Close the ClientSocket
    ClientSocket.close()

if __name__ == "__main__":
    main()
