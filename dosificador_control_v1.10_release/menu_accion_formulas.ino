void menu_selecFormula(){ 
  lcd.setCursor(0,0); lcd.print("Selec. Formula ");lcd.print(contador_formula + 1);
  lcd.setCursor(0,1); lcd.print("D1:");lcd.print(dosis_1[contador_formula]);
  lcd.setCursor(12,1); lcd.print("D2:");lcd.print(dosis_2[contador_formula]);
  lcd.setCursor(0,2); lcd.print("          Elegir <*>");
  lcd.setCursor(0,3); lcd.print("<-C | D->  Volver<#>");
}

void accion_selecFormula(){ 
    if(pulsacion == '#') {contador = 1;contador_formula = 0;lcd.clear();pulsacion = ' ';}
    if(pulsacion == '*') {contador = 3;lcd.clear();pulsacion = ' ';}
    if(pulsacion == 'D') {contador_formula += 1;if(contador_formula > 23){contador_formula = 0;} lcd.clear();pulsacion = ' ';}
    if(pulsacion == 'C') {contador_formula -= 1;if(contador_formula < 0){contador_formula = 23;} lcd.clear();pulsacion = ' ';}
}


void menu_formula(){
  lcd.setCursor(0,0); lcd.print("Form.");lcd.print(contador_formula + 1);
  lcd.setCursor(9,0); lcd.print("t:");
  lcd.setCursor(13,3); lcd.print("Salir>#");
  lcd.setCursor(0,3);lcd.print("Bal.Kg:");lcd.print(balanza);lcd.print("  ");
  lcd.setCursor(0,1); lcd.print("D1(");
  lcd.setCursor(3,1); lcd.print(dosis_1[contador_formula]);
  lcd.setCursor(6,1); lcd.print(")");
  lcd.setCursor(0,2); lcd.print("D2(");
  lcd.setCursor(3,2); lcd.print(dosis_2[contador_formula]);
  lcd.setCursor(6,2); lcd.print(")");
  if(ciclo_descarga != true){lcd.setCursor(13,1); lcd.print("MEZCLA");}else{lcd.setCursor(13,1); lcd.print("DESCAR");}
  if(proc_comp == true){lcd.setCursor(11,0); lcd.print("FINALIZ.");}
  }

void accion_formula(){ 
   if(pulsacion == '#') {contador = 16;contador_formula = 0;proc_comp = false;lcd.clear();pulsacion = ' ';}
   reloj_1_print(14, 2);
   if((pulsacion == '*' || act_in3 != true) && balanza < 5) {
    
   proc_activo = true;
   
   while(proc_activo != false){
       int peso_temp;
       int peso_d1;
       int peso_d2;
       if(ciclo_descarga != true){lcd.setCursor(13,1); lcd.print("MEZCLA");}else{lcd.setCursor(13,1); lcd.print("DESCAR");}
       lcd.setCursor(0,3);lcd.print("                    ");
       lcd.setCursor(0,3);lcd.print("Bal.Kg:");

     if(dosis_1[contador_formula] != 0){   
       while(peso_temp < (dosis_1[contador_formula] - result_bal)) {      
         pulsacion = Teclado1.getKey();
         if(balanza > (dosis_1[contador_formula] + 10)){digitalWrite(pin_d1, HIGH); act_d1 = false; digitalWrite(pin_d2, HIGH); act_d2 = false; break;}
         if(ciclo_descarga != true){lcd.setCursor(13,1); lcd.print("MEZCLA");}else{lcd.setCursor(13,1); lcd.print("DESCAR");}
         lcd.setCursor(8,3);lcd.print(balanza);lcd.print("   ");
         if(pulsacion == '#') break;
         peso_temp = balanza;
//         if(peso_temp < 0){peso_temp = 0;}
         peso_d1 = peso_temp;
         if(peso_d1 > (dosis_1[contador_formula] / 2) && estab_comp != true){digitalWrite(pin_d1, HIGH);estabilizacion(); estab_comp = true;}
         digitalWrite(pin_d1, LOW); act_d1 = true;
         tiempo += 1;
         reloj(11, 0);
         reloj_1_print(14, 2);
         lcd.setCursor(7,1);lcd.print(peso_d1);lcd.print("  ");
         delay(100);            
         }
      digitalWrite(pin_d1, HIGH); act_d1 = false;            
      lcd.setCursor(11,0); lcd.print("ESTABIL.");delay(t_estabilizacion * 1000);
     
      peso_d1 = balanza;
      lcd.setCursor(7,1);lcd.print(peso_d1); lcd.print("  ");
      peso_temp = 0;   
      result_bal = 0;
      estab_comp = false;
     }

    if(dosis_2[contador_formula] != 0){  
      while(peso_temp < (dosis_2[contador_formula] - result_bal)){
         pulsacion = Teclado1.getKey();
         if(balanza > (peso_d1 + dosis_2[contador_formula] + 5)){digitalWrite(pin_d1, HIGH); act_d1 = false; digitalWrite(pin_d2, HIGH); act_d2 = false; break;}
         if(ciclo_descarga != true){lcd.setCursor(13,1); lcd.print("MEZCLA");}else{lcd.setCursor(13,1); lcd.print("DESCAR");}
         lcd.setCursor(8,3);lcd.print(balanza);lcd.print("   ");
         if(pulsacion == '#') break;
         peso_temp = balanza - peso_d1;
         peso_d2 = peso_temp;
         if(peso_d2 > (dosis_2[contador_formula] / 2) && estab_comp != true){digitalWrite(pin_d2, HIGH);estabilizacion(); estab_comp = true;}
         digitalWrite(pin_d2, LOW); act_d2 = true;
         tiempo += 1;
         reloj(11, 0);
         reloj_1_print(14, 2);
         lcd.setCursor(7,2);lcd.print(peso_d2);lcd.print(" ");         
         delay(100);            
         }
      digitalWrite(pin_d2, HIGH); act_d2 = false;
      lcd.setCursor(11,0); lcd.print("ESTABIL.");delay(t_estabilizacion * 1000);
    
      peso_d2 = balanza - peso_d1;
      lcd.setCursor(7,2);lcd.print(peso_d2);
      peso_temp = 0;   
      result_bal = 0;
      estab_comp = false;
    }      
      tiempo = 0;
      now = 0;
      hour=0;
      minutes=0;
      segundo=0;
      peso_temp = 0;   
      result_bal = 0;
      peso_d1 = 0;
      peso_d2 = 0;
      digitalWrite(pin_d1, HIGH); act_d1 = false;
      digitalWrite(pin_d2, HIGH); act_d2 = false;               
      proc_activo = false;
      proc_comp = true;
    }
   }else if((pulsacion == '*' || act_in3 != true) && balanza > 5){
      lcd.setCursor(0,3);lcd.print("err_bal");
      delay(1000);
    }    
  }
  

void estabilizacion(){
  int bal_1;
  int bal_2;
    
  bal_1 = balanza;  
  lcd.setCursor(11,0); lcd.print(" CONTROL ");
  delay(t_estabilizacion * 1000);   
  bal_2 = balanza;    
  result_bal = bal_2 - bal_1 + t_delay_factor;
  }

void parada_em(){
  tiempo = 0;
  now = 0;
  hour=0;
  minutes=0;
  segundo=0;             
  proc_activo = false;
  proc_comp = true;
  digitalWrite(pin_d1, HIGH);
  digitalWrite(pin_d2, HIGH);
  digitalWrite(pin_d3, HIGH);
  contador = 16;
  contador_formula = 0;
  pulsacion = ' ';  
  }
