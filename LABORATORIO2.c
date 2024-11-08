/* 
Universidad Simon Bolivar
Este es el quiz 2 del laboratorio de computacion 1 --- CI2125
Estudiante: Nohely Vasquez, Carnet: 20-10651
Profesor: Ing. Jorge Baralt
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int coeficiente;
    int exponente;
} Termino;

typedef struct {
    Termino terminos[100];
    int n;
} Polinomio;

void leer_polinomio(Polinomio *p) {
    int i;

    printf("Ingrese el orden del polinomio: ");
    scanf("%d", &p->n);

    for (i = 0; i <= p->n; i++) {
        printf("Ingrese el coeficiente del termino x^%d: ", i);
        scanf("%d", &p->terminos[i].coeficiente);
    }

    for (i = p->n + 1; i < 100; i++) {
        p->terminos[i].coeficiente = 0;
    }
}

Polinomio *sumar_polinomios(Polinomio *p1, Polinomio *p2) {
    Polinomio *resultado = malloc(sizeof(Polinomio));
    int i;

    resultado->n = p1->n > p2->n ? p1->n : p2->n;
    for (i = 0; i <= resultado->n; i++) {
        resultado->terminos[i].coeficiente = p1->terminos[i].coeficiente + p2->terminos[i].coeficiente;
    }

    // Para los términos de orden superior, se utiliza el siguiente algoritmo:

    for (i = resultado->n + 1; i < 100; i++) {
        resultado->terminos[i].coeficiente = p1->terminos[i].coeficiente + p2->terminos[i].coeficiente;
        if (resultado->terminos[i].coeficiente != 0) {
            resultado->n = i;
        }
    }

    return resultado;
}

void imprimir_termino(int coeficiente, int exponente) {
    if (coeficiente != 0) {
        if (coeficiente > 0) {
            printf("+%dx^%d", coeficiente, exponente);
        } else {
            printf("%dx^%d", coeficiente, exponente);
        }
    }
}

void imprimir_polinomio(Polinomio *p) {
    int i;

    for (i = p->n; i >= 0; i--) {
        imprimir_termino(p->terminos[i].coeficiente, i);
    }
}

// Funcion main -------------------------------

int main() {
    int n_polinomios;
    int i, j;
    Polinomio *polinomios[100];
    Polinomio *suma;
    int orden_maximo;

    printf("Ingrese el numero de polinomios: ");
    scanf("%d", &n_polinomios);

    for (i = 0; i < n_polinomios; i++) {
        polinomios[i] = malloc(sizeof(Polinomio));
        leer_polinomio(polinomios[i]);
    }

    orden_maximo = 0;
    for (i = 0; i < n_polinomios; i++) {
        if (polinomios[i]->n > orden_maximo) {
            orden_maximo = polinomios[i]->n;
        }
    }

    // Imprimir matriz
    printf("\n");

    for (i = 0; i < n_polinomios; i++) {
        for (j = 0; j <= orden_maximo; j++) {
            printf("%d ", polinomios[i]->terminos[j].coeficiente);
        }
        printf("\n");
    }

    // Sumar polinomios

    suma = polinomios[0];
    for (i = 1; i < n_polinomios; i++) {
        suma = sumar_polinomios(suma, polinomios[i]);
    }

    // Imprimir resultado

    printf("\n La suma de los polinomios es: \n \n");
    imprimir_polinomio(suma);
    printf("\n \n");
    system("pause");
    return 0;


} 