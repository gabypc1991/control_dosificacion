#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <TimerOne.h>
#include <EEPROM.h>
#include <HX711.h>

const int pin_d1 = 36;
const int pin_d2 = 34;
const int pin_d3 = 32;
const int pin_d4 = 30;
const int pin_mezcla = 28;
const int in_1 = 26;
const int in_2 = 24;
const int in_3 = 22;
const int in_4 = 4;

float peso = 0;
int balanza = 0;
int balanza_bruto = 0;
int result_bal;
int tara = 0;
bool estab_comp = false;
int t_mezcla = 150;

int f1D1 = 0;
int f1D2 = 0;
int f1D3 = 0;
int f1D4 = 0;
int f2D1 = 0;
int f2D2 = 0;
int f2D3 = 0;
int f2D4 = 0;
int f3D1 = 0;
int f3D2 = 0;
int f3D3 = 0;
int f3D4 = 0;
int f4D1 = 0;
int f4D2 = 0;
int f4D3 = 0;
int f4D4 = 0;

long latter_time;
long difference;
bool endtext = false;
bool edit = false;
bool proc_activo = false;
bool proc_comp = false;
char last_key_pressed = ' ';
byte num_times_pressed = 0;
String text;
char last_character = ' ';
char pulsacion;       // almacena la tecla pulsada
int pos_col = 0;
int pos_fil = 0;
String myString = "";

int tiempo = 0;
int now = 0;
int minutes = 0;
int hour = 0;
int segundo = 0;
bool act_d1 = false;
bool act_d2 = false;
bool act_d3 = false;
bool act_d4 = false;
bool act_in1 = false;
bool act_in2 = false;
bool act_in3 = false;
bool act_in4 = false;
bool buttonState = false;
bool lastButtonState;
bool salida;  

const int DOUT=A1;
const int CLK=A0;

int  contador = 1;    // cuenta el nivel del menu en el que se esta
const byte ROWS = 4;  //Cuatro Filas
const byte COLS = 4;  //Cuatro Columnas 
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

char letters[14] [4] = {
{'0', '0', '0', '0'},
{'a', 'b', 'c', '1'},
{'d', 'e', 'f', '2'},
{'g', 'h', 'i', '3'},
{'j', 'k', 'l', '4'},
{'m', 'n', 'o', '5'},
{'p', 'q', 'r', '6'},
{'s', 't', 'u', '7'},
{'v', 'w', 'x', '8'},
{'y', 'z', '9', '9'},
{',', '.', '-', ':'},
{'<', '?', '>', '!'},
{'@', '+', '=', '#'},
{'(', ')', '*', '/'}
};

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
 Serial.begin(9600);
 balanza_hx.begin(DOUT, CLK);
 balanza_hx.set_scale(439430.25);
 balanza_hx.tare(20); 
 Timer1.initialize(100000);
 Timer1.attachInterrupt(proceso);
 lcd.init();
 lcd.backlight();
 
 f1D1 = EEPROM.read(0);
 f1D2 = EEPROM.read(1);
 f1D3 = EEPROM.read(2);
 f1D4 = EEPROM.read(3);

 pinMode(pin_d1, OUTPUT);
 pinMode(pin_d2, OUTPUT);
 pinMode(pin_d3, OUTPUT);
 pinMode(pin_d4, OUTPUT);
 pinMode(pin_mezcla, OUTPUT);
 pinMode(in_1, INPUT_PULLUP);
 pinMode(in_2, INPUT_PULLUP);
 pinMode(in_3, INPUT_PULLUP);
 pinMode(in_4, INPUT_PULLUP);

 digitalWrite(pin_d1, LOW);
 digitalWrite(pin_d2, LOW);
 digitalWrite(pin_d3, LOW);
 digitalWrite(pin_d4, LOW);
 digitalWrite(pin_mezcla, LOW);
 
 Teclado1.addEventListener(keypadEvent);
 intro_0();             // muestra el intro de  bienvenida

} 
////////////////////////// Void loop() ///////////////////////
void loop() {
  pulsacion = Teclado1.getKey() ;  // Lee la tecla pulsada
 if (pulsacion != 0) {      
    lcd.clear();
    delay(100);
 } 
 if(contador == 17){ menu_8();accion_8();}
 if(contador == 16){ menu_1_2();accion_1_2();}
 if(contador == 15){ menu_7();accion_7();}
 if(contador == 14){ menu_6();accion_6();} 
 if(contador == 13){ menu_5_4();accion_5_4();}
 if(contador == 12){ menu_5_3();accion_5_3();}
 if(contador == 11){ menu_5_2();accion_5_2();}
 if(contador == 10){ menu_5_1();accion_5_1();}
 if(contador == 9){ menu_5();accion_5();}
 if(contador == 8){ menu_4_4();accion_4_4();}
 if(contador == 7){ menu_4_3();accion_4_3();}
 if(contador == 6){ menu_4_2();accion_4_2();}
 if(contador == 5){ menu_4_1();accion_4_1();}
 if(contador == 4){ menu_4();accion_4();}
 if(contador == 3){ menu_3();accion_3();}
 if(contador == 2){ menu_2();accion_2();}
 if(contador == 1){ menu_1();accion_1();}
 
}  ///////// Fin del void loop(), inician las Funciones///////////////

