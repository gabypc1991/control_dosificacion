/////////////////////Menu_3  //////////////////////////////////
void menu_3(){
//  pos_col = 11;
//  pos_fil = 0;
//  pos_col1 = 14;
//  pos_fil1 = 2; 
  lcd.setCursor(0,0); lcd.print("Form.1   t:");
  lcd.setCursor(13,3); lcd.print("Salir>#");
  lcd.setCursor(0,3);lcd.print("Bal.Kg:");lcd.print(balanza);lcd.print("  ");
  lcd.setCursor(0,1); lcd.print("D1(");
  lcd.setCursor(3,1); lcd.print(f1D1);
  lcd.setCursor(6,1); lcd.print(")");
  lcd.setCursor(0,2); lcd.print("D2(");
  lcd.setCursor(3,2); lcd.print(f1D2);
  lcd.setCursor(6,2); lcd.print(")");
  if(ciclo_descarga != true){lcd.setCursor(13,1); lcd.print("MEZCLA");}else{lcd.setCursor(13,1); lcd.print("DESCAR");}
  if(proc_comp == true){lcd.setCursor(11,0); lcd.print("FINALIZ.");}
//  if(proc_comp == false){
//    lcd.setCursor(0,3);lcd.print("Bal.Kg:");lcd.print(balanza);lcd.print("  ");
//    lcd.setCursor(14,3); lcd.print("Inic->");
//  }else if(proc_comp == true){
//    lcd.setCursor(0,3);lcd.print("Bal.Kg:");lcd.print(balanza);lcd.print("  ");
//    lcd.setCursor(14,3);lcd.print("Otra->");
//  }  
}
/////////////////////Accion 3 //////////////////////////////
void accion_3(){ 
   if(pulsacion == '#') {contador = 2;proc_comp = false;lcd.clear();pulsacion = ' ';}
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

     if(f1D1 != 0){   
       while(peso_temp < (f1D1 - result_bal)) {      
         pulsacion = Teclado1.getKey();
         if(ciclo_descarga != true){lcd.setCursor(13,1); lcd.print("MEZCLA");}else{lcd.setCursor(13,1); lcd.print("DESCAR");}
         lcd.setCursor(8,3);lcd.print(balanza);lcd.print("   ");
         if(pulsacion == '#') break;
         peso_temp = balanza;
         peso_d1 = peso_temp;
         if(peso_d1 > (f1D1 / 2) && estab_comp != true){digitalWrite(pin_d1, HIGH);estabilizacion(); estab_comp = true;}
         digitalWrite(pin_d1, LOW); act_d1 = true;
         tiempo += 1;
         reloj(11, 0);
         reloj_1_print(14, 2);
         lcd.setCursor(7,1);lcd.print(peso_d1);lcd.print(" ");
         delay(100);            
         }
      digitalWrite(pin_d1, HIGH); act_d1 = false;            
      lcd.setCursor(11,0); lcd.print("ESTABIL.");delay(t_estabilizacion * 1000);
     
      peso_d1 = balanza;
      lcd.setCursor(7,1);lcd.print(peso_d1); 
      peso_temp = 0;   
      result_bal = 0;
      estab_comp = false;
     }

    if(f1D2 != 0){  
      while(peso_temp < (f1D2 - result_bal)){
         pulsacion = Teclado1.getKey();
         if(ciclo_descarga != true){lcd.setCursor(13,1); lcd.print("MEZCLA");}else{lcd.setCursor(13,1); lcd.print("DESCAR");}
         lcd.setCursor(8,3);lcd.print(balanza);lcd.print("   ");
         if(pulsacion == '#') break;
         peso_temp = balanza - peso_d1;
         peso_d2 = peso_temp;
         if(peso_d2 > (f1D2 / 2) && estab_comp != true){digitalWrite(pin_d2, HIGH);estabilizacion(); estab_comp = true;}
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
      proc_activo = false;
      proc_comp = true;
    }
   }else if((pulsacion == '*' || act_in3 != true) && balanza > 5){
      lcd.setCursor(0,3);lcd.print("err_bal");
      delay(1000);
    }    
  }
  

