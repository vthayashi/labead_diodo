// UNOfonte_200920a

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (Serial.available()) {
    String str;
    str = Serial.readStringUntil('\r');
    str.trim();
    str.replace("\n", "");
    if (str.length() > 0) {
      str = "?" + str;
      str.replace("??", "&");
      str.replace("?", "&");
      serial_run(str);
    }
  }
}

void serial_run(String str) {
  String sa, sb;
  /////&aw=[port],[value]
  sa="&aw="; 
  if (str.indexOf(sa) >= 0) {
    sb = str.substring(str.indexOf(sa) + sa.length()) + "&";
    sb = sb.substring(0, sb.indexOf("&"));
    uint16_t port, value;
    port = sb.substring(0, sb.indexOf(",")).toInt();
    value = sb.substring(sb.indexOf(",") + 1).toInt();
    analogWrite(port,value);
  }
  String pg="{";
  
  //
  sa="&ar="; // &ar=[porta],[porta-porta],...
  if (str.indexOf(sa) >= 0) {
    pg+="\"ar\":[";
    sb=str.substring( str.indexOf(sa) + sa.length() )+"&";
    sb=sb.substring(0,sb.indexOf("&"))+",";
    String sc;
    while(sb.indexOf(",")>=0){
      sc=sb.substring(0,sb.indexOf(","));
      sb=sb.substring(sb.indexOf(",")+1);
      if(sc.indexOf("-")>0){
        uint8_t ini=sc.substring(0,sc.indexOf("-")).toInt();
        uint8_t fim=sc.substring(sc.indexOf("-")+1).toInt();
        for(uint8_t i=ini;i<=fim;i++){
          pg += analogRead(A0+i);
          pg += ",";
        }
      }else{
        uint8_t pin=sc.toInt();
        pg += analogRead(A0+pin);
        pg += ",";
      }
    }
    pg=pg.substring(0,pg.length()-1);
    Serial.print(pg+"]"); pg=",";
  }
  
  // json fim
  if(pg==",") pg="";
  pg+="}\n";
  Serial.print(pg);
}
  