void intro_0(){ 
 lcd.clear();  // Borra el  LCD
 lcd.setCursor(0, 0); lcd.print("--------------v1.0pR");
 lcd.setCursor(0, 1); lcd.print("    CONTROLADOR     ");
 lcd.setCursor(0, 2); lcd.print("     DOSIFICACION   ");
 lcd.setCursor(0, 3); lcd.print("--------------------");
 delay(4000);                // espera 4 segundos mostrando el intro
 lcd.clear();
}
/////////////////////Menu_1  //////////////////////////////////
void menu_1(){ 
   lcd.setCursor(0,0); lcd.print("SELEC. FORMULA    >1");
   lcd.setCursor(0,1); lcd.print("EDIT. FORMULAS    >2");
   lcd.setCursor(0,2); lcd.print("BALANZA           >3");
   lcd.setCursor(0,3); lcd.print("Mas... <*>");
}
/////////////////////Accion 1 //////////////////////////////
void accion_1(){ 
  if(pulsacion == '1') {contador = 2;lcd.clear();}
  if(pulsacion == '2') {contador = 4;lcd.clear();}
  if(pulsacion == '3') {contador = 14;lcd.clear();}
  if(pulsacion == '*') {contador = 16;lcd.clear();}
}

void menu_1_2(){ 
   lcd.setCursor(0,0); lcd.print("MEZCLADO          >1");
   lcd.setCursor(0,1); lcd.print("PARAMETROS        >2");
   lcd.setCursor(0,2); lcd.print("ESTADO IO         >3");
   lcd.setCursor(0,3); lcd.print("Volver <#>");
}
/////////////////////Accion 1 //////////////////////////////
void accion_1_2(){ 
  if(pulsacion == '1') {contador = 15;lcd.clear();}
  if(pulsacion == '2') {contador = 1;lcd.clear();}
  if(pulsacion == '3') {contador = 17;lcd.clear();}
  if(pulsacion == '#') {contador = 1;lcd.clear();}
}

/////////////////////Menu_2  //////////////////////////////////
void menu_2(){ 
   lcd.setCursor(0,0); lcd.print("FORM1 <1>  FORM4 <4>");
   lcd.setCursor(0,1); lcd.print("FORM2 <2>  FORM5 <5>");
   lcd.setCursor(0,2); lcd.print("FORM3 <3>  FORM6 <6>");
   lcd.setCursor(0,3); lcd.print("Volver <#>  Mas..<*>");
}
/////////////////////Accion 2 //////////////////////////////
void accion_2(){ 
    if(pulsacion == '#') {contador = 1;lcd.clear();}
    if(pulsacion == '1') {contador = 3;lcd.clear();}
}

