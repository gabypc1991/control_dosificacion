void menu_1(){ 
 lcd.setCursor(0,0); lcd.print("SELEC. FORMULA    >1");
 lcd.setCursor(0,1); lcd.print("EDIT. FORMULAS    >2");
 lcd.setCursor(0,2); lcd.print("BALANZA           >3");
 lcd.setCursor(12,3); lcd.print("Mas..<#>");
}

void accion_1(){ 
 if(pulsacion == '1') {contador = 2;lcd.clear(); pulsacion = ' ';}
 if(pulsacion == '2') {contador = 4;lcd.clear(); pulsacion = ' ';}
 if(pulsacion == '3') {contador = 14;lcd.clear(); pulsacion = ' ';}
 if(pulsacion == '#') {contador = 16;lcd.clear(); pulsacion = ' ';}
}

void menu_1_2(){ 
 lcd.setCursor(0,0); lcd.print("TIEMPO DESCARGA   >1");
 lcd.setCursor(0,1); lcd.print("TIEMPO MEZCLA     >2");
 lcd.setCursor(0,2); lcd.print("AJUSTES           >3");
 lcd.setCursor(10,3); lcd.print("Volver <#>");
}

void accion_1_2(){ 
 if(pulsacion == '1') {contador = 13;lcd.clear(); pulsacion = ' ';}
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
 if(pulsacion == '#') {contador = 1;lcd.clear();pulsacion = ' ';}
 if(pulsacion == '1') {contador = 3;lcd.clear();pulsacion = ' ';}
 if(pulsacion == '2') {contador = 21;lcd.clear();pulsacion = ' ';}
 if(pulsacion == '3') {contador = 22;lcd.clear();pulsacion = ' ';}
}

void menu_7(){      
 //pos_col = 12;
 //pos_fil = 2;
 bool edit_m = false;
 bool edit_s = false;
 int t_mezcla_m;
 int t_mezcla_s;
 lcd.setCursor(0,0); lcd.print("  TIEMPO DE MEZCLA   ");
 lcd.setCursor(0,1); lcd.print("                     ");
// lcd.setCursor(11,1); lcd.print("("); lcd.print(t_mezcla / 600); lcd.print(")");
 reloj_1(t_mezcla * 1000);
 reloj_1_print(7, 1);
 lcd.setCursor(3,1); lcd.print("-->>");
 lcd.setCursor(12,1); lcd.print("    ");
 lcd.setCursor(0,2); lcd.print("Set Minutos:");

 while(edit_m != true){
  lcd.setCursor(0,3); lcd.print("           Enter <#>");
  readVal(12, 2);
  if(myString != ""){
   edit_m = true;
   t_mezcla_m = myString.toInt();
   t_mezcla_m = t_mezcla_m * 60;
//   EEPROM.put(12, t_mezcla);   
   reloj_1(t_mezcla * 1000);
   reloj_1_print(7, 1);
//   lcd.setCursor(11,1); lcd.print("("); lcd.print(t_mezcla / 600); lcd.print(")");
   lcd.setCursor(0,3); lcd.print("CORRECTO");
   delay(800);
   }else{
    edit_m = true;
    }
  }

 lcd.setCursor(0,0); lcd.print("  TIEMPO DE MEZCLA   ");
 lcd.setCursor(0,1); lcd.print("                     ");
// lcd.setCursor(11,1); lcd.print("("); lcd.print(t_mezcla / 600); lcd.print(")");
 reloj_1(t_mezcla * 1000); 
 reloj_1_print(7, 1);
 lcd.setCursor(3,1); lcd.print("    ");
 lcd.setCursor(12,1); lcd.print("<<--");
 lcd.setCursor(0,2); lcd.print("Set Segundo:");
 
 while(edit_s != true){
  lcd.setCursor(0,3); lcd.print("           Enter <#>");
  readVal(12, 2);
  if(myString != ""){
   edit_s = true;
   t_mezcla_s = myString.toInt();
   t_mezcla = t_mezcla_m + t_mezcla_s;
   EEPROM.put(12, t_mezcla);
   reloj_1(t_mezcla * 1000);   
   reloj_1_print(7, 1);   
//   lcd.setCursor(11,1); lcd.print("("); lcd.print(t_mezcla / 600); lcd.print(")");
   lcd.setCursor(0,3); lcd.print("CORRECTO");
   delay(800);
   }else{
    edit_s = true;
    }
  }
 segundo_1 = 0;
 minutes_1 = 0;
 edit_m = false;
 edit_s = false;
 pulsacion = ' ';
 contador = 16;
 lcd.clear();
 }

