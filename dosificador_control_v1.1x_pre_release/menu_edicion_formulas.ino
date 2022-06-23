void menu_4(){ 
  lcd.setCursor(0,0); lcd.print("Formula 1           ");
  lcd.setCursor(0,1); lcd.print("A>D1:");lcd.print(f1D1);
  lcd.setCursor(0,2); lcd.print("B>D2:");lcd.print(f1D2);
  lcd.setCursor(0,3); lcd.print("Volver >#  Prox. <*>");
}

void accion_4(){ 
    if(pulsacion == '#') {contador = 1;lcd.clear();pulsacion = ' ';}
    if(pulsacion == '*') {contador = 9;lcd.clear();pulsacion = ' ';}
    if(pulsacion == 'A') {contador = 5;lcd.clear();pulsacion = ' ';}
    if(pulsacion == 'B') {contador = 6;lcd.clear();pulsacion = ' ';}
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
        //if(pulsacion == '#') {contador = 4;edit = false;lcd.clear();pulsacion = ' ';}
                
    }

    void menu_4_2(){ 
      pos_col = 11;
      pos_fil = 2;
      lcd.setCursor(0,0); lcd.print("      Formula 1     ");
      lcd.setCursor(0,1); lcd.print("   DOSIS 2: ");lcd.print("(");lcd.print(f1D2);lcd.print(")");
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

void menu_5(){ 
  lcd.setCursor(0,0); lcd.print("Formula 2           ");
  lcd.setCursor(0,1); lcd.print("A>D1:");lcd.print(f2D1);
  lcd.setCursor(0,2); lcd.print("B>D2:");lcd.print(f2D2);
  lcd.setCursor(0,3); lcd.print("Volver >#  Prox. <*>");
}

void accion_5(){ 
    if(pulsacion == '#') {contador = 1;lcd.clear();pulsacion = ' ';}
    if(pulsacion == '*') {contador = 23;lcd.clear();pulsacion = ' ';}
    if(pulsacion == 'A') {contador = 10;lcd.clear();pulsacion = ' ';}
    if(pulsacion == 'B') {contador = 11;lcd.clear();pulsacion = ' ';}
}

void menu_5_1(){ 
 pos_col = 11;
 pos_fil = 2;
 lcd.setCursor(0,0); lcd.print("      Formula 2     ");
 lcd.setCursor(0,1); lcd.print("   DOSIS 1: ");lcd.print("(");lcd.print(f2D1);lcd.print(")");
 lcd.setCursor(0,2); lcd.print("VALOR (Kg):");
 lcd.setCursor(12,2); lcd.print(f2D1);
 while(edit != true){
  lcd.setCursor(0,3); lcd.print("           Enter <#>");
  readVal();
  edit = true;
  f2D1 = myString.toInt();
  EEPROM.put(16, f2D1);        
  lcd.setCursor(12,2); lcd.print(f2D1);
  lcd.setCursor(0,3); lcd.print("CORRECTO");
  delay(800);               
  }
 contador = 9;
 edit = false; 
 lcd.clear();
 }

void accion_5_1(){ 
// if(pulsacion == '*') {contador = 11;lcd.clear();}
   }

void menu_5_2(){ 
 pos_col = 11;
 pos_fil = 2;
 lcd.setCursor(0,0); lcd.print("      Formula 2     ");
 lcd.setCursor(0,1); lcd.print("   DOSIS 2: ");lcd.print("(");lcd.print(f2D2);lcd.print(")");
 lcd.setCursor(0,2); lcd.print("VALOR (Kg):");
 lcd.setCursor(12,2); lcd.print(f2D2);
 while(edit != true){
  lcd.setCursor(0,3); lcd.print("           Enter <#>");
  readVal();
  edit = true;
  f2D2 = myString.toInt();
  EEPROM.put(20, f2D2);        
  lcd.setCursor(12,2); lcd.print(f2D2);
  lcd.setCursor(0,3); lcd.print("CORRECTO");
  delay(800);               
  }
 contador = 9;
 edit = false; 
 lcd.clear();
 }

void accion_5_2(){ 
// if(pulsacion == '*') {contador = 12;lcd.clear();}
   }

void menu_11(){ 
 lcd.setCursor(0,0); lcd.print("Formula 3           ");
 lcd.setCursor(0,1); lcd.print("A>D1:");lcd.print(f3D1);
 lcd.setCursor(0,2); lcd.print("B>D2:");lcd.print(f3D2);
 lcd.setCursor(0,3); lcd.print("Volver >#           ");
 }

void accion_11(){ 
 if(pulsacion == '#') {contador = 1;lcd.clear();}
 if(pulsacion == 'A') {contador = 24;lcd.clear();}
 if(pulsacion == 'B') {contador = 25;lcd.clear();}
 }

void menu_11_1(){ 
 pos_col = 11;
 pos_fil = 2;
 lcd.setCursor(0,0); lcd.print("      Formula 3     ");
 lcd.setCursor(0,1); lcd.print("   DOSIS 1: ");lcd.print("(");lcd.print(f3D1);lcd.print(")");
 lcd.setCursor(0,2); lcd.print("VALOR (Kg):");
 lcd.setCursor(12,2); lcd.print(f3D1);
 while(edit != true){
  lcd.setCursor(0,3); lcd.print("           Enter <#>");
  readVal();
  edit = true;
  f3D1 = myString.toInt();
  EEPROM.put(24, f3D1);        
  lcd.setCursor(12,2); lcd.print(f3D1);
  lcd.setCursor(0,3); lcd.print("CORRECTO");
  delay(800);               
  }
 contador = 23;
 edit = false; 
 lcd.clear();
 }

void accion_11_1(){ 
// if(pulsacion == '*') {contador = 11;lcd.clear();}
   }


void menu_11_2(){ 
 pos_col = 11;
 pos_fil = 2;
 lcd.setCursor(0,0); lcd.print("      Formula 3     ");
 lcd.setCursor(0,1); lcd.print("   DOSIS 2: ");lcd.print("(");lcd.print(f3D2);lcd.print(")");
 lcd.setCursor(0,2); lcd.print("VALOR (Kg):");
 lcd.setCursor(12,2); lcd.print(f3D2);
 while(edit != true){
  lcd.setCursor(0,3); lcd.print("           Enter <#>");
  readVal();
  edit = true;
  f3D2 = myString.toInt();
  EEPROM.put(28, f3D2);        
  lcd.setCursor(12,2); lcd.print(f3D2);
  lcd.setCursor(0,3); lcd.print("CORRECTO");
  delay(800);               
  }
 contador = 23;
 edit = false; 
 lcd.clear();
 }

void accion_11_2(){ 
// if(pulsacion == '*') {contador = 11;lcd.clear();}
   }