/////////////////////Menu_3  //////////////////////////////////
void menu_3(){
  pos_col = 11;
  pos_fil = 0; 
  lcd.setCursor(0,0); lcd.print("Form.1   t:");
  lcd.setCursor(0,1); lcd.print("D1(");
  lcd.setCursor(3,1); lcd.print(f1D1);
  lcd.setCursor(6,1); lcd.print(")");
  lcd.setCursor(10,1); lcd.print("D2(");
  lcd.setCursor(13,1); lcd.print(f1D2);
  lcd.setCursor(16,1); lcd.print(")");
  lcd.setCursor(0,2); lcd.print("D3(");
  lcd.setCursor(3,2); lcd.print(f1D3);
  lcd.setCursor(6,2); lcd.print(")");
  lcd.setCursor(10,2); lcd.print("D4(");
  lcd.setCursor(13,2); lcd.print(f1D4);
  lcd.setCursor(16,2); lcd.print(")");
  if(proc_comp == false){
    lcd.setCursor(0,3); lcd.print("           Inic. <*>");
  }else if(proc_comp == true){
    lcd.setCursor(0,3); lcd.print("           Volver<#>");
  }  
}
/////////////////////Accion 3 //////////////////////////////
void accion_3(){ 
   if(pulsacion == '#') {contador = 1;proc_comp = false;lcd.clear();}
   
   if(pulsacion == '*' && balanza < 5) {
    
   proc_activo = true;
   
   while(proc_activo != false){
       int peso_temp;
       int peso_d1;
       int peso_d2;
       int peso_d3;
       int peso_d4;
       lcd.setCursor(0,3);lcd.print("                    ");
       lcd.setCursor(0,3);lcd.print("Bal.Kg:");
        
       while(peso_temp < (f1D1 - result_bal) && f1D1 != 0) {      
         pulsacion = Teclado1.getKey();
         lcd.setCursor(8,3);lcd.print(balanza);lcd.print("   ");
         if(pulsacion == '#') break;
         peso_temp = balanza;
         peso_d1 = peso_temp;
         if(peso_d1 > (f1D1 / 2) && estab_comp != true){digitalWrite(pin_d1, LOW);estabilizacion(); estab_comp = true;}
         digitalWrite(pin_d1, HIGH); act_d1 = true;
         tiempo += 1;
         reloj();
         lcd.setCursor(7,1);lcd.print(peso_d1);
         delay(100);            
         }
      digitalWrite(pin_d1, LOW); act_d1 = false;            
      lcd.setCursor(11,0); lcd.print(" BAL_EST ");delay(5000);
      peso_d1 = balanza;
      lcd.setCursor(7,1);lcd.print(peso_d1); 
      peso_temp = 0;   
      result_bal = 0;
      estab_comp = false;
      
      while(peso_temp < (f1D2 - result_bal) && f1D2 != 0){
         pulsacion = Teclado1.getKey();
         lcd.setCursor(8,3);lcd.print(balanza);lcd.print("   ");
         if(pulsacion == '#') break;
         peso_temp = balanza - peso_d1;
         peso_d2 = peso_temp;
         if(peso_d2 > (f1D2 / 2) && estab_comp != true){digitalWrite(pin_d2, LOW);estabilizacion(); estab_comp = true;}
         digitalWrite(pin_d2, HIGH); act_d2 = true;
         tiempo += 1;
         reloj();
         lcd.setCursor(17,1);lcd.print(peso_d2);
         delay(100);            
         }
      digitalWrite(pin_d2, LOW); act_d2 = false;
      lcd.setCursor(11,0); lcd.print(" BAL_EST ");delay(5000);
      peso_d2 = balanza - peso_d1;
      lcd.setCursor(17,1);lcd.print(peso_d2);
      peso_temp = 0;   
      result_bal = 0;
      estab_comp = false;
      
      while(peso_temp < (f1D3 - result_bal) && f1D3 != 0){
         pulsacion = Teclado1.getKey();
         lcd.setCursor(8,3);lcd.print(balanza);lcd.print("   ");
         if(pulsacion == '#') break;
         peso_temp = balanza - (peso_d1 + peso_d2);
         peso_d3 = peso_temp;
         if(peso_d3 > (f1D3 / 2) && estab_comp != true){digitalWrite(pin_d3, LOW);estabilizacion(); estab_comp = true;}
         digitalWrite(pin_d3, HIGH); act_d3 = true;
         tiempo += 1;
         reloj();
         lcd.setCursor(7,2);lcd.print(peso_d3);
         delay(100);            
         }
      digitalWrite(pin_d3, LOW); act_d3 = false;
      lcd.setCursor(11,0); lcd.print(" BAL_EST ");delay(5000);
      peso_d3 = balanza - (peso_d1 + peso_d2);
      lcd.setCursor(7,2);lcd.print(peso_d3);
      peso_temp = 0;   
      result_bal = 0;
      estab_comp = false;
      
      while(peso_temp < (f1D4 - result_bal) && f1D4 != 0){
         pulsacion = Teclado1.getKey();
         lcd.setCursor(8,3);lcd.print(balanza);lcd.print("   ");
         if(pulsacion == '#') break;
         peso_temp = balanza - (peso_d1 + peso_d2 + peso_d3);
         peso_d4 = peso_temp;
         if(peso_d4 > (f1D4 / 2) && estab_comp != true){digitalWrite(pin_d4, LOW);estabilizacion(); estab_comp = true;}
         digitalWrite(pin_d4, HIGH); act_d4 = true;
         tiempo += 1;
         reloj();
         lcd.setCursor(17,2);lcd.print(peso_d4);
         delay(100);            
         }
      digitalWrite(pin_d4, LOW); act_d4 = false;
      lcd.setCursor(11,0); lcd.print(" BAL_EST ");delay(5000);
      peso_d4 = balanza - (peso_d1 + peso_d2 + peso_d3);
      lcd.setCursor(17,2);lcd.print(peso_d4);
      peso_temp = 0;   
      result_bal = 0;
      estab_comp = false;
      tiempo = 0;
      now = 0;
      hour=0;
      minutes=0;
      segundo=0;             
      proc_activo = false;
      proc_comp = true;
    }
   }else if(pulsacion == '*' && balanza > 5){
      lcd.setCursor(0,3);lcd.print("err_bal");
      delay(1000);
    }    
  }

