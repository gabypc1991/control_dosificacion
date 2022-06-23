void proceso(){  
  //int temp_bal = analogRead(A8);
  //balanza_bruto = map(temp_bal, 0, 1023, 0, 999);
  //balanza = (balanza_bruto - tara);  
  balanza = balanza_hx.get_units();
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
      if(tiempo_m < t_mezcla){     
        digitalWrite(pin_d4, LOW);
        tiempo_m += 1;
        reloj_1();        
      }else{
       digitalWrite(pin_d4, HIGH);
       boton_in4 = false;
       tiempo_m = 0;
       now_1 = 0;
       hour_1=0;
       minutes_1=0;
       segundo_1=0;
    }
   }else{
    digitalWrite(pin_d4, HIGH);
    }   
  }
