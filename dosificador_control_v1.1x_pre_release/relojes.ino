int ms_to_hora(int ms){
  int seg = ms / 1000;
  int minutos = seg / 60;
  int horas = minutos / 60;
  }
  
void reloj() {
  if(tiempo > now + 9){//cada segunto
    now = tiempo;    
    segundo++;
  if(segundo>59){
    minutes++;
    segundo=0;
  }
  if(minutes>59){
    hour++;
    minutes=0;
    segundo=0;
  }
  if(hour>=24){
    hour=0;
    minutes=0;
    segundo=0;
  }
  lcd.setCursor(pos_col,pos_fil);
  if(hour<10)lcd.print("0");
  lcd.print(hour);
  lcd.print(":");
  if(minutes<10)lcd.print("0");
  lcd.print(minutes);
  lcd.print(":");
  if(segundo<10)lcd.print("0");
  lcd.print(segundo);
 }
}

void reloj_1() {
 if(tiempo_m > now_1 + 9){
  now_1 = tiempo_m;    
  segundo_1++;
  if(segundo_1>59){
   minutes_1++;
   segundo_1=0;
   }
  if(minutes_1>59){
   hour_1++;
   minutes_1=0;
   segundo_1=0;
   }
  if(hour_1>=24){
   hour_1=0;
   minutes_1=0;
   segundo_1=0;
   }  
 }
}

void reloj_1_print() {  
  lcd.setCursor(pos_col1,pos_fil1);
  if(minutes_1<10)lcd.print("0");
  lcd.print(minutes_1);
  lcd.print(":");
  if(segundo_1<10)lcd.print("0");
  lcd.print(segundo_1);
 }