/////////////////////Menu_4  //////////////////////////////////
void menu_4(){ 
  lcd.setCursor(0,0); lcd.print("Formula 1           ");
  lcd.setCursor(0,1); lcd.print("A>D1:");lcd.print(f1D1);
  lcd.setCursor(10,1); lcd.print("B>D2:");lcd.print(f1D2);
  lcd.setCursor(0,2); lcd.print("C>D3:");lcd.print(f1D3);
  lcd.setCursor(10,2); lcd.print("D>D4:");lcd.print(f1D4);
  lcd.setCursor(0,3); lcd.print("Volver >#  Prox. <*>");
}
/////////////////////Accion 4 //////////////////////////////
void accion_4(){ 
    if(pulsacion == '#') {contador = 1;lcd.clear();}
    if(pulsacion == '*') {contador = 9;lcd.clear();}
    if(pulsacion == 'A') {contador = 5;lcd.clear();}
    if(pulsacion == 'B') {contador = 6;lcd.clear();}
    if(pulsacion == 'C') {contador = 7;lcd.clear();}
    if(pulsacion == 'D') {contador = 8;lcd.clear();}
}
/////////////////////////Sub_Menu_4_1  //////////////////////////////////
    void menu_4_1(){     
      pos_col = 11;
      pos_fil = 2;
      lcd.setCursor(0,0); lcd.print("      Formula 1     ");
      lcd.setCursor(0,1); lcd.print("       DOSIS 1      ");
      lcd.setCursor(0,2); lcd.print("VALOR (Kg):");
      lcd.setCursor(11,2); lcd.print(f1D1);
      while(edit != true){
        lcd.setCursor(0,3); lcd.print("           Enter <#>");
        readVal();
        edit = true;
        f1D1 = myString.toInt();
        EEPROM.write(0, f1D1);        
        lcd.setCursor(11,2); lcd.print(f1D1);
        lcd.setCursor(0,3); lcd.print("CORRECTO");
        delay(800);               
        }
        contador = 4;
        edit = false; 
        lcd.clear();   
        //lcd.setCursor(0,3); lcd.print("            D2-> <*>");      
    }
