#include <ESP8266WiFi.h>


const char* ssid = "NODEMCU";    //  Your Wi-Fi Name

const char* password = "12345678";   // Wi-Fi Password

int control_command = 1;


int pinLF = D0;
int pinLB = D1;
int pinRF = D2;
int pinRB = D3;

char command;
WiFiServer server(80);


void setup()

{

  Serial.begin(9600); //Default Baudrate

  pinMode(pinLF, OUTPUT);
  pinMode(pinLB, OUTPUT);
  pinMode(pinRF, OUTPUT);
  pinMode(pinRB, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  digitalWrite(pinLF,LOW);
  digitalWrite(pinLB,LOW);
  digitalWrite(pinRF,LOW);
  digitalWrite(pinRB,LOW);
 
  
 
   WiFi.softAP(ssid, password); //begin WiFi access point
  Serial.println("");


  Serial.println("Creating the server with NodeMCU as an access point"); 

  server.begin();  // Starts the Server

  Serial.println("Server started");

 

  Serial.print("IP Address of network: "); // will IP address on Serial Monitor

  Serial.println(WiFi.softAPIP());

  Serial.print("Copy and paste the following URL: https://"); // Will print IP address in URL format

  Serial.print(WiFi.localIP());

  Serial.println("/");

}

 

void loop()

{
  
  
  
  WiFiClient client = server.available();

  if (!client)

  {

    return;

  }

  Serial.println("Waiting for new client");

  while(!client.available())

  {

    delay(1);

  }
  // check out what request the client has made
  String request = client.readStringUntil('\r');

  Serial.println(request);

  client.flush();

  
  if(request.indexOf("/FORWARD") != -1)

  {
    
     digitalWrite(pinLF, HIGH);
     digitalWrite(pinRF, HIGH);
     digitalWrite(pinLB,LOW);
     digitalWrite(pinRB,LOW);
     command = 1;
  

  }

  else if(request.indexOf("/BACKWARD") != -1)

  {
     digitalWrite(pinLB, HIGH);
     digitalWrite(pinRB, HIGH);
     digitalWrite(pinLF,LOW);
     digitalWrite(pinRF,LOW);
     command = 2;
    //value = HIGH;

  }

  else if(request.indexOf("/RIGHT") != -1)

  {
     digitalWrite(pinLF, HIGH);
     digitalWrite(pinLB,LOW);
     digitalWrite(pinRB,HIGH);
     digitalWrite(pinRF,LOW);
     delay(90);
     digitalWrite(pinLF, LOW);
     digitalWrite(pinLB,LOW);
     digitalWrite(pinRB,LOW);
     digitalWrite(pinRF,LOW);
     command = 3;
    //value = HIGH;

  }

  else if(request.indexOf("/LEFT") != -1)

  {
     digitalWrite(pinLF, LOW);
     digitalWrite(pinLB,HIGH);
     digitalWrite(pinRB,LOW);
     digitalWrite(pinRF,HIGH);
     delay(90);
     digitalWrite(pinLF, LOW);
     digitalWrite(pinLB,LOW);
     digitalWrite(pinRB,LOW);
     digitalWrite(pinRF,LOW);
     command = 4;
    //value = HIGH;

  }
  
  else if(request.indexOf("/STOP") != -1)

  {
     digitalWrite(pinRF, LOW);
     digitalWrite(pinLF, LOW);
     digitalWrite(pinRB, LOW);
     digitalWrite(pinLB, LOW);
     command = 5;
  }



  
  

//*------------------HTML Page Code---------------------*//

 

  client.println("HTTP/1.1 200 OK"); //

  client.println("Content-Type: text/html");

  client.println("");

  client.println("<!DOCTYPE HTML>");

  client.println("<html>");

 

 // client.print(" CONTROLLING COMMAND: ");

 

  if(command == 1)

  {

    client.print("<h1>MOVING FORWARD</h1>");

  }

  else if(command == 2)

  {

    client.print("<h1>MOVING BACKWARD</h1>");

  }
  else if(command == 3)
  {

    client.print("<h1>MOVING RIGHT</h1>");

  }
  else if(command == 4)
  {

    client.print("<h1> MOVING LEFT </h1>");

  }
  else if(command == 5)
  {

    client.print("<h1> CAR STOPPED </h1>");

  }

  

  client.println("<br><br>");
  client.println("<body style='background-color:powderblue;'>");

  client.println("<center><a href=\"/FORWARD\"\"><h1>MOVE FORWARD</h1></center></a><br><br>");

  client.println("<center><a href=\"/BACKWARD\"\"><h1>MOVE BACKWARD</h1></a></center><br><br>");
  
  client.println("<center><a href=\"/RIGHT\"\"><h1>TURN RIGHT</h1></a></center><br><br>");

  client.println("<center><a href=\"/LEFT\"\"><h1>TURN LEFT</h1></a></center><br><br>");

  client.println("<center><a href=\"/STOP\"\"><h1>STOP</h1></a></center><br><br>");
  client.println("</body>");
  
    

  client.println("</html>");

 

  delay(5);

  

  Serial.println("");

}

