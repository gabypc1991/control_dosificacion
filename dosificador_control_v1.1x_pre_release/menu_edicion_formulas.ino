void menu_4(){ 
  lcd.setCursor(0,0); lcd.print("Formula 1           ");
  lcd.setCursor(0,1); lcd.print("A>D1:");lcd.print(f1D1);
  lcd.setCursor(0,2); lcd.print("B>D2:");lcd.print(f1D2);
  lcd.setCursor(0,3); lcd.print("Volver >#  Prox. <*>");
}

void accion_4(){ 
    if(pulsacion == '#') {contador = 1;lcd.clear();}
    if(pulsacion == '*') {contador = 9;lcd.clear();}
    if(pulsacion == 'A') {contador = 5;lcd.clear();}
    if(pulsacion == 'B') {contador = 6;lcd.clear();}
}

    void menu_4_1(){     
      pos_col = 11;
      pos_fil = 2;
      lcd.setCursor(0,0); lcd.print("      Formula 1     ");
      lcd.setCursor(0,1); lcd.print("   DOSIS 1: ");lcd.print("(");lcd.print(f1D1);lcd.print(")");
      lcd.setCursor(0,2); lcd.print("VALOR (Kg):");
      lcd.setCursor(12,2);
      while(edit != true){
        lcd.setCursor(0,3); lcd.print("           Enter <#>");
        readVal();
        edit = true;
        f1D1 = myString.toInt();
        EEPROM.put(0, f1D1);        
        lcd.setCursor(12,2); lcd.print(f1D1);
        lcd.setCursor(0,3); lcd.print("CORRECTO");
        delay(800);               
        }
        contador = 4;
        edit = false; 
        lcd.clear();   
        //lcd.setCursor(0,3); lcd.print("            D2-> <*>");      
    }

    void accion_4_1(){         
        //if(pulsacion == '#') {contador = 4;edit = false;lcd.clear();}
                
    }

    void menu_4_2(){ 
      pos_col = 11;
      pos_fil = 2;
      lcd.setCursor(0,0); lcd.print("      Formula 1     ");
      lcd.setCursor(0,1); lcd.print("   DOSIS 1: ");lcd.print("(");lcd.print(f1D2);lcd.print(")");
      lcd.setCursor(0,2); lcd.print("VALOR (Kg):");
      lcd.setCursor(12,2); lcd.print(f1D2);
      while(edit != true){
        lcd.setCursor(0,3); lcd.print("           Enter <#>");
        readVal();
        edit = true;
        f1D2 = myString.toInt();        
        EEPROM.put(4, f1D2);          
        lcd.setCursor(12,2); lcd.print(f1D2);
        lcd.setCursor(0,3); lcd.print("CORRECTO");
        delay(800);
           
        }
        edit = false;
        contador = 4;
        lcd.clear();   
    }

    void accion_4_2(){ 
       // if(pulsacion == '*') {contador = 4;edit = false;lcd.clear();}
    }