/////////////////////////Accion_4_1 //////////////////////////////
    void accion_4_1(){         
        //if(pulsacion == '#') {contador = 4;edit = false;lcd.clear();}
                
    }
/////////////////////////Menu_4_2  //////////////////////////////////
    void menu_4_2(){ 
      pos_col = 11;
      pos_fil = 2;
      lcd.setCursor(0,0); lcd.print("      Formula 1     ");
      lcd.setCursor(0,1); lcd.print("       DOSIS 2      ");
      lcd.setCursor(0,2); lcd.print("VALOR (Kg):");
      lcd.setCursor(11,2); lcd.print(f1D2);
      while(edit != true){
        lcd.setCursor(0,3); lcd.print("           Enter <#>");
        readVal();
        edit = true;
        f1D2 = myString.toInt();        
        EEPROM.write(1, f1D2);          
        lcd.setCursor(11,2); lcd.print(f1D2);
        lcd.setCursor(0,3); lcd.print("CORRECTO");
        delay(800);
           
        }
        edit = false;
        contador = 4;
        lcd.clear();  
        //lcd.setCursor(0,3); lcd.print("            D3-> <*>");     
    }
/////////////////////////Accion_4_2 //////////////////////////////
    void accion_4_2(){ 
       // if(pulsacion == '*') {contador = 4;edit = false;lcd.clear();}
    }
/////////////////////////Menu_4_3  //////////////////////////////////
    void menu_4_3(){ 
      pos_col = 11;
      pos_fil = 2;
      lcd.setCursor(0,0); lcd.print("      Formula 1     ");
      lcd.setCursor(0,1); lcd.print("       DOSIS 3      ");
      lcd.setCursor(0,2); lcd.print("VALOR (Kg):");
      lcd.setCursor(11,2); lcd.print(f1D3);
      
      while(edit != true){
        lcd.setCursor(0,3); lcd.print("           Enter <#>");
        readVal();
        edit = true;
        f1D3 = myString.toInt();        
        EEPROM.write(2, f1D3);       
        lcd.setCursor(11,2); lcd.print(f1D3);
        lcd.setCursor(0,3); lcd.print("CORRECTO");
        delay(800);
           
        }
        edit = false;
        contador = 4;
        lcd.clear(); 
        //lcd.setCursor(0,3); lcd.print("            D4-> <*>"); 
    }
/////////////////////////Accion_4_3 //////////////////////////////
    void accion_4_3(){ 
        //if(pulsacion == '#') {contador = 4;edit = false;lcd.clear();}
    }
/////////////////////////Menu_4_4  //////////////////////////////////
    void menu_4_4(){ 
      pos_col = 11;
      pos_fil = 2;
      lcd.setCursor(0,0); lcd.print("      Formula 1     ");
      lcd.setCursor(0,1); lcd.print("       DOSIS 4      ");
      lcd.setCursor(0,2); lcd.print("VALOR (Kg):");
      lcd.setCursor(11,2); lcd.print(f1D4);
      
      while(edit != true){
        lcd.setCursor(0,3); lcd.print("           Enter <#>");
        readVal();
        edit = true;
        f1D4 = myString.toInt();        
        EEPROM.write(3, f1D4);        
        lcd.setCursor(11,2); lcd.print(f1D4);
        lcd.setCursor(0,3); lcd.print("CORRECTO");
        delay(800);
          
        }
        edit = false;
        contador = 4;
        lcd.clear();
        //lcd.setCursor(0,3); lcd.print("          Volver <*>"); 
      
    }
