void eeprom_get_inicio(){
  EEPROM.get(0, f1D1);
  EEPROM.get(4, f1D2);
  EEPROM.get(8, factor);
  EEPROM.get(12, t_mezcla);
  EEPROM.get(16, f2D1);
  EEPROM.get(20, f2D2);
  EEPROM.get(24, f3D1);
  EEPROM.get(28, f3D2);
  }