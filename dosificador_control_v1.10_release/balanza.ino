void menu_6(){ 
 lcd.setCursor(0,0); lcd.print("   SENSOR BALANZA   ");
 lcd.setCursor(0,1); lcd.print("      TARA  <*>     ");
 lcd.setCursor(0,2); lcd.print("VALOR (Kg):");
 lcd.setCursor(11,2); lcd.print(balanza_bruto);lcd.print("   ");
 lcd.setCursor(0,3); lcd.print("          Volver <#>");            
 }

void accion_6(){                 
 if(pulsacion == '#') {contador = 1;lcd.clear();pulsacion = ' ';}
 if(pulsacion == '*') {balanza_hx.tare(20);}                
 }

void calibrar_balanza(){ 
 lcd.setCursor(0,0); lcd.print("Factor:");
 lcd.setCursor(0,1); lcd.print("COLOQUE PESO DE REF.");
 lcd.setCursor(0,2); lcd.print("VALOR (Kg):");
 lcd.setCursor(0,3); lcd.print("1>+ | 2>-  Enter <#>");            
 }

void accion_calibrar(){
  balanza_hx.set_scale(factor_temp);        
  
  lcd.setCursor(11,2); lcd.print(balanza);lcd.print("   ");
  
  if (pulsacion == '1'){factor_temp +=10;}
  if (pulsacion == '2'){factor_temp -=10;}

  if (pulsacion == '4'){factor_temp +=100;}
  if (pulsacion == '5'){factor_temp -=100;}

  if (pulsacion == '7'){factor_temp +=1000;}
  if (pulsacion == '8'){factor_temp -=1000;}
  
  lcd.setCursor(7,0); lcd.print(factor_temp);
  
  if (pulsacion == '#'){
    factor = factor_temp;
    balanza_hx.set_scale(factor);
    EEPROM.put(8, factor);
    lcd.setCursor(0,3); lcd.print("CORRECTO            ");
    delay(800);    
    pulsacion = ' ';
    contador = 19;
    lcd.clear();
    }
  }
