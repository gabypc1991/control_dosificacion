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

void setup() { 
 eeprom_get_inicio();
 
 factor_temp = factor;
 factor_delay_temp = t_delay_factor;

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
 Timer1.initialize(100000);
 Timer1.attachInterrupt(proceso);
 lcd.init();
 lcd.backlight(); 
  
 Teclado1.addEventListener(keypadEvent);
 intro_0();

} 

void loop() {
 pulsacion = Teclado1.getKey();
 
 if(act_in3 != true && (contador != 3 || contador != 21 || contador != 22)){contador = 2;}

 if(contador == 25){ menu_11_2();accion_11_2();}
 if(contador == 24){ menu_11_1();accion_11_1();}
 if(contador == 23){ menu_11();accion_11();}
// if(contador == 22){ menu_3_2();accion_3_2();}
// if(contador == 21){ menu_3_1();accion_3_1();}
 if(contador == 20){ menu_pesoTolva();accion_pesoTolva();}
 if(contador == 19){ menu_9();accion_9();}
 if(contador == 18){ calibrar_balanza();accion_calibrar();} 
 if(contador == 17){ menu_8();accion_8();}
 if(contador == 16){ menu_formPag1();accion_formPag1();}
 if(contador == 15){ menu_tMezcla();accion_tMezcla();}
 if(contador == 14){ menu_6();accion_6();} 
 if(contador == 13){ menu_edicionTDescarga();accion_edicionTDescarga();}
 if(contador == 12){ menu_edicionFactorPeso();accion_edicionFactorPeso();}
 if(contador == 11){ menu_5_2();accion_5_2();}
 if(contador == 10){ menu_5_1();accion_5_1();}
 if(contador == 9){ menu_5();accion_5();}
 if(contador == 8){ menu_edicionTEstabiliz();accion_edicionTEstabiliz();}
 if(contador == 7){ menu_parametros();accion_parametros();}
 if(contador == 6){ menu_4_2();accion_4_2();}
 if(contador == 5){ menu_4_1();accion_4_1();}
 if(contador == 4){ menu_4();accion_4();}
 if(contador == 3){ menu_formula();accion_formula();}
 if(contador == 2){ menu_inicialPag2();accion_inicialPag2();}
 if(contador == 1){ menu_inicial();accion_inicial();} 
}