void accion_7(){         
// if(pulsacion == '#') {contador = 4;lcd.clear();pulsacion = ' ';}
}

void menu_8(){     
 lcd.setCursor(0,0); lcd.print("D1|D2|D3|D4|>SALIDA ");      
 lcd.setCursor(0,2); lcd.print("I1|I2|I3|I4|<ENTRADA");
 lcd.setCursor(12,3); lcd.print("Volv.<#>");
 }

void accion_8(){
 if(pulsacion == '1' && act_d1 == false) {digitalWrite(pin_d1, LOW); act_d1 = true;
  }else if(pulsacion == '1' && act_d1 == true){digitalWrite(pin_d1, HIGH); act_d1 = false;}
 if(pulsacion == '2' && act_d2 == false) {digitalWrite(pin_d2, LOW); act_d2 = true;
  }else if(pulsacion == '2' && act_d2 == true){digitalWrite(pin_d2, HIGH); act_d2 = false;}
 if(pulsacion == '3' && act_d3 == false) {digitalWrite(pin_d3, LOW); act_d3 = true;
  }else if(pulsacion == '3' && act_d3 == true){digitalWrite(pin_d3, HIGH); act_d3 = false;}
 if(pulsacion == '4' && act_d4 == false) {digitalWrite(pin_d4, LOW); act_d4 = true;
  }else if(pulsacion == '4' && act_d4 == true){digitalWrite(pin_d4, HIGH); act_d4 = false;}

 if(act_d1 == true){lcd.setCursor(0,1); lcd.print("->|");}else{lcd.setCursor(0,1); lcd.print("  |");}
 if(act_d2 == true){lcd.setCursor(3,1); lcd.print("->|");}else{lcd.setCursor(3,1); lcd.print("  |");}
 if(act_d3 == true){lcd.setCursor(6,1); lcd.print("->|");}else{lcd.setCursor(6,1); lcd.print("  |");}
 if(act_d4 == true){lcd.setCursor(9,1); lcd.print("->|");}else{lcd.setCursor(9,1); lcd.print("  |");}

 if(act_in1 == true){lcd.setCursor(0,3); lcd.print("<-|");}else{lcd.setCursor(0,3); lcd.print("  |");}
 if(act_in2 == true){lcd.setCursor(3,3); lcd.print("<-|");}else{lcd.setCursor(3,3); lcd.print("  |");}
 if(act_in3 == true){lcd.setCursor(6,3); lcd.print("<-|");}else{lcd.setCursor(6,3); lcd.print("  |");}
 if(act_in4 == true){lcd.setCursor(9,3); lcd.print("<-|");}else{lcd.setCursor(9,3); lcd.print("  |");}
 
 if(pulsacion == '#') {contador = 19;lcd.clear();pulsacion = ' ';}
 }

void menu_9(){ 
 String pass = "1234";
 if(user != true){
  //pos_col = 4;
  //pos_fil = 1;
  lcd.setCursor(0,0); lcd.print("PASSWORD");
  lcd.setCursor(0,1); lcd.print("-->");
  lcd.setCursor(0,3); lcd.print("Enter <#>");
  readVal(4, 1);
  pass_temp = myString;
  user = true;
  }
   
 if(pass_temp == pass && user == true){
  lcd.setCursor(0,0); lcd.print("CALIBRAR BALANZA  >A");
  lcd.setCursor(0,1); lcd.print("ESTADO IO         >B");
  lcd.setCursor(0,2); lcd.print("PARAMETROS        >C");
  lcd.setCursor(0,3); lcd.print("Volver <#>");
  }else{
   lcd.setCursor(0,2); lcd.print("error");
   delay(800);
   user = false;
   pass_temp = "";
   contador = 1;
   lcd.clear();  
   }
 }

