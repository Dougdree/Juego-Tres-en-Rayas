#include <stdio.h>

// Función para imprimir el mensaje de bienvenida 
void bienvenida() {
    // Imprime el mensaje de bienvenida
    printf("¡Bienvenido al juego de Tres en Raya!\n");
}

// Función para imprimir el tablero
void imprimirTablero(char tablero[3][3]) {
    // Imprime el tablero en su estado actual
    printf("\n");
    for (int i = 0; i < 3; i++) { // Recorre cada fila
        for (int j = 0; j < 3; j++) { // Recorre cada columna
            printf(" %c ", tablero[i][j]); // Imprime el valor de la celda
            if (j < 2) printf("|"); // Imprime la separación de columnas
        }
        printf("\n");
        if (i < 2) printf("---+---+---\n"); // Imprime la separación de filas
    }
    printf("\n");
}

// Función para verificar si hay un ganador
char verificarGanador(char tablero[3][3]) {
    // Verifica filas y columnas
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] != ' ') // Verifica filas
            return tablero[i][0]; // Retorna el ganador si hay tres en línea
        if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] && tablero[0][i] != ' ') // Verifica columnas
            return tablero[0][i]; // Retorna el ganador si hay tres en línea
    }
    // Verifica diagonales
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[0][0] != ' ')
        return tablero[0][0]; // Retorna el ganador si hay tres en diagonal
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] && tablero[0][2] != ' ')
        return tablero[0][2]; // Retorna el ganador si hay tres en diagonal
    // No hay ganador
    return ' ';
}

// Función para reiniciar el tablero
void reiniciarTablero(char tablero[3][3]) {
    // Reinicia el tablero a su estado vacío
    for (int i = 0; i < 3; i++) { // Recorre cada fila
        for (int j = 0; j < 3; j++) { // Recorre cada columna
            tablero[i][j] = ' '; // Asigna espacio vacío a cada celda
        }
    }
}

// Función principal
int main() {
    char tablero[3][3]; // Define el tablero de 3x3
    int jugador, fila, columna, opcion; // Variables para el jugador, filas, columnas y opción
    char ganador; // Variable para el ganador
    
    bienvenida(); // Llama a la función de bienvenida
    
    while (1) { // Bucle principal del juego
        // Selección de jugador
        printf("¿Desea ser el Jugador 1 o el Jugador 2? (1/2): ");
        scanf("%d", &jugador); // Lee la elección del jugador
        
        reiniciarTablero(tablero); // Reinicia el tablero
        ganador = ' '; // Inicializa el ganador a espacio vacío
        
        // Bucle del juego
        for (int turno = 0; turno < 9 && ganador == ' '; turno++) { // Hasta 9 turnos o hasta que haya un ganador
            imprimirTablero(tablero); // Imprime el estado actual del tablero
            printf("Turno del Jugador %d\n", (turno % 2) + 1); // Indica de quién es el turno
            printf("Ingrese la fila (0-2): ");
            scanf("%d", &fila); // Lee la fila
            printf("Ingrese la columna (0-2): ");
            scanf("%d", &columna); // Lee la columna
            
            // Validar movimiento
            if (fila >= 0 && fila < 3 && columna >= 0 && columna < 3 && tablero[fila][columna] == ' ') { // Verifica que la celda esté dentro del rango y vacía
                tablero[fila][columna] = (turno % 2) + 1 == 1 ? 'X' : 'O'; // Asigna 'X' o 'O' dependiendo del turno
                ganador = verificarGanador(tablero); // Verifica si hay un ganador
            } else {
                printf("Movimiento no válido, intente de nuevo.\n"); // Mensaje de movimiento inválido
                turno--; // No cuenta el turno inválido
            }
        }
        
        imprimirTablero(tablero); // Imprime el tablero final
        
        if (ganador != ' ') { // Si hay un ganador
            printf("¡El Jugador %d ha ganado la partida!\n", ganador == 'X' ? 1 : 2); // Anuncia al ganador
        } else {
            printf("¡Es un empate!\n"); // Anuncia el empate
        }
        
        // Menú de revancha
        if (ganador != ' ') {
            printf("¿Quiere revancha? Presione 1 para revancha o 2 para salir: "); // Opción de revancha
        } else {
            printf("Hubo un empate, ¿quieren volver a jugar? Presione 1 para volver a jugar o 2 para salir: "); // Opción de jugar de nuevo tras empate
        }
        scanf("%d", &opcion); // Lee la opción
        
        if (opcion == 2) break; // Sale del bucle principal si la opción es 2
    }
    
    printf("Gracias por jugar. ¡Hasta la próxima!\n"); // Mensaje de despedida
    return 0; // Termina el programa
}
