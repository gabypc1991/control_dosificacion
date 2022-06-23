#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <TimerOne.h>
#include <EEPROM.h>
#include <HX711.h>
#include "variables.h"



byte colPins[ROWS] = {46,48,50,52}; //Puntos de conexion del teclado al arduino FILAS
//byte colPins[COLS] = {44,42,40,38}; //Puntos de conexion del teclado al arduino COLUMNAS
//byte rowPins[ROWS] = {46,48,50,52}; //Puntos de conexion del teclado al arduino FILAS
byte rowPins[COLS] = {38,40,42,44}; //Puntos de conexion del teclado al arduino COLUMNAS

HX711 balanza_hx;
Keypad Teclado1 = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //Configura el teclado
LiquidCrystal_I2C lcd(0x27,20,4); // dependiendo del fabricante del I2C el codigo 0x27 cambiar a
                                  // 0x3F , 0x20 , 0x38 , 
                                  
////////////////////////////////// Void Setup() ///////////
void setup() { 
 eeprom_get_inicio();
 
 factor_temp = factor;

 pinMode(pin_d1, OUTPUT);
 pinMode(pin_d2, OUTPUT);
 pinMode(pin_d3, OUTPUT);
 pinMode(pin_d4, OUTPUT);
 pinMode(pin_d5, OUTPUT);
 pinMode(in_1, INPUT_PULLUP);
 pinMode(in_2, INPUT_PULLUP);
 pinMode(in_3, INPUT_PULLUP);
 pinMode(in_4, INPUT_PULLUP);

 last_in1 = false;
 last_in2 = false;
 last_in3 = false;
 last_in4 = false;
 digitalWrite(pin_d1, HIGH);
 digitalWrite(pin_d2, HIGH);
 digitalWrite(pin_d3, HIGH);
 digitalWrite(pin_d4, HIGH);
 digitalWrite(pin_d5, HIGH);
 
 Serial.begin(9600);
 balanza_hx.begin(DOUT, CLK);
 balanza_hx.set_scale(factor);
 //balanza_hx.tare(20); 
 Timer1.initialize(100000);
 Timer1.attachInterrupt(proceso);
 lcd.init();
 lcd.backlight(); 
  
 Teclado1.addEventListener(keypadEvent);
 intro_0();             // muestra el intro de  bienvenida

} 
////////////////////////// Void loop() ///////////////////////
void loop() {
  pulsacion = Teclado1.getKey() ;  // Lee la tecla pulsada  
 
 if(act_in3 != true && (contador != 3 || contador != 21 || contador != 22)){contador = 2;}

 if(contador == 25){ menu_11_2();accion_11_2();}
 if(contador == 24){ menu_11_1();accion_11_1();}
 if(contador == 23){ menu_11();accion_11();}
 if(contador == 22){ menu_3_2();accion_3_2();}
 if(contador == 21){ menu_3_1();accion_3_1();}
 if(contador == 20){ menu_10();accion_10();}
 if(contador == 19){ menu_9();accion_9();}
 if(contador == 18){ calibrar_balanza();accion_calibrar();} 
 if(contador == 17){ menu_8();accion_8();}
 if(contador == 16){ menu_1_2();accion_1_2();}
 if(contador == 15){ menu_7();accion_7();}
 if(contador == 14){ menu_6();accion_6();} 
 //if(contador == 13){ menu_5_4();accion_5_4();}
 //if(contador == 12){ menu_5_3();accion_5_3();}
 if(contador == 11){ menu_5_2();accion_5_2();}
 if(contador == 10){ menu_5_1();accion_5_1();}
 if(contador == 9){ menu_5();accion_5();}
 //if(contador == 8){ menu_4_4();accion_4_4();}
 //if(contador == 7){ menu_4_3();accion_4_3();}
 if(contador == 6){ menu_4_2();accion_4_2();}
 if(contador == 5){ menu_4_1();accion_4_1();}
 if(contador == 4){ menu_4();accion_4();}
 if(contador == 3){ menu_3();accion_3();}
 if(contador == 2){ menu_2();accion_2();}
 if(contador == 1){ menu_1();accion_1();} 
}



