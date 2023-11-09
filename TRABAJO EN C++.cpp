#include <stdio.h>
#include <string.h>

struct Estudiante {
    char nombre[50];
    int id;
    float notas[5]; // EL CODIGO TIENE UNA ESCTROCTURA LLAMADA ESTUDIANTE
};

void consultarNotas(struct Estudiante est) {
    printf("Notas de %s (ID: %d):\n", est.nombre, est.id);
    for (int i = 0; i < 5; i++) {
        printf("Asignatura %d: %.2f\n", i + 1, est.notas[i]);
    }
}

float calcularPromedio(struct Estudiante est) {
    float sum = 0.0;
    for (int i = 0; i < 5; i++) {
        sum += est.notas[i];
    }
    return sum / 5;
}

int main() {//LA FUNCION  MAIN ES DONDE SE EJECUTA EL PROGRAMA
    int numEstudiantes;
    printf("Cuantos estudiantes quiere registrar: ");
    scanf("%d", &numEstudiantes);

    struct Estudiante estudiantes[numEstudiantes];

    for (int i = 0; i < numEstudiantes; i++) {
        printf("Ingrese el nombre del estudiante %d: ", i + 1);//printf: Esta función se utiliza para imprimir un mensaje en la consola. "Ingrese el nombre del estudiante %d: ": Es una cadena de texto

//que se muestra en la consola. El %des un marcador de posición que se reemplaza por el valor de i + 1. Esto permite mostrar el número del estudiante en el mensaje.

 i + 1: Es la expresión i + 1, donde ies una variable que representa el índice del estudiante en el bucle for. Al sumarle 1, se obtiene el número del estudiante que se está registrando
        scanf("%s", estudiantes[i].nombre);
        printf("Ingrese el ID del estudiante %d: ", i + 1);
        scanf("%d", &estudiantes[i].id);

        for (int j = 0; j < 5; j++) {
            printf("Ingrese la nota de la asignatura %d para el estudiante %d: ", j + 1, i + 1);
            scanf("%f", &estudiantes[i].notas[j]);
        }//scanf: Esta función se utiliza para leer la entrada del usuario desde la consola.

 //"%f": Es un especificador de formato que indica que se espera un valor de tipo float.

//&estudiantes[i].notas[j]: Es la dirección de memoria donde se almacenará el valor ingresado por el usuario. estudiantes[i]de refiere al estudiante en la posición iy.notas[j]se refiere a la asignatura en la posición jde de notas.
    }

    int opcion;//LA OPCION DE ESTE USUARIO SE ALMACENA AQUI
    int estudianteSeleccionado;
    
    while (1) {//ESTE PERMITE QUE MUESTRA UN MENU DE OPCIONES
        printf("\nMenu:\n");
        printf("1. Consultar notas\n");
        printf("2. Calcular promedio\n");// EL CODIGO TIENE DOS FUNCIONES QUE SON CONSULTAR NOTAS Y CALCULAR PROMEDIO
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {//  switch ESTA SE USA PARA REALIZAR DIFERENTES ACCIONES SEGUN LA ELECCION DEL USUARIO
            case 1:
                printf("Ingrese el nUmero de estudiante a consultar: ");
                scanf("%d", &estudianteSeleccionado);
                if (estudianteSeleccionado >= 1 && estudianteSeleccionado <= numEstudiantes) {//ESTA VARIABLE ALMACENA EL NUMERO DE ESTUDIANTES QUE SE MATRICULAN SE LE DA A SOLICITAR AL USUARIO QUE INGRESE DATO O VALOR
                    consultarNotas(estudiantes[estudianteSeleccionado - 1]);
                } else {
                    printf("Estudiante no encontrado.\n");
                }
                break;
            case 2:
                printf("Ingrese el nUmero de estudiante para calcular el promedio: ");
                scanf("%d", &estudianteSeleccionado);
                if (estudianteSeleccionado >= 1 && estudianteSeleccionado <= numEstudiantes) {
                    float promedio = calcularPromedio(estudiantes[estudianteSeleccionado - 1]);//CALCULA LA CALIFICACION PROMEDIO Y LA DEVUELVE
                    printf("Promedio del estudiante %d: %.2f\n", estudianteSeleccionado, promedio);
                } else {
                    printf("Estudiante no encontrado.\n");
                }
                break;
            case 3:
                return 0;
            default:
                printf("Opcion no valida.\n");
        }
    }

    return 0;
}
