#ifndef COUNT_H_INCLUDED
#define COUNT_H_INCLUDED

using namespace std;

void ordenar(int **numeros, int *numPunteros, int numerosCont)
{
    for (int i = 0; i < numerosCont - 1; i++)
    {
        for (int j = 0; j < numerosCont - i - 1; j++)
        {
            if (numPunteros[j] > numPunteros[j + 1])
            {
                int temp = numPunteros[j];
                numPunteros[j] = numPunteros[j + 1];
                numPunteros[j + 1] = temp;
                int *temp2 = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp2;
            }
        }
    }
};

void imprimir(int *numeros[], int numPunteros[], int numerosCont)
{
    for (int i = 0; i < numerosCont; i++)
    {
        cout << **(numeros + i) << " ";
        cout << numPunteros[i] << endl;
    }
}

void count(int **p[])
{
    int *numeros[MAX_NUM_INTVAR] = {NULL};
    int numPunteros[MAX_NUM_INTVAR] = {0};
    int numerosCont = 0;
    for (int i = 0; p[i] != NULL; i++)
    {
        bool existe = false;
        int k;
        int posicion = 0;
        for (k = 0; k < numerosCont; k++)
        {
            if (numeros[k] == **(p + i))
            {
                existe = true;
                posicion = k;
            }
        }
        if (existe)
        {
            numPunteros[posicion]++;
        }
        else
        {
            numeros[numerosCont] = **(p + i);
            numPunteros[numerosCont]++;
            numerosCont += 1;
        }
    }
    ordenar(numeros, numPunteros, numerosCont);
    imprimir(numeros, numPunteros, numerosCont);
}
#endif