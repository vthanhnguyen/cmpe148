
var SerialPort = require('serialport');
const parsers = SerialPort.parsers;

const parser = new parsers.Readline({
    delimiter: '\r\n'
});
//TCP request
var port = new SerialPort('COM3',{ 
    baudRate: 9600,
    dataBits: 8,
    parity: 'none',
    stopBits: 1,
    flowControl: false
});

port.pipe(parser);

parser.on('data', function(data) {
    //whenever we recieve data, print it
    console.log('Received data from port: ' + data);
    
});
