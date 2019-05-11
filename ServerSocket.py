"""
    Description: Server file of socket communication that receives data
		from the client and display on the lcd panel.
    Author: Hanbyul Park
    Date: May 4, 2019
"""

import socket
import time
import sys
import i2c_lcd


def main():
    '''This function manages the mainline logic of the program '''

#    HOST = '' # Available for all interaces
    HOST = '192.168.0.22'
    PORT = 8888 #PRESET

    # 0. Instantiation of the lcd class
    lcd = i2c_lcd.lcd()
    lcd.backlight_on(True)

    # 1. Instantiation of the socket class
    SocketServer = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print('Socket is created')

    # 2. Being prepared to receive data from the client
    try:
        SocketServer.bind((HOST, PORT))
    except:
        print("Binding failed")
        sys.exit()

    print('Socket binding completed')

    # 3. Start listening from the client
    SocketServer.listen(100)
    print("Server is waiting for connection")

    # 4. Socket starts to communicate
    conn, addr = SocketServer.accept()
    print("Connected with " + addr[0] + ': ' + str(addr[1]))
    msg = conn.recv(1024)

    # 5. Return the state of the socket
    conn.sendall("Successfully sent".encode())

    # 6. Display
    encoded_data = msg.decode()
    if len(encoded_data) <= 16:
        lcd.lcd_display_string(encoded_data, 1)
    elif len(encoded_data) > 16:
        lcd.lcd_display_string(encoded_data[:16], 1)
        lcd.lcd_display_string(encoded_data[16:], 2)

    # 7. Delay and ends the program
    time.sleep(10)
    lcd.lcd_clear()
    lcd.backlight_on(False)

    # 8. Close the socket
    conn.close()
    SocketServer.close()

if __name__ == "__main__":
    main()

