void menu_editFormula(){ 
  lcd.setCursor(0,0); lcd.print("Formula ");lcd.print(contador_formula + 1);
  lcd.setCursor(0,1); lcd.print("A>D1:");lcd.print(dosis_1[contador_formula]);
  lcd.setCursor(0,2); lcd.print("B>D2:");lcd.print(dosis_2[contador_formula]);
  lcd.setCursor(0,3); lcd.print("<-C | D->  Volver<#>");
}

void accion_editFormula(){ 
    if(pulsacion == '#') {contador = 1;contador_formula = 0;lcd.clear();pulsacion = ' ';}
    if(pulsacion == 'D') {contador_formula += 1;if(contador_formula > 23){contador_formula = 0;} lcd.clear();pulsacion = ' ';}
    if(pulsacion == 'C') {contador_formula -= 1;if(contador_formula < 0){contador_formula = 23;} lcd.clear();pulsacion = ' ';}
    if(pulsacion == 'A') {contador = 5;lcd.clear();pulsacion = ' ';}
    if(pulsacion == 'B') {contador = 6;lcd.clear();pulsacion = ' ';}
}

void menu_editDosis1(){
 lcd.setCursor(0,0); lcd.print("      Formula ");lcd.print(contador_formula + 1);
 lcd.setCursor(0,1); lcd.print("   DOSIS 1: ");lcd.print("(");lcd.print(dosis_1[contador_formula]);lcd.print(")");
 lcd.setCursor(0,2); lcd.print("VALOR (Kg):");
 while(edit != true){
  lcd.setCursor(0,3); lcd.print("           Enter <#>");
  readVal(11, 2);
  if(myString != ""){
   edit = true;
   dosis_1[contador_formula] = myString.toInt();
   EEPROM.put(adr_d1[contador_formula], dosis_1[contador_formula]);        
   lcd.setCursor(11,2); lcd.print(dosis_1[contador_formula]);
   lcd.setCursor(0,3); lcd.print("CORRECTO");
   delay(800);
   }else{
     edit = true;
     }              
  }
 contador = 4;
 edit = false; 
 lcd.clear();      
 }
 
void accion_editDosis1(){
                
 }

void menu_editDosis2(){
 lcd.setCursor(0,0); lcd.print("      Formula ");lcd.print(contador_formula + 1);
 lcd.setCursor(0,1); lcd.print("   DOSIS 2: ");lcd.print("(");lcd.print(dosis_2[contador_formula]);lcd.print(")");
 lcd.setCursor(0,2); lcd.print("VALOR (Kg):");
 while(edit != true){
  lcd.setCursor(0,3); lcd.print("           Enter <#>");
  readVal(11, 2);
  if(myString != ""){
   edit = true;
   dosis_2[contador_formula] = myString.toInt();        
   EEPROM.put(adr_d2[contador_formula], dosis_2[contador_formula]);          
   lcd.setCursor(11,2); lcd.print(dosis_2[contador_formula]);
   lcd.setCursor(0,3); lcd.print("CORRECTO");
   delay(800);
   }else{
     edit = true;
     }           
  }
 edit = false;
 contador = 4;
 lcd.clear();   
 }

void accion_editDosis2(){
  
 }
