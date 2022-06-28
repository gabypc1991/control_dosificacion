#define MENU_BALANZA 1

int dosis_1[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int dosis_2[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

const int pin_d1 = 36;
const int pin_d2 = 34;
const int pin_d3 = 32;
const int pin_d4 = 30;
const int pin_d5 = 28;
const int in_1 = 26;
const int in_2 = 24;
const int in_3 = 22;
const int in_4 = 4;

String pass_temp = "";
bool user = false;
bool ciclo_mezcla = false;
bool ciclo_descarga = false;

float factor;
float factor_temp;
int balanza = 0;
int balanza_bruto = 0;
int kg_recip;
int result_bal;
int tara = 0;
bool estab_comp = false;
long t_mezcla;
long t_descarga;

int f1D1 = 0;
int f1D2 = 0;
int f2D1 = 0;
int f2D2 = 0;
int f3D1 = 0;
int f3D2 = 0;
int f4D1 = 0;
int f4D2 = 0;
int t_estabilizacion;
//int t_delay_kilos = 3000;
int t_delay_factor;
int factor_delay_temp; 

long latter_time;
long difference;

bool endtext = false;
bool edit = false;
bool proc_activo = false;
bool proc_comp = false;
bool boton_in1 = false;
bool boton_in2 = false;
bool boton_in3 = false;
bool boton_in4 = false;
bool mezcla = false;
char last_key_pressed = ' ';
byte num_times_pressed = 0;
String text;
char last_character = ' ';
char pulsacion;       // almacena la tecla pulsada
//int pos_col = 0;
//int pos_fil = 0;
//int pos_col1 = 0;
//int pos_fil1 = 0;
String myString = "";

int tiempo = 0;
int now = 0;
int minutes = 0;
int hour = 0;
int segundo = 0;

unsigned long tiempo_m = 0;
unsigned long tiempo_d = 0;
int now_1 = 0;
int minutes_1 = 0;
int hour_1 = 0;
int segundo_1 = 0;

bool act_d1 = false;
bool act_d2 = false;
bool act_d3 = false;
bool act_d4 = false;
bool act_d5 = false;
bool act_in1 = true;
bool act_in2 = true;
bool act_in3 = true;
bool act_in4 = true;
bool last_in1 = false;
bool last_in2 = false;
bool last_in3 = false;
bool last_in4 = false;
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
