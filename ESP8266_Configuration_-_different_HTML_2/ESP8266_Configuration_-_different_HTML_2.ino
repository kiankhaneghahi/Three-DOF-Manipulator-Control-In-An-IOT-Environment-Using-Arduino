#include <ESP8266WiFi.h>

const char* ssid = "DC-Lab";
const char* password = "digital@1396";

WiFiServer server(80);

int output_pin = 2;

void setup() {

 

  
  Serial.begin(115200);
  delay(10);

  pinMode(output_pin, OUTPUT);
  digitalWrite(output_pin, 0);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  server.begin();
  Serial.println("Server started");

  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  //Serial.println("new client");
  while (!client.available()) {
  delay(1);
  }

  String req = client.readStringUntil('\r');
  //Serial.println(req);

  if (req.indexOf("/up1") != -1) {
  digitalWrite(output_pin, 0);
  Serial.println('q');
     
  }
  else if (req.indexOf("/down1") != -1) {
  digitalWrite(output_pin, 0);
  Serial.println('a');
     
  }
  else if (req.indexOf("/up2") != -1) {
  digitalWrite(output_pin, 0);
  Serial.println('w');

  }
  else if (req.indexOf("/down2") != -1) {
  digitalWrite(output_pin, 0);
  Serial.println('s');
     
  }
  else if (req.indexOf("/up3") != -1) {
  digitalWrite(output_pin, 0);
  Serial.println('d');

  }
  else if (req.indexOf("/down3") != -1) {
  digitalWrite(output_pin, 0);
  Serial.println('e');
  }
  

    client.flush();
    String readData2="";
    char data[64];
  
    Serial.flush();  
    delay(10);
    Serial.readBytes(data,64);
    String readData(data);
    //printf("available");
    //readData=Serial.readStringUntil('\n');
    readData2=readData.substring(readData.indexOf('@'),readData.indexOf('$'));
    Serial.flush();  
 
  
  /*SERVER HTML CODE */
  
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";

  
  s += "<head>";
  s += "<meta charset=\"utf-8\">";
  s += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
  s += "<script src=\"https://code.jquery.com/jquery-2.1.3.min.js\"></script>";
  s += "<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.4/css/bootstrap.min.css\">";
  s += "</head>";
  
  s += "<div class=\"container\">";
  s += "<h1>  Robot control: </h1>";
  s += "<div class=\"row\">";
  s += "<div class=\"col-md-2\"><input class=\"btn btn-block btn-lg btn-success\"style=\"font-size:24px;border-radius:100%;height:100px;width:200px;\"type=\"button\" value=\"motor 1:up\" onclick=\"up1()\"></div>";
  s += "<div class=\"col-md-2\"><input class=\"btn btn-block btn-lg btn-danger\"style=\"font-size:24px;border-radius:100%;height:100px;width:200px;\" type=\"button\" value=\"motor 1:down\" onclick=\"down1()\"></div>";
  s += "<div class=\"col-md-2\"><input class=\"btn btn-block btn-lg btn-success\"style=\"font-size:24px;border-radius:100%;height:100px;width:200px;\" type=\"button\" value=\"motor 2:up\" onclick=\"up2()\"></div>";
  s += "<div class=\"col-md-2\"><input class=\"btn btn-block btn-lg btn-danger\"style=\"font-size:24px;border-radius:100%;height:100px;width:200px;\" type=\"button\" value=\"motor 2:down\" onclick=\"down2()\"></div>";
  s += "<div class=\"col-md-2\"><input class=\"btn btn-block btn-lg btn-success\"style=\"font-size:24px;border-radius:100%;height:100px;width:200px;\" type=\"button\" value=\"motor 3:up\" onclick=\"up3()\"></div>";
  s += "<div class=\"col-md-2\"><input class=\"btn btn-block btn-lg btn-danger\"style=\"font-size:24px;border-radius:100%;height:100px;width:200px;\" type=\"button\" value=\"motor 3:down\" onclick=\"down3()\"></div>";
  s += "</div></div>";
  s += "<h1>Recieved information:</h1>";
  s += "<h1>servo1/servo2/servo3</h1>";
  //s += "<h1>"+readData+"</h1>";
  s += "<h1>"+readData2+"</h1>";
  

  s += "<script>function up1() {$.get(\"/up1\");}</script>";
  s += "<script>function down1() {$.get(\"/down1\");}</script>";
  s += "<script>function up2() {$.get(\"/up2\");}</script>";
  s += "<script>function down2() {$.get(\"/down2\");}</script>";
  s += "<script>function up3() {$.get(\"/up3\");}</script>";
  s += "<script>function down3() {$.get(\"/down3\");}</script>";
  


  client.print(s);
  delay(1);
    
  //Serial.println("Client disconnected");
}
