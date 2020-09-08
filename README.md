# Three DOF Manipulator Control In An IOT Environment Using Arduino :
The aim of this project was to control a 3 degree of freedom (DOF) manipulator from a web user interface and for that 2 arduino boards are needed. The first board is an arduino UNO board that is programmed to control the manipulator servo motors and also get the position(angle) of the motors from their encoders. Additionally, another arduino board is needed that has the hardware needed for connecting to a local wifi network and in this case an ESP2866 board was used. The ESP board should be programmed to first of all connect to a local wifi network by using its username and password and then create a local server and wait for local clients to use the interface and refresh the interface page everytime a client action is made. The interface itself is a simple web gui written in HTML and it has two buttons for each motor (for each direction) and they act as a push button therefore, the motors would stop when we are not pushing their buttons.

The communication between the boards are used by a dual way UART serial connection(2 wires). The basis of this communication from the interface to the Arduino UNO board is on sending certain strings based on actions and decoding them on the other end. Also, the encoder positions should be send via the serial wire to the interface for the user to see them and they should be sent as numbers.