void accion_9(){ 
 if(pulsacion == 'A') {contador = 18;lcd.clear();pulsacion = ' ';}
 if(pulsacion == 'B') {contador = 17;lcd.clear();pulsacion = ' ';}
 if(pulsacion == 'C') {contador = 7;lcd.clear();pulsacion = ' ';}
 if(pulsacion == '#') {user = false;pass_temp = "";contador = 1;lcd.clear();pulsacion = ' ';}
 }

void menu_parametros(){
  lcd.setCursor(0,0); lcd.print("FACTOR CORRECCION >A");
  lcd.setCursor(0,1); lcd.print("TIEMPO ESTABILIZ. >B");
  lcd.setCursor(0,3); lcd.print("Volver <#>");
  }

void accion_parametros(){
  if(pulsacion == 'A') {contador = 12;lcd.clear();pulsacion = ' ';}
  if(pulsacion == 'B') {contador = 8;lcd.clear();pulsacion = ' ';}
  if(pulsacion == '#') {contador = 19;lcd.clear();pulsacion = ' ';}
  }

void menu_10(){
// pos_col1 = 8;
// pos_fil1 = 2; 
 lcd.setCursor(0,0); lcd.print("      MEZCLADOR     ");
 lcd.setCursor(0,1); lcd.print("  TIEMPO DE PROCESO ");
 lcd.setCursor(0,3); lcd.print("Volver<#>   Reini<*>");
 }

void accion_10(){
 reloj_1_print(8, 2); 
 if(pulsacion == '#') {contador = 1;lcd.clear();pulsacion = ' ';}
 if(pulsacion == '*') {
  tiempo_m = 0;
  now_1 = 0;
  hour_1=0;
  minutes_1=0;
  segundo_1=0;
  }
 }

void menu_edicionTDescarga(){      
 //pos_col = 12;
 //pos_fil = 2;
 bool edit_m = false;
 bool edit_s = false;
 int t_descarga_m;
 int t_descarga_s;
 lcd.setCursor(0,0); lcd.print(" TIEMPO DE DESCARGA  ");
 lcd.setCursor(0,1); lcd.print("                     ");
// lcd.setCursor(11,1); lcd.print("("); lcd.print(t_mezcla / 600); lcd.print(")");
 reloj_1(t_descarga * 1000);
 reloj_1_print(7, 1);
 lcd.setCursor(3,1); lcd.print("-->>");
 lcd.setCursor(12,1); lcd.print("    ");
 lcd.setCursor(0,2); lcd.print("Set Minutos:");

 while(edit_m != true){
  lcd.setCursor(0,3); lcd.print("           Enter <#>");
  readVal(12, 2);
  if(myString != ""){
   edit_m = true;
   t_descarga_m = myString.toInt();
   t_descarga_m = t_descarga_m * 60;
//   EEPROM.put(12, t_mezcla);   
   reloj_1(t_descarga * 1000);
   reloj_1_print(7, 1);
//   lcd.setCursor(11,1); lcd.print("("); lcd.print(t_mezcla / 600); lcd.print(")");
   lcd.setCursor(0,3); lcd.print("CORRECTO");
   delay(800);
   }else{
    edit_m = true;
    }
  }

 lcd.setCursor(0,0); lcd.print(" TIEMPO DE DESCARGA  ");
 lcd.setCursor(0,1); lcd.print("                     ");
// lcd.setCursor(11,1); lcd.print("("); lcd.print(t_mezcla / 600); lcd.print(")");
 reloj_1(t_descarga * 1000); 
 reloj_1_print(7, 1);
 lcd.setCursor(3,1); lcd.print("    ");
 lcd.setCursor(12,1); lcd.print("<<--");
 lcd.setCursor(0,2); lcd.print("Set Segundo:");
 
 while(edit_s != true){
  lcd.setCursor(0,3); lcd.print("           Enter <#>");
  readVal(12, 2);
  if(myString != ""){
   edit_s = true;
   t_descarga_s = myString.toInt();
   t_descarga = t_descarga_m + t_descarga_s;
   EEPROM.put(32, t_descarga);
   reloj_1(t_descarga * 1000);   
   reloj_1_print(7, 1);   
//   lcd.setCursor(11,1); lcd.print("("); lcd.print(t_mezcla / 600); lcd.print(")");
   lcd.setCursor(0,3); lcd.print("CORRECTO");
   delay(800);
   }else{
    edit_s = true;
    }
  }
 segundo_1 = 0;
 minutes_1 = 0;
 edit_m = false;
 edit_s = false;
 pulsacion = ' ';
 contador = 16;
 lcd.clear();
 }

