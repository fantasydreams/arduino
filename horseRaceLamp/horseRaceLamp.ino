int startPin = 2,endPin = 13;
void setup() {
    // put your setup code here, to run once:
    for(int pin = startPin;pin <= endPin;++pin){
        pinMode(pin,OUTPUT);
    }

}


int idx = 0,prePin = 0;
void loop() {
    // put your main code here, to run repeatedly:
    digitalWrite(startPin + prePin,LOW);
    idx =( idx + 1 ) % (endPin - startPin + 1);
    digitalWrite(startPin + idx,HIGH);
    prePin = idx;
    delay(100);
}