/////////////////////////Accion_4_4 //////////////////////////////
    void accion_4_4(){ 
       // if(pulsacion == '#') {contador = 4;edit = false;lcd.clear();}
    }


/////////////////////Menu_5  //////////////////////////////////
void menu_5(){ 
  lcd.setCursor(0,0); lcd.print("Formula 2           ");
  lcd.setCursor(0,1); lcd.print("A>D1:");lcd.print(f2D1);
  lcd.setCursor(10,1); lcd.print("B>D2:");lcd.print(f2D2);
  lcd.setCursor(0,2); lcd.print("C>D1:");lcd.print(f2D3);
  lcd.setCursor(10,2); lcd.print("D>D2:");lcd.print(f2D4);
  lcd.setCursor(0,3); lcd.print("Volver >#  Prox. <*>");
}
/////////////////////Accion 5 //////////////////////////////
void accion_5(){ 
    if(pulsacion == '#') {contador = 1;lcd.clear();}
    if(pulsacion == 'A') {contador = 10;lcd.clear();}
    if(pulsacion == 'B') {contador = 11;lcd.clear();}
    if(pulsacion == 'C') {contador = 12;lcd.clear();}
    if(pulsacion == 'D') {contador = 13;lcd.clear();}
}
/////////////////////////Sub_Menu_5_1  //////////////////////////////////
    void menu_5_1(){ 
      lcd.setCursor(0,0); lcd.print("      Formula 2     ");
      lcd.setCursor(0,1); lcd.print("       DOSIS 1      ");
      lcd.setCursor(0,2); lcd.print("VALOR (Kg):         ");
      lcd.setCursor(0,3); lcd.print("            D2-> <*>");
    }
/////////////////////////Accion_5_1 //////////////////////////////
    void accion_5_1(){ 
        if(pulsacion == '*') {contador = 11;lcd.clear();}
        
    }
/////////////////////////Menu_5_2  //////////////////////////////////
    void menu_5_2(){ 
      lcd.setCursor(0,0); lcd.print("      Formula 2     ");
      lcd.setCursor(0,1); lcd.print("       DOSIS 2      ");
      lcd.setCursor(0,2); lcd.print("VALOR (Kg):         ");
      lcd.setCursor(0,3); lcd.print("            D3-> <*>");
    }
/////////////////////////Accion_5_2 //////////////////////////////
    void accion_5_2(){ 
        if(pulsacion == '*') {contador = 12;lcd.clear();}
    }
/////////////////////////Menu_5_3  //////////////////////////////////
    void menu_5_3(){ 
      lcd.setCursor(0,0); lcd.print("      Formula 2     ");
      lcd.setCursor(0,1); lcd.print("       DOSIS 3      ");
      lcd.setCursor(0,2); lcd.print("VALOR (Kg):         ");
      lcd.setCursor(0,3); lcd.print("            D4-> <*>");
    }
/////////////////////////Accion_5_3 //////////////////////////////
    void accion_5_3(){ 
        if(pulsacion == '*') {contador = 13;lcd.clear();}
    }
/////////////////////////Menu_5_4  //////////////////////////////////
    void menu_5_4(){ 
      lcd.setCursor(0,0); lcd.print("      Formula 2     ");
      lcd.setCursor(0,1); lcd.print("       DOSIS 4      ");
      lcd.setCursor(0,2); lcd.print("VALOR (Kg):         ");
      lcd.setCursor(0,3); lcd.print("           Enter <*>");
    }
