int LDRValue1_1, LDRValue1_2, LDRValue1_3;
int LDRValue2_1, LDRValue2_2, LDRValue2_3;
int LDRValue3_1, LDRValue3_2, LDRValue3_3;
int LDRValue4_1, LDRValue4_2, LDRValue4_3;
int LDRValue1, LDRValue2, LDRValue3, LDRValue4;

void setup()
{

  Serial.begin(9600);

}

void loop()
{

  leerDatos();
  
  LDRValue1 = promedio1();
  LDRValue2 = promedio2();
  LDRValue3 = promedio3();
  LDRValue4 = promedio4();

  Serial.print("Luz 1: ");
  Serial.print(LDRValue1);
  Serial.print(" luz 2: ");
  Serial.print(LDRValue2);
  Serial.print(" luz 3: ");
  Serial.print(LDRValue3);
  Serial.print(" luz 4: ");
  Serial.println(LDRValue4);
  
}

void leerDatos()
{
//enfrente
  LDRValue1_1 = analogRead(A6);
  LDRValue1_2 = analogRead(A7);
  LDRValue1_3 = analogRead(A8);
//izquierda(clema)  
  LDRValue2_1 = analogRead(A9);
  LDRValue2_2 = analogRead(A10);
  LDRValue2_3 = analogRead(A11);
//derecha  
  LDRValue3_1 = analogRead(A3);
  LDRValue3_2 = analogRead(A4);
  LDRValue3_3 = analogRead(A5);
//atras  
  LDRValue4_1 = analogRead(A0);
  LDRValue4_2 = analogRead(A1);
  LDRValue4_3 = analogRead(A2);
}

int promedio1()
{

  return (LDRValue1_1, LDRValue1_2, LDRValue1_3)/3;

}

int promedio2()
{

  return (LDRValue2_1, LDRValue2_2, LDRValue2_3)/3;

}

int promedio3()
{

  return (LDRValue3_1, LDRValue3_2, LDRValue3_3)/3;

}

int promedio4()
{

  return (LDRValue4_1, LDRValue4_2, LDRValue4_3)/3;

}

