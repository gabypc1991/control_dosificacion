void reloj(int col, int fil) {
  if(tiempo > now + 6){
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
  lcd.setCursor(col, fil);
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

void reloj_1(long ms) {
 int seg = ms / 1000;
 seg = seg % 60;
 int minutos = (ms / 1000) / 60;
 minutos = minutos % 60;
 int horas = ((ms / 1000) / 60) / 60;
 horas = horas % 60;

 segundo_1 = seg;
 minutes_1 = minutos;
 hour_1 = horas;
 }

void reloj_1_print(int col, int fil) {  
  lcd.setCursor(col, fil);
  if(minutes_1<10)lcd.print("0");
  lcd.print(minutes_1);
  lcd.print(":");
  if(segundo_1<10)lcd.print("0");
  lcd.print(segundo_1);
  lcd.print(" ");
 }