/////////////////////Menu_3  //////////////////////////////////
void menu_3_1(){
//  pos_col = 11;
//  pos_fil = 0;
//  pos_col1 = 14;
//  pos_fil1 = 2; 
  lcd.setCursor(0,0); lcd.print("Form.2   t:");
  lcd.setCursor(13,3); lcd.print("Salir>#");
  lcd.setCursor(0,3);lcd.print("Bal.Kg:");lcd.print(balanza);lcd.print("  ");
  lcd.setCursor(0,1); lcd.print("D1(");
  lcd.setCursor(3,1); lcd.print(f2D1);
  lcd.setCursor(6,1); lcd.print(")");
  lcd.setCursor(0,2); lcd.print("D2(");
  lcd.setCursor(3,2); lcd.print(f2D2);
  lcd.setCursor(6,2); lcd.print(")");
  if(ciclo_descarga != true){lcd.setCursor(13,1); lcd.print("MEZCLA");}else{lcd.setCursor(13,1); lcd.print("DESCAR");}
  if(proc_comp == true){lcd.setCursor(11,0); lcd.print("FINALIZ.");}
//  if(proc_comp == false){
//    lcd.setCursor(0,3);lcd.print("Bal.Kg:");lcd.print(balanza);lcd.print("  ");
//    lcd.setCursor(14,3); lcd.print("Inic->");
//  }else if(proc_comp == true){
//    lcd.setCursor(0,3);lcd.print("Bal.Kg:");lcd.print(balanza);lcd.print("  ");
//    lcd.setCursor(14,3);lcd.print("Otra->");
//  }  
}
/////////////////////Accion 3 //////////////////////////////
void accion_3_1(){ 
   if(pulsacion == '#') {contador = 2;proc_comp = false;lcd.clear();pulsacion = ' ';}
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

     if(f2D1 != 0){   
       while(peso_temp < (f2D1 - result_bal)) {      
         pulsacion = Teclado1.getKey();
         if(ciclo_descarga != true){lcd.setCursor(13,1); lcd.print("MEZCLA");}else{lcd.setCursor(13,1); lcd.print("DESCAR");}
         lcd.setCursor(8,3);lcd.print(balanza);lcd.print("   ");
         if(pulsacion == '#') break;
         peso_temp = balanza;
         peso_d1 = peso_temp;
         if(peso_d1 > (f2D1 / 2) && estab_comp != true){digitalWrite(pin_d1, HIGH);estabilizacion(); estab_comp = true;}
         digitalWrite(pin_d1, LOW); act_d1 = true;
         tiempo += 1;
         reloj(11, 0);
         reloj_1_print(14, 2);
         lcd.setCursor(7,1);lcd.print(peso_d1);lcd.print(" ");
         delay(100);            
         }
      digitalWrite(pin_d1, HIGH); act_d1 = false;            
      lcd.setCursor(11,0); lcd.print("ESTABIL.");delay(t_estabilizacion * 1000);
     
      peso_d1 = balanza;
      lcd.setCursor(7,1);lcd.print(peso_d1); 
      peso_temp = 0;   
      result_bal = 0;
      estab_comp = false;
     }

    if(f2D2 != 0){  
      while(peso_temp < (f2D2 - result_bal)){
         pulsacion = Teclado1.getKey();
         if(ciclo_descarga != true){lcd.setCursor(13,1); lcd.print("MEZCLA");}else{lcd.setCursor(13,1); lcd.print("DESCAR");}
         lcd.setCursor(8,3);lcd.print(balanza);lcd.print("   ");
         if(pulsacion == '#') break;
         peso_temp = balanza - peso_d1;
         peso_d2 = peso_temp;
         if(peso_d2 > (f2D2 / 2) && estab_comp != true){digitalWrite(pin_d2, HIGH);estabilizacion(); estab_comp = true;}
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
      proc_activo = false;
      proc_comp = true;
    }
   }else if((pulsacion == '*' || act_in3 != true) && balanza > 5){
      lcd.setCursor(0,3);lcd.print("err_bal");
      delay(1000);
    }    
  }

