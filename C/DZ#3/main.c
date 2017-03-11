#include <stdio.h>
#include <memory.h>
#include <errno.h>
#include "../Challenge#2/list.h"
#include "words.h"

#define MAX_WORDS 1024


bool print_words(word_t *data) {
    printf("%s: [%d]\n", data->word, data->count);
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Got %d arguments, expected 1.\n", argc - 1);
        return EXIT_FAILURE;
    }

    const char *path = argv[1];
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Unable to open %s: %s.\n", path, strerror(errno));
        fclose(fp);
        return EXIT_FAILURE;
    }

    list list;
    char **words = malloc(sizeof(char *) * MAX_WORDS);

    create_list(&list, sizeof(word_t), NULL);
    fill_from_file(&list, fp, words);
    sort_list(&list);
    fn_for_each(&list, (listIteratorFn) print_words);

    destroy(&list);
    for (int i = 0; i < MAX_WORDS; i++) {
        free(words[i]);
    }
    free(words);
    fclose(fp);
    return EXIT_SUCCESS;
}