void menu_1(){ 
   lcd.setCursor(0,0); lcd.print("SELEC. FORMULA    >1");
   lcd.setCursor(0,1); lcd.print("EDIT. FORMULAS    >2");
   lcd.setCursor(0,2); lcd.print("MEZCLADO          >3");
   lcd.setCursor(12,3); lcd.print("Mas..<#>");
}

void accion_1(){ 
  if(pulsacion == '1') {contador = 2;lcd.clear(); pulsacion = ' ';}
  if(pulsacion == '2') {contador = 4;lcd.clear(); pulsacion = ' ';}
  if(pulsacion == '3') {contador = 20;lcd.clear(); pulsacion = ' ';}
  if(pulsacion == '#') {contador = 16;lcd.clear(); pulsacion = ' ';}
}

void menu_1_2(){ 
   lcd.setCursor(0,0); lcd.print("BALANZA           >1");
   lcd.setCursor(0,1); lcd.print("TIEMPO MEZCLA     >2");
   lcd.setCursor(0,2); lcd.print("AJUSTES           >3");
   lcd.setCursor(10,3); lcd.print("Volver <#>");
}

void accion_1_2(){ 
  if(pulsacion == '1') {contador = 14;lcd.clear(); pulsacion = ' ';}
  if(pulsacion == '2') {contador = 15;lcd.clear(); pulsacion = ' ';}
  if(pulsacion == '3') {contador = 19;lcd.clear(); pulsacion = ' ';}
  if(pulsacion == '#') {contador = 1;lcd.clear(); pulsacion = ' ';}
}

void menu_2(){ 
   lcd.setCursor(0,0); lcd.print("FORM1 <1>           ");
   lcd.setCursor(0,1); lcd.print("FORM2 <2>           ");
   lcd.setCursor(0,2); lcd.print("FORM3 <3>           ");
   lcd.setCursor(10,3); lcd.print("Volver <#>");
}

void accion_2(){ 
    if(pulsacion == '#') {contador = 1;lcd.clear();}
    if(pulsacion == '1') {contador = 3;lcd.clear();}
    if(pulsacion == '2') {contador = 21;lcd.clear();}
    if(pulsacion == '3') {contador = 22;lcd.clear();}
}