/////////////////////Menu_5  //////////////////////////////////
void menu_5(){ 
  lcd.setCursor(0,0); lcd.print("Formula 2           ");
  lcd.setCursor(0,1); lcd.print("A>D1:");lcd.print(f2D1);
  lcd.setCursor(0,2); lcd.print("B>D2:");lcd.print(f2D2);
  lcd.setCursor(0,3); lcd.print("Volver >#  Prox. <*>");
}
/////////////////////Accion 5 //////////////////////////////
void accion_5(){ 
    if(pulsacion == '#') {contador = 1;lcd.clear();}
    if(pulsacion == '*') {contador = 23;lcd.clear();}
    if(pulsacion == 'A') {contador = 10;lcd.clear();}
    if(pulsacion == 'B') {contador = 11;lcd.clear();}
}
/////////////////////////Sub_Menu_5_1  //////////////////////////////////
    void menu_5_1(){ 
      pos_col = 11;
      pos_fil = 2;
      lcd.setCursor(0,0); lcd.print("      Formula 2     ");
      lcd.setCursor(0,1); lcd.print("       DOSIS 1      ");
      lcd.setCursor(0,2); lcd.print("VALOR (Kg):");
      lcd.setCursor(11,2); lcd.print(f2D1);
      while(edit != true){
        lcd.setCursor(0,3); lcd.print("           Enter <#>");
        readVal();
        edit = true;
        f2D1 = myString.toInt();
        EEPROM.put(16, f2D1);        
        lcd.setCursor(11,2); lcd.print(f2D1);
        lcd.setCursor(0,3); lcd.print("CORRECTO");
        delay(800);               
        }
        contador = 9;
        edit = false; 
        lcd.clear();
    }
/////////////////////////Accion_5_1 //////////////////////////////
    void accion_5_1(){ 
        //if(pulsacion == '*') {contador = 11;lcd.clear();}
        
    }
/////////////////////////Menu_5_2  //////////////////////////////////
    void menu_5_2(){ 
      pos_col = 11;
      pos_fil = 2;
      lcd.setCursor(0,0); lcd.print("      Formula 2     ");
      lcd.setCursor(0,1); lcd.print("       DOSIS 2      ");
      lcd.setCursor(0,2); lcd.print("VALOR (Kg):");
      lcd.setCursor(11,2); lcd.print(f2D2);
      while(edit != true){
        lcd.setCursor(0,3); lcd.print("           Enter <#>");
        readVal();
        edit = true;
        f2D2 = myString.toInt();
        EEPROM.put(20, f2D2);        
        lcd.setCursor(11,2); lcd.print(f2D2);
        lcd.setCursor(0,3); lcd.print("CORRECTO");
        delay(800);               
        }
        contador = 9;
        edit = false; 
        lcd.clear();
    }
/////////////////////////Accion_5_2 //////////////////////////////
    void accion_5_2(){ 
        //if(pulsacion == '*') {contador = 12;lcd.clear();}
    }

/////////////////////Menu_11  //////////////////////////////////
void menu_11(){ 
  lcd.setCursor(0,0); lcd.print("Formula 3           ");
  lcd.setCursor(0,1); lcd.print("A>D1:");lcd.print(f3D1);
  lcd.setCursor(0,2); lcd.print("B>D2:");lcd.print(f3D2);
  lcd.setCursor(0,3); lcd.print("Volver >#           ");
}
/////////////////////Accion 11 //////////////////////////////
void accion_11(){ 
    if(pulsacion == '#') {contador = 1;lcd.clear();}
    if(pulsacion == 'A') {contador = 24;lcd.clear();}
    if(pulsacion == 'B') {contador = 25;lcd.clear();}
}

/////////////////////////Sub_Menu_11_1  //////////////////////////////////
    void menu_11_1(){ 
      pos_col = 11;
      pos_fil = 2;
      lcd.setCursor(0,0); lcd.print("      Formula 3     ");
      lcd.setCursor(0,1); lcd.print("       DOSIS 1      ");
      lcd.setCursor(0,2); lcd.print("VALOR (Kg):");
      lcd.setCursor(11,2); lcd.print(f3D1);
      while(edit != true){
        lcd.setCursor(0,3); lcd.print("           Enter <#>");
        readVal();
        edit = true;
        f3D1 = myString.toInt();
        EEPROM.put(24, f3D1);        
        lcd.setCursor(11,2); lcd.print(f3D1);
        lcd.setCursor(0,3); lcd.print("CORRECTO");
        delay(800);               
        }
        contador = 23;
        edit = false; 
        lcd.clear();
    }
/////////////////////////Accion_5_1 //////////////////////////////
    void accion_11_1(){ 
        //if(pulsacion == '*') {contador = 11;lcd.clear();}
        
    }

/////////////////////////Sub_Menu_11_2  //////////////////////////////////
    void menu_11_2(){ 
      pos_col = 11;
      pos_fil = 2;
      lcd.setCursor(0,0); lcd.print("      Formula 3     ");
      lcd.setCursor(0,1); lcd.print("       DOSIS 2      ");
      lcd.setCursor(0,2); lcd.print("VALOR (Kg):");
      lcd.setCursor(11,2); lcd.print(f3D2);
      while(edit != true){
        lcd.setCursor(0,3); lcd.print("           Enter <#>");
        readVal();
        edit = true;
        f3D2 = myString.toInt();
        EEPROM.put(28, f3D2);        
        lcd.setCursor(11,2); lcd.print(f3D2);
        lcd.setCursor(0,3); lcd.print("CORRECTO");
        delay(800);               
        }
        contador = 23;
        edit = false; 
        lcd.clear();
    }