void accion_edicionTDescarga(){         
// if(pulsacion == '#') {contador = 4;lcd.clear();pulsacion = ' ';}
}

void menu_edicionFactorPeso(){ 
 lcd.setCursor(0,0); lcd.print(" FACTOR CORRECCION  ");
 lcd.setCursor(0,1); lcd.print("        PESO        "); 
 lcd.setCursor(0,2); lcd.print("Set kg:");
 lcd.setCursor(0,3); lcd.print("1>+ | 2>-  Enter <#>");

 }

void accion_edicionFactorPeso(){          
  if (pulsacion == '1'){factor_delay_temp +=1;}
  if (pulsacion == '2'){factor_delay_temp -=1;}
  
  lcd.setCursor(8,2); lcd.print(factor_delay_temp);

  if (pulsacion == '#'){
    t_delay_factor = factor_delay_temp;
    EEPROM.put(36, t_delay_factor);
    lcd.setCursor(0,3); lcd.print("CORRECTO            ");
    delay(800);
    pulsacion = ' ';
    contador = 7;
    lcd.clear();
    }
}

void menu_edicionTEstabiliz(){
 bool edit_m = false;
 bool edit_s = false;
 int t_estabilizacion_m;
 int t_estabilizacion_s;
 lcd.setCursor(0,0); lcd.print("  t ESTABILIZ BAL.   ");
 lcd.setCursor(0,1); lcd.print("                     ");
 reloj_1(t_estabilizacion * 1000);
 reloj_1_print(7, 1);
 lcd.setCursor(3,1); lcd.print("-->>");
 lcd.setCursor(12,1); lcd.print("    ");
 lcd.setCursor(0,2); lcd.print("Set Minutos:");

 while(edit_m != true){
  lcd.setCursor(0,3); lcd.print("           Enter <#>");
  readVal(12, 2);
  if(myString != ""){
   edit_m = true;
   t_estabilizacion_m = myString.toInt();
   t_estabilizacion_m = t_estabilizacion_m * 60; 
   reloj_1(t_estabilizacion * 1000);
   reloj_1_print(7, 1);
   lcd.setCursor(0,3); lcd.print("CORRECTO");
   delay(800);
   }else{
    edit_m = true;
    }
  }

 lcd.setCursor(0,0); lcd.print("  t ESTABILIZ BAL.   ");
 lcd.setCursor(0,1); lcd.print("                     ");
 reloj_1(t_estabilizacion * 1000); 
 reloj_1_print(7, 1);
 lcd.setCursor(3,1); lcd.print("    ");
 lcd.setCursor(12,1); lcd.print("<<--");
 lcd.setCursor(0,2); lcd.print("Set Segundo:");
 
 while(edit_s != true){
  lcd.setCursor(0,3); lcd.print("           Enter <#>");
  readVal(12, 2);
  if(myString != ""){
   edit_s = true;
   t_estabilizacion_s = myString.toInt();
   t_estabilizacion = t_estabilizacion_m + t_estabilizacion_s;
   EEPROM.put(40, t_estabilizacion);
   reloj_1(t_estabilizacion * 1000);   
   reloj_1_print(7, 1);
   lcd.setCursor(0,3); lcd.print("CORRECTO");
   delay(800);
   }else{
    edit_s = true;
    }
  }
 segundo_1 = 0;
 minutes_1 = 0;
 edit_m = false;
 edit_s = false; 
 pulsacion = ' ';
 contador = 7;
 lcd.clear();
 }

void accion_edicionTEstabiliz(){         
// if(pulsacion == '#') {contador = 4;lcd.clear();pulsacion = ' ';}
}
