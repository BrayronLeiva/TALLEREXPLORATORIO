#include <stdio.h>
#include <pthread.h>

#define N 5  // Cantidad de mutexes

pthread_mutex_t mutexes[N];

void* moverHilo(void* arg) {
    for (int i = 0; i < N; i++) {
        printf("Hilo intentando tomar mutex en la posicion %d\n", i);
        pthread_mutex_lock(&mutexes[i]);
        printf("Hilo tomo el mutex %d\n", i);
        pthread_mutex_unlock(&mutexes[i]);
    }
    return NULL;
}

int main() {
    pthread_t hilo;

    // Inicializar mutexes
    for (int i = 0; i < N; i++)
        pthread_mutex_init(&mutexes[i], NULL);

    // Crear hilo
    pthread_create(&hilo, NULL, moverHilo, NULL);
    pthread_join(hilo, NULL);

    // Destruir mutexes
    for (int i = 0; i < N; i++)
        pthread_mutex_destroy(&mutexes[i]);

    return 0;
}