/////////////////////////Accion_5_1 //////////////////////////////
    void accion_11_2(){ 
        //if(pulsacion == '*') {contador = 11;lcd.clear();}
        
    }

/////////////////////////  Menu_6  //////////////////////////////////
    void menu_6(){ 
      lcd.setCursor(0,0); lcd.print("       BALANZA      ");
      lcd.setCursor(0,1); lcd.print("      TARA  <*>     ");
      lcd.setCursor(0,2); lcd.print("VALOR (Kg):");
      lcd.setCursor(11,2); lcd.print(balanza);lcd.print("   ");
      lcd.setCursor(0,3); lcd.print("          Volver <#>");            
    }
/////////////////////////Accion_6 //////////////////////////////
    void accion_6(){                 
        if(pulsacion == '#') {contador = 1;lcd.clear();}
        if(pulsacion == '*') {balanza_hx.tare(20);}                
    }

    void menu_7(){      
      pos_col = 12;
      pos_fil = 2;
      lcd.setCursor(0,0); lcd.print("  TIEMPO DE MEZCLA   ");
      lcd.setCursor(0,1); lcd.print("                     ");
      lcd.setCursor(11,1); lcd.print("("); lcd.print(t_mezcla / 600); lcd.print(")");
      lcd.setCursor(0,2); lcd.print("Set Minutos:");

      while(edit != true){
        lcd.setCursor(0,3); lcd.print("           Enter <#>");
        readVal();
        edit = true;
        t_mezcla = myString.toInt();
        t_mezcla = t_mezcla * 600;
        EEPROM.put(12, t_mezcla);   
        lcd.setCursor(11,1); lcd.print("("); lcd.print(t_mezcla / 600); lcd.print(")");
        lcd.setCursor(0,3); lcd.print("CORRECTO");
        delay(800);
          
        }
        edit = false;
        pulsacion = '0';
        contador = 1;
        lcd.clear();
          
    }
/////////////////////////Accion_4_1 //////////////////////////////
    void accion_7(){         
       // if(pulsacion == '#') {contador = 4;lcd.clear();}
                
    }

 void menu_8(){     
      lcd.setCursor(0,0); lcd.print("D1|D2|D3|D4|>SALIDA ");      
      lcd.setCursor(0,2); lcd.print("I1|I2|I3|I4|<ENTRADA");
      lcd.setCursor(12,3); lcd.print("Volv.<#>");
          
    }
/////////////////////////Accion_4_1 //////////////////////////////
    void accion_8(){
                
       if(pulsacion == '#') {user = false;pass_temp = "";contador = 1;lcd.clear();}
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
                
    }
/////////////////////////Menu_9 //////////////////////////////////
void menu_9(){ 
   String pass = "1234";
   if(user != true){
    pos_col = 4;
    pos_fil = 1;
    lcd.setCursor(0,0); lcd.print("PASSWORD");
    lcd.setCursor(0,1); lcd.print("-->");
    lcd.setCursor(0,3); lcd.print("Enter <#>");
    readVal();
    pass_temp = myString;
    user = true;
    }
   
   if(pass_temp == pass && user == true){
    lcd.setCursor(0,0); lcd.print("CALIBRAR BALANZA  >A");
    lcd.setCursor(0,1); lcd.print("ESTADO IO         >B");
    lcd.setCursor(0,2); lcd.print("                    ");
    lcd.setCursor(0,3); lcd.print("Volver <#>");
    }else{
    lcd.setCursor(0,2); lcd.print("error");
    delay(800);
    user = false;
    pass_temp = "";
    contador = 1;  
    }
   
   
}
/////////////////////Accion 9 //////////////////////////////
void accion_9(){ 
  if(pulsacion == 'A') {contador = 18;lcd.clear();}
  if(pulsacion == 'B') {contador = 17;lcd.clear();}
  if(pulsacion == '#') {user = false;pass_temp = "";contador = 1;lcd.clear();}
}

/////////////////////////Menu_10 //////////////////////////////////
    void menu_10(){
      pos_col1 = 8;
      pos_fil1 = 2; 
      lcd.setCursor(0,0); lcd.print("      MEZCLADOR     ");
      lcd.setCursor(0,1); lcd.print("  TIEMPO DE PROCESO ");
      lcd.setCursor(0,3); lcd.print("Volver<#>   Reini<*>");
    }
/////////////////////////Accion_10 //////////////////////////////
    void accion_10(){
        reloj_1_print(); 
        if(pulsacion == '#') {contador = 1;lcd.clear();}
        if(pulsacion == '*') {
          tiempo_m = 0;
          now_1 = 0;
          hour_1=0;
          minutes_1=0;
          segundo_1=0;
      }
    }
