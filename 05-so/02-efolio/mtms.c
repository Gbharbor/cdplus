/*
 * mtms.c
 * Merge Sort multitarefa - base de implementação
 * C99 + POSIX Threads
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sched.h>
#include <time.h>

#define MAX_N 20000
#define MAX_CHUNK 16
#define MAX_NT 64
#define MAX_NAME 128

typedef struct {
    int *v;
    int size;
} Chunk;

typedef struct {
    Chunk *items;
    int capacity;
    int count;
    int in;
    int out;
    pthread_mutex_t mutex;
} Buffer;

static int nt;
static int dim_buffer_ordenacao;
static int dim_buffer_fusao;
static int n;

static int dados[MAX_N];
static int resultado[MAX_N];

static Buffer buffer_ord;
static Buffer buffer_fusao;

/* Controlo de fim */
static int leitura_terminou = 0;

/* Estatísticas */
static int leitora_ints = 0;
static int leitora_buffers = 0;

static int ordenadora_ints[MAX_NT];
static int ordenadora_buffers[MAX_NT];

static int fusao_ints = 0;
static int fusao_count = 0;

/*  BUFFER  */

static void buffer_init(Buffer *b, int capacity)
{
    b->items = malloc(sizeof(Chunk) * capacity);
    b->capacity = capacity;
    b->count = 0;
    b->in = 0;
    b->out = 0;
    pthread_mutex_init(&b->mutex, NULL);
}

static int buffer_put(Buffer *b, Chunk c)
{
    int ok = 0;

    pthread_mutex_lock(&b->mutex);

    if (b->count < b->capacity) {
        b->items[b->in] = c;
        b->in = (b->in + 1) % b->capacity;
        b->count++;
        ok = 1;
    }

    pthread_mutex_unlock(&b->mutex);

    return ok;
}

static int buffer_get(Buffer *b, Chunk *c)
{
    int ok = 0;

    pthread_mutex_lock(&b->mutex);

    if (b->count > 0) {
        *c = b->items[b->out];
        b->out = (b->out + 1) % b->capacity;
        b->count--;
        ok = 1;
    }

    pthread_mutex_unlock(&b->mutex);

    return ok;
}

/*  ORDENAÇÃO LOCAL  */

static void insertion_sort(int *v, int size)
{
    int i, j, key;

    for (i = 1; i < size; i++) {
        key = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = key;
    }
}

/*  FUSÃO  */

static void merge_vectors(int *dest, int *dest_size, int *src, int src_size)
{
    int temp[MAX_N];
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < *dest_size && j < src_size) {
        if (dest[i] <= src[j]) {
            temp[k++] = dest[i++];
        } else {
            temp[k++] = src[j++];
        }
    }

    while (i < *dest_size) {
        temp[k++] = dest[i++];
    }

    while (j < src_size) {
        temp[k++] = src[j++];
    }

    for (i = 0; i < k; i++) {
        dest[i] = temp[i];
    }

    *dest_size = k;
}

/*  LEITURA DO FICHEIRO  */

static void ler_ficheiro(const char *nome)
{
    FILE *fp;
    char linha[256];
    int valor;
    int count = 0;

    fp = fopen(nome, "r");
    if (fp == NULL) {
        exit(1);
    }

    fscanf(fp, "nt=%d\n", &nt);
    fscanf(fp, "dim_buffer_ordenacao=%d\n", &dim_buffer_ordenacao);
    fscanf(fp, "dim_buffer_fusao=%d\n", &dim_buffer_fusao);
    fscanf(fp, "n=%d\n", &n);

    fgets(linha, sizeof(linha), fp); /* lê linha "# dados" */

    while (count < n && fscanf(fp, "%d", &valor) == 1) {
        dados[count++] = valor;
    }

    fclose(fp);
}

/*  THREAD LEITORA  */

static void *thread_leitora(void *arg)
{
    int i = 0;

    (void)arg;

    while (i < n) {
        Chunk c;
        int size = MAX_CHUNK;

        if (i + size > n) {
            size = n - i;
        }

        c.v = &dados[i];
        c.size = size;

        while (!buffer_put(&buffer_ord, c)) {
            sched_yield();
        }

        leitora_ints += size;
        leitora_buffers++;

        i += size;
    }

    leitura_terminou = 1;

    return NULL;
}

/*  THREAD ORDENADORA  */

static void *thread_ordenadora(void *arg)
{
    int id = *(int *)arg;
    Chunk c;

    while (1) {
        if (buffer_get(&buffer_ord, &c)) {
            insertion_sort(c.v, c.size);

            while (!buffer_put(&buffer_fusao, c)) {
                sched_yield();
            }

            ordenadora_ints[id] += c.size;
            ordenadora_buffers[id]++;
        } else {
            if (leitura_terminou) {
                break;
            }

            sched_yield();
        }
    }

    return NULL;
}

/*  THREAD FUSÃO  */

static void *thread_fusao(void *arg)
{
    int resultado_size = 0;
    Chunk c;

    (void)arg;

    while (fusao_ints < n) {
        if (buffer_get(&buffer_fusao, &c)) {
            merge_vectors(resultado, &resultado_size, c.v, c.size);

            fusao_ints += c.size;
            fusao_count++;
        } else {
            sched_yield();
        }
    }

    return NULL;
}

/*  IMPRESSÃO  */

static void imprimir_dados_ordenados(void)
{
    int i;

    printf("# dados ordenados\n");

    for (i = 0; i < n; i++) {
        if (i % 12 == 0 && i != 0) {
            printf("\n");
        }

        if (i % 12 != 0) {
            printf(" ");
        }

        printf("%d", resultado[i]);
    }

    printf("\n");
}

static void imprimir_relatorio(void)
{
    int i;

    printf("nt=%d\n", nt);
    printf("n=%d\n", n);

    printf("T. Leitora:\n");
    printf("%d ints em %d buffers\n",
           leitora_ints,
           leitora_buffers);

    printf("T. Ordenadoras(%d):\n", nt);

    for (i = 0; i < nt; i++) {
        printf("T_%d: %d ints em %d buffers\n",
               i,
               ordenadora_ints[i],
               ordenadora_buffers[i]);
    }

    printf("T. Fusão:\n");
    printf("%d ints em %d fusões\n",
           fusao_ints,
           fusao_count);

    imprimir_dados_ordenados();
}

int main(void)
{
    char nome[MAX_NAME];
    pthread_t t_leitora;
    pthread_t t_fusao;
    pthread_t t_ordenadoras[MAX_NT];
    int ids[MAX_NT];
    int i;

    if (scanf("%127s", nome) != 1) {
        return 1;
    }

    ler_ficheiro(nome);

    buffer_init(&buffer_ord, dim_buffer_ordenacao);
    buffer_init(&buffer_fusao, dim_buffer_fusao);

    pthread_create(&t_leitora, NULL, thread_leitora, NULL);

    for (i = 0; i < nt; i++) {
        ids[i] = i;
        pthread_create(&t_ordenadoras[i], NULL,
                       thread_ordenadora, &ids[i]);
    }

    pthread_create(&t_fusao, NULL, thread_fusao, NULL);

    pthread_join(t_leitora, NULL);

    for (i = 0; i < nt; i++) {
        pthread_join(t_ordenadoras[i], NULL);
    }

    pthread_join(t_fusao, NULL);

    imprimir_relatorio();

    return 0;
}
