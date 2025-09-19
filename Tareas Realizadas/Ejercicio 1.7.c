#include <stdio.h>

  /*Medias.
  El programa, al recibir como datos la longitud y el peso de un objeto
  Expreados en pies y librass, calcula los datos de este objeto pero en
  Metro y Kilogramos, respectivamente.

  PIE, LIB, KIL: variables de tipo real. */

  void main(void)
  {
      float PIE, LIB, MET, KIL;
      printf("Ingrese los datos del objeto:" );
      scanf("%f %f", &PIE, &LIB);
      MET = PIE * 0.09290;
      KIL = LIB * 0.45359;
      printf("\nDatos del objeto \nLongitud: %5.2 \t Peso: %5.2f", MET, KIL);
  }