/////////////////////////Accion_5_4 //////////////////////////////
    void accion_5_4(){ 
        if(pulsacion == '*') {contador = 9;lcd.clear();}
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
      pos_col = 11;
      pos_fil = 2;
      lcd.setCursor(0,0); lcd.print("  TIEMPO DE MEZCLA   ");
      lcd.setCursor(0,1); lcd.print("                     ");
      lcd.setCursor(0,2); lcd.print("Minutos:");
      lcd.setCursor(11,2); lcd.print(t_mezcla);

      while(edit != true){
        lcd.setCursor(0,3); lcd.print("           Enter <#>");
        readVal();
        edit = true;
        t_mezcla = myString.toInt();   
        lcd.setCursor(11,2); lcd.print(t_mezcla);
        lcd.setCursor(0,3); lcd.print("CORRECTO");
        delay(800);
          
        }
        edit = false;
        contador = 16;
        lcd.clear();
          
    }
/////////////////////////Accion_4_1 //////////////////////////////
    void accion_7(){         
       // if(pulsacion == '#') {contador = 4;lcd.clear();}
                
    }

 void menu_8(){     
      lcd.setCursor(0,0); lcd.print("D1|D2|D3|D4|>SALIDA ");      
      lcd.setCursor(0,2); lcd.print("I1|I2|I3|I4|<ENTRADA");
      lcd.setCursor(12,3); lcd.print("Volv.<*>");
          
    }
/////////////////////////Accion_4_1 //////////////////////////////
    void accion_8(){
                
       if(pulsacion == '*') {contador = 16;lcd.clear();}
       if(pulsacion == '1' && act_d1 == false) {digitalWrite(pin_d1, HIGH); act_d1 = true;
       }else if(pulsacion == '1' && act_d1 == true){digitalWrite(pin_d1, LOW); act_d1 = false;}
       if(pulsacion == '2' && act_d2 == false) {digitalWrite(pin_d2, HIGH); act_d2 = true;
       }else if(pulsacion == '2' && act_d2 == true){digitalWrite(pin_d2, LOW); act_d2 = false;}
       if(pulsacion == '3' && act_d3 == false) {digitalWrite(pin_d3, HIGH); act_d3 = true;
       }else if(pulsacion == '3' && act_d3 == true){digitalWrite(pin_d3, LOW); act_d3 = false;}
       if(pulsacion == '4' && act_d4 == false) {digitalWrite(pin_d4, HIGH); act_d4 = true;
       }else if(pulsacion == '4' && act_d4 == true){digitalWrite(pin_d4, LOW); act_d4 = false;}

       if(act_d1 == true){lcd.setCursor(0,1); lcd.print("->|");}else{lcd.setCursor(0,1); lcd.print("  |");}
       if(act_d2 == true){lcd.setCursor(3,1); lcd.print("->|");}else{lcd.setCursor(3,1); lcd.print("  |");}
       if(act_d3 == true){lcd.setCursor(6,1); lcd.print("->|");}else{lcd.setCursor(6,1); lcd.print("  |");}
       if(act_d4 == true){lcd.setCursor(9,1); lcd.print("->|");}else{lcd.setCursor(9,1); lcd.print("  |");}

       if(act_in1 == true){lcd.setCursor(0,3); lcd.print("<-|");}else{lcd.setCursor(0,3); lcd.print("  |");}
       if(act_in2 == true){lcd.setCursor(3,3); lcd.print("<-|");}else{lcd.setCursor(3,3); lcd.print("  |");}
       if(act_in3 == true){lcd.setCursor(6,3); lcd.print("<-|");}else{lcd.setCursor(6,3); lcd.print("  |");}
       if(act_in4 == true){lcd.setCursor(9,3); lcd.print("<-|");}else{lcd.setCursor(9,3); lcd.print("  |");}
                
    }

void mezclador(){
      pos_col = 3;
      pos_fil = 2;
      lcd.setCursor(0,0); lcd.print("                    ");     
      lcd.setCursor(0,1); lcd.print("     Mezclando...   ");  
      lcd.setCursor(0,2); lcd.print("                    ");
      lcd.setCursor(0,3); lcd.print("           Parar <O>"); 
      while(tiempo < t_mezcla){
        digitalWrite(pin_mezcla, HIGH);
        tiempo += 1;
        reloj();
        delay(100);
        }
      digitalWrite(pin_mezcla, LOW);
      tiempo = 0;
      now = 0;
      hour=0;
      minutes=0;
      segundo=0;
      contador = 1;   
  }

