var http = require('http');
var fs = require('fs')
var index = fs.readFileSync('client.html')

var SerialPort = require('serialport');
const parsers = SerialPort.parsers;

const parser = new parsers.Readline({
    delimiter: '\r\n'
});
//UDP request inorder to get data
var port = new SerialPort('COM3',{ 
    baudRate: 9600,
    dataBits: 8,
    parity: 'none',
    stopBits: 1,
    flowControl: false
});
port.pipe(parser); //pipe and parse the data

//create our server to host our webpage
var myServer = http.createServer(function(request,response){
    //return a http 200 response code and content
    response.writeHead(200,{'Content-Type': 'text/html'});
    response.end(index);
});

//use socket.io to ensure connection
var io = require('socket.io').listen(myServer);
io.on('connection', function(data){
    console.log('Client webpage is listening..');
})

//using our parser, whenever we receive data we will run this function
parser.on('data', function(data) {
    //whenever we recieve data, print it
    console.log('Received data from port: ' + data);

    //when we recieve data from the serialport/parser, emit a message data
    io.emit('data', data);
});

//run the server at port localhost port 3000
myServer.listen(3000);

