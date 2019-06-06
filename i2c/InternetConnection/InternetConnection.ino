#include<ESP8266WiFi.h>

const char* ssid = "Onestar"; // 자신의 환경에 맞는 무선 인터넷의 SSID
const char* password= "02200820"; // 와 패스 워드를 입력합니다.

void setup() {
  // put your setup code here, to run once:
  delay(1000);
  Serial.begin(9600);  //시리얼 모니터 사용하기 위해 초기화

  WiFi.begin(ssid, password); // WiFi  시작 초기화  가 되면  다음으로 넘어갑니다.

  Serial.println();
  Serial.print("Connecting"); //  WiFi 에 연결중  "Connecting "출력

  while(WiFi.status() != WL_CONNECTED)
   {
    delay(500);
    Serial.print("."); //연결될때 까지 출력
   }

   Serial.println("success!");  //연결이 완료되면..
   Serial.print("IP Address is: ");
   Serial.println(WiFi.localIP());   // 연결된 아이피가 출력됩니다.
}

void loop() {
  // put your main code here, to run repeatedly:
}
