import serial

from flask import Flask, send_file
from flask import request

ser = serial.Serial('COM7', baudrate=115200, timeout=10)
ser.set_buffer_size(rx_size = 25600, tx_size = 12800)

app = Flask(__name__)

@app.route('/')
def index():
    filename = 'index.htm'
    return send_file(filename, mimetype='text/html')

@app.route('/js')
def js():
    data="{}"
    command = request.query_string
    if command!=b'':
        ser.write(command)
        ser.write(b'\r')
        ser.write(b'\n')
        data = ser.readline()
    return data

if __name__ == '__main__':
    #app.run(host="127.0.0.1", port=5000)
    app.run(host="127.0.0.1", port=80)
    #app.run(host="0.0.0.0", port=5000)

ser.close()