void status_IO(){  
  buttonState = digitalRead(in_1);
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      salida = true;
    } else {
      salida = false;
    }
  }
}

String readVal(){
  myString = "";
  char keyPressed = Teclado1.getKey();
  while (keyPressed != '#'){
    keyPressed = Teclado1.getKey();
    if ((keyPressed != NO_KEY) && (keyPressed != '#')) {
      myString.concat(keyPressed);
      lcd.setCursor(pos_col,pos_fil);lcd.print(myString);
      
      }   
    }  
  return(myString);  
  }

void proceso(){
  
  //int temp_bal = analogRead(A8);
  //balanza_bruto = map(temp_bal, 0, 1023, 0, 999);
  //balanza = (balanza_bruto - tara);

  balanza = balanza_hx.get_units();
  act_in1 != digitalRead(in_1);
  act_in2 != digitalRead(in_2);
  act_in3 != digitalRead(in_3);
  act_in4 != digitalRead(in_4);
  status_IO();
  }

void estabilizacion(){
  int bal_1;
  int bal_2;
    
  bal_1 = balanza;  
  lcd.setCursor(11,0); lcd.print(" CONTROL ");
  delay(10000);   
  bal_2 = balanza;    
  result_bal = bal_2 - bal_1;
  }

void reloj() {
  if(tiempo > now + 9){//cada segunto
    now = tiempo;    
    segundo++;
  if(segundo>59){
    minutes++;
    segundo=0;
  }
  if(minutes>59){
    hour++;
    minutes=0;
    segundo=0;
  }
  if(hour>=24){
    hour=0;
    minutes=0;
    segundo=0;
  }
  lcd.setCursor(pos_col,pos_fil);
  if(hour<10)lcd.print("0");
  lcd.print(hour);
  lcd.print(":");
  if(minutes<10)lcd.print("0");
  lcd.print(minutes);
  lcd.print(":");
  if(segundo<10)lcd.print("0");
  lcd.print(segundo);
 }
}

void keypadEvent(KeypadEvent key) {
switch (Teclado1.getState()) {
case PRESSED:
if (key == '#') {
Serial.println(text);
text = "";
// key '#' sets the end of the text.
if (last_character != ' ') {
text += last_character;
}
endtext = true;
} else {
if (key == last_key_pressed) {
/* If the same key is pressed several times, with an interval of less than 2 seconds,
* it is considered "looking for the next character".
* If the interval is of more than 2 seconds, it is considered a new character
*/
difference = millis() - latter_time;
latter_time = millis();
if (difference > 2000) {
text += last_character;
byte indice;
/* For keys A, B, C and D, corresponding positions 10 to 14 of the keys array,
* the way of calculating the index is, when converting to integer,
* substracting the ASCII corresponding to '7', that leaves A as 10, B as 11, and so on.
*/
if (key > '9') {
indice = key - '7';
} else {
indice = key - '0';
}
last_character = letters[indice][0];
Serial.print("caracter: ");
Serial.println(last_character);
num_times_pressed = 1;
} else {
byte indice;
if (key > '9') {
indice = key - '7';
} else {
indice = key - '0';
}
last_character = letters[indice][num_times_pressed % 4];
Serial.print("caracter: ");
Serial.println(last_character);
num_times_pressed++;
}
} else {
last_key_pressed = key;
if (last_character != ' ') {
text += last_character;
}
byte indice;
if (key > '9') {
indice = key - '7';
} else {
indice = key - '0';
}
last_character = letters[indice][0];
Serial.print("caracter: ");
Serial.println(last_character);
num_times_pressed = 1;
latter_time = millis();
}
}
break;
}
}
