// dependencies
var HID = require('node-hid')
,   serialport = require('serialport')
,   SerialPort = serialport.SerialPort;


// constants
var THRESHOLD = 64;


// setup da serial port
var sp1 = new SerialPort('/dev/tty.usbmodemfa131', {
  parser: serialport.parsers.readline("\n")
});

// sp1.on('data', function(data) {
//   console.log(data);
// });


// first find the logitech wheel
var devicePath;
var devices = HID.devices();
devices.forEach(function(device) {
  if(device.manufacturer === 'Logitech') {
    devicePath = device.path;
  }
});

// start reading wheel data
var wheel = new HID.HID(devicePath);
wheel.read(dataRead);


var quardrant, value, position;
function dataRead(err, data) {
  if(err) throw err;
  else { 
    value = data[0];
    quardrant = data[1];
    position = (quardrant * 256 + value) - 512; // map the value so it's easier to work with, -512 < position < 512, 0 = centre

    // simple logic to 
    if(Math.abs(position) < THRESHOLD) {

      sp1.write("1");
      //console.log('centre');

    } else if(position < THRESHOLD) {

      sp1.write("0");
      //console.log('left');

    } else if(position > THRESHOLD) {

      sp1.write("2");
      //console.log('right');

    }

    // keep reading!
    wheel.read(dataRead);
  }
}
