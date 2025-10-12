 #include <stdio.h>

  int f1 (int);

  void main(void)
  {
      int I, K = 4;
      for (I = 1; I <= 3; I++)
      {
          printf("\n\nValor de k antes de llamar la funcion:  %d", ++K);
          printf("\nvalor de k despues de llamar la funcion: %d", K);

      }
  }
    int f1 (int R)

    {
        R += R;
        return (R);
    }
