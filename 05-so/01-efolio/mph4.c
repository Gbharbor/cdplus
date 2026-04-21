/*
** file: mph4.c  (template) (** UTF-8 **)
**
** UC: 21111 - SO @ UAb
** e-fólio A 2025-26
** mph4 - multi process hash 4 bytes
**
** Botão VPL "Run"  <=> Utilização com dados do utilizador em terminal:
**    ./mph4 np     # lê da entrada padrão stdin o nome do ficheiro a processar
** Botão VPL "Evaluate" <=> Utilização com redireção de ficheiros automática:
**    ./mph4 np <input.txt >output.txt
**
** Compilação VPL (auto):   gcc -Wall -std=c99 -o mph4 mph4.c
**
** Aluno: NNNNN - Nome Apelido
*/

#define _FILE_OFFSET_BITS 64

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

// macros
// Num. máximo processos np (trabalhadores)
#define MAXPROC 8

static int write_full(int fd, const void *buf, size_t count)
{
    const unsigned char *p = (const unsigned char *)buf;
    size_t total = 0;

    while (total < count) {
        ssize_t n = write(fd, p + total, count - total);
        if (n <= 0) {
            return -1;
        }
        total += (size_t)n;
    }

    return 0;
}

static int read_full(int fd, void *buf, size_t count)
{
    unsigned char *p = (unsigned char *)buf;
    size_t total = 0;

    while (total < count) {
        ssize_t n = read(fd, p + total, count - total);
        if (n <= 0) {
            return -1;
        }
        total += (size_t)n;
    }

    return 0;
}

static uint32_t hash_range(const char *filename, off_t start_block, off_t num_blocks)
{
    uint32_t hash = 0;
    int fd;
    off_t start_pos;
    off_t i;

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        return 0;
    }

    start_pos = start_block * 4;
    if (lseek(fd, start_pos, SEEK_SET) == (off_t)-1) {
        close(fd);
        return 0;
    }

    for (i = 0; i < num_blocks; i++) {
        unsigned char buf[4] = {0, 0, 0, 0};
        ssize_t n = read(fd, buf, 4);
        uint32_t block;

        if (n < 0) {
            close(fd);
            return 0;
        }

        // Ordem esperada pelo VPL: little-endian
        block = ((uint32_t)buf[0]) |
                ((uint32_t)buf[1] << 8) |
                ((uint32_t)buf[2] << 16) |
                ((uint32_t)buf[3] << 24);

        hash ^= block;

        if (n < 4) {
            break;
        }
    }

    close(fd);
    return hash;
}

int main(int argc, char *argv[])
{
    int np = 1;
    char filename[4096];
    int i;
    int pipes[MAXPROC][2];
    pid_t pids[MAXPROC];
    uint32_t final_hash = 0;
    int fd;
    off_t dim;
    off_t total_blocks;
    off_t full_blocks;
    off_t base_blocks;

    if (argc >= 2) {
        np = atoi(argv[1]);
        if (np < 1 || np > MAXPROC) {
            np = 1;
        }
    }

    if (scanf("%4095s", filename) != 1) {
        return 1;
    }

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        return 1;
    }

    dim = lseek(fd, 0, SEEK_END);
    close(fd);

    if (dim < 0) {
        return 1;
    }

    total_blocks = (dim + 3) / 4;
    full_blocks = dim / 4;
    base_blocks = full_blocks / np;

    for (i = 0; i < np; i++) {
        if (pipe(pipes[i]) == -1) {
            return 1;
        }

        pids[i] = fork();

        if (pids[i] < 0) {
            return 1;
        }

        if (pids[i] == 0) {
            uint32_t partial_hash;
            off_t start_block;
            off_t blocks_to_process;
            int j;

            close(pipes[i][0]);

            for (j = 0; j < i; j++) {
                close(pipes[j][0]);
                close(pipes[j][1]);
            }

            start_block = (off_t)i * base_blocks;

            if (i == np - 1) {
                blocks_to_process = total_blocks - start_block;
            } else {
                blocks_to_process = base_blocks;
            }

            partial_hash = hash_range(filename, start_block, blocks_to_process);

            if (write_full(pipes[i][1], &partial_hash, sizeof(partial_hash)) == -1) {
                close(pipes[i][1]);
                _exit(1);
            }

            close(pipes[i][1]);
            _exit(0);
        }

        close(pipes[i][1]);
    }

    for (i = 0; i < np; i++) {
        uint32_t partial_hash = 0;

        if (read_full(pipes[i][0], &partial_hash, sizeof(partial_hash)) == -1) {
            close(pipes[i][0]);
            return 1;
        }

        close(pipes[i][0]);
        final_hash ^= partial_hash;
    }

    for (i = 0; i < np; i++) {
        waitpid(pids[i], NULL, 0);
    }

    printf("hash4= %04X %04X\n",
           (unsigned int)((final_hash >> 16) & 0xFFFF),
           (unsigned int)(final_hash & 0xFFFF));

    return 0;
}

// EOF