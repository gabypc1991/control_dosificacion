void intro_0(){ 
 lcd.clear();  // Borra el  LCD
 lcd.setCursor(0, 0); lcd.print("--------------v1.10-");
 lcd.setCursor(0, 1); lcd.print("    CONTROLADOR     ");
 lcd.setCursor(0, 2); lcd.print("     DOSIFICACION   ");
 lcd.setCursor(0, 3); lcd.print("--------------------");
 delay(4000);                // espera 4 segundos mostrando el intro
 lcd.clear();
}
