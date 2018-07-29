int startPin = 2,endPin = 13;
int preIdx = startPin,idx = startPin;
void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    for(int idx = startPin;idx <= endPin;++idx){
        pinMode(idx,OUTPUT);
    }
}

int StrTOInt(String str){
    int res = 0,factor = 1;
    int idx = 0;
    factor = ('-' == str[idx])?(++idx,-1):1;
    while('0'<=str[idx] && str[idx] <= '9'){
        res = 10 * res + str[idx++] - '0';
    }
    return res * factor;
}

String str = "";
int val;
void loop() {
    // put your main code here, to run repeatedly:
    while(Serial.available()){
        str += char(Serial.read());
        delay(2); // this line must be here,is delay time is to small,serial port can not read data correctly
    }
    val = StrTOInt(str);
    str = "";
    if(val) {
        Serial.println(val);
        delay(100);
    }
    if(val < startPin || val > endPin )return;
    digitalWrite(preIdx, LOW);
    digitalWrite(val, HIGH);
    preIdx = val;
}