void menu_3_2(){
//  pos_col = 11;
//  pos_fil = 0;
//  pos_col1 = 14;
//  pos_fil1 = 2; 
  lcd.setCursor(0,0); lcd.print("Form.3   t:");
  lcd.setCursor(13,3); lcd.print("Salir>#");
  lcd.setCursor(0,3);lcd.print("Bal.Kg:");lcd.print(balanza);lcd.print("  ");
  lcd.setCursor(0,1); lcd.print("D1(");
  lcd.setCursor(3,1); lcd.print(f3D1);
  lcd.setCursor(6,1); lcd.print(")");
  lcd.setCursor(0,2); lcd.print("D2(");
  lcd.setCursor(3,2); lcd.print(f3D2);
  lcd.setCursor(6,2); lcd.print(")");
  if(ciclo_descarga != true){lcd.setCursor(13,1); lcd.print("MEZCLA");}else{lcd.setCursor(13,1); lcd.print("DESCAR");}
  if(proc_comp == true){lcd.setCursor(11,0); lcd.print("FINALIZ.");}
//  if(proc_comp == false){
//    lcd.setCursor(0,3);lcd.print("Bal.Kg:");lcd.print(balanza);lcd.print("  ");
//    lcd.setCursor(14,3); lcd.print("Inic->");
//  }else if(proc_comp == true){
//    lcd.setCursor(0,3);lcd.print("Bal.Kg:");lcd.print(balanza);lcd.print("  ");
//    lcd.setCursor(14,3);lcd.print("Otra->");
//  }   
}
/////////////////////Accion 3 //////////////////////////////
void accion_3_2(){ 
   if(pulsacion == '#') {contador = 2;proc_comp = false;lcd.clear();pulsacion = ' ';}
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

     if(f3D1 != 0){   
       while(peso_temp < (f3D1 - result_bal)) {      
         pulsacion = Teclado1.getKey();
         if(ciclo_descarga != true){lcd.setCursor(13,1); lcd.print("MEZCLA");}else{lcd.setCursor(13,1); lcd.print("DESCAR");}
         lcd.setCursor(8,3);lcd.print(balanza);lcd.print("   ");
         if(pulsacion == '#') break;
         peso_temp = balanza;
         peso_d1 = peso_temp;
         if(peso_d1 > (f3D1 / 2) && estab_comp != true){digitalWrite(pin_d1, HIGH);estabilizacion(); estab_comp = true;}
         digitalWrite(pin_d1, LOW); act_d1 = true;
         tiempo += 1;
         reloj(11, 0);
         reloj_1_print(14, 2);
         lcd.setCursor(7,1);lcd.print(peso_d1);lcd.print(" ");
         delay(100);            
         }
      digitalWrite(pin_d1, HIGH); act_d1 = false;            
      lcd.setCursor(11,0); lcd.print("ESTABIL.");delay(t_estabilizacion * 1000);
     
      peso_d1 = balanza;
      lcd.setCursor(7,1);lcd.print(peso_d1); 
      peso_temp = 0;   
      result_bal = 0;
      estab_comp = false;
     }

    if(f3D2 != 0){  
      while(peso_temp < (f3D2 - result_bal)){
         pulsacion = Teclado1.getKey();
         if(ciclo_descarga != true){lcd.setCursor(13,1); lcd.print("MEZCLA");}else{lcd.setCursor(13,1); lcd.print("DESCAR");}
         lcd.setCursor(8,3);lcd.print(balanza);lcd.print("   ");
         if(pulsacion == '#') break;
         peso_temp = balanza - peso_d1;
         peso_d2 = peso_temp;
         if(peso_d2 > (f3D2 / 2) && estab_comp != true){digitalWrite(pin_d2, HIGH);estabilizacion(); estab_comp = true;}
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
  contador = 2;
  pulsacion = ' ';  
  }
