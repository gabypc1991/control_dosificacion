void proceso(){  
  //int temp_bal = analogRead(A8);
  //balanza_bruto = map(temp_bal, 0, 1023, 0, 999);
  //balanza = (balanza_bruto - tara);  
  balanza = balanza_hx.get_units(5);
  balanza = balanza - kg_recip;
  act_in1 = digitalRead(in_1);
  act_in2 = digitalRead(in_2);
  act_in3 = digitalRead(in_3);
  act_in4 = digitalRead(in_4);
  
  botonera();
  mezclador();
  }

void botonera(){
  if(act_in4 != last_in4){if(act_in4 != true && boton_in4 == false){boton_in4 = true;}else if(act_in4 != true && boton_in4 == true){boton_in4 = false;}last_in4 = act_in4;}
  }

void mezclador(){  
 if(boton_in4 == true){ 
  if(ciclo_mezcla == false){tiempo_m = t_mezcla * 1000;}     // t_mezcla
  if(tiempo_m > 0){
   ciclo_mezcla = true;     
   digitalWrite(pin_d4, HIGH);
   tiempo_m -= 100;
   reloj_1(tiempo_m);        
   }else{        
     tiempo_m = 0;
     if(ciclo_descarga != true){tiempo_d = t_descarga * 1000;} //t_descarga
     if(tiempo_d > 0){
      ciclo_descarga = true;     
      digitalWrite(pin_d4, LOW);
      tiempo_d -= 100;
      reloj_1(tiempo_d);        
      }else{
       ciclo_descarga = false;
       ciclo_mezcla = false;
       boton_in4 = false;
       tiempo_m = 0;
       tiempo_d = 0;
       }
     }
      
   }else{
    digitalWrite(pin_d4, HIGH);
    ciclo_descarga = false;
    ciclo_mezcla = false;
    boton_in4 = false;
    tiempo_m = 0;
    tiempo_d = 0;
    }   
  }
