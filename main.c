#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

struct verticale {
    int value;
    int arrEdges[SIZE];
};

void initVerticales(struct verticale *verticales) {
    int mx[SIZE][SIZE];
    FILE *fin;
    int k = 1;
    for (int i = 0; i < SIZE; i++) {
        printf("Enter the %d edge value\n", k);
        scanf("%d", &verticales[i].value);
        k++;
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            verticales[i].arrEdges[j] = 0;
        }
    }

    fin = fopen("matrix.txt", "r");

    if (fin != NULL) {
        for(int j = 0; j < SIZE; j++) {
            for(int i = 0; i < SIZE; i++) {

                fscanf(fin, "%d,", &mx[i][j]);
                if (mx[i][j] == 1) {
                    verticales[j].arrEdges[i] = verticales[j].value;
                }
            }
        }

        fclose(fin);
    } else {
        printf("Error");
    }
}
){
    FILE *file;
    file = fopen("graph.dot", "w");
        if (file != NULL) {
            fprintf(file, "graph mainGraph {\n");
            for (int i = 0; i < SIZE; i++) {

                for (int j = 0; j < SIZE; j++) {

                    if(verticales[j].arrEdges[i]!=0){
                    fprintf(file, "  %d -- %d\n", verticales[i].value, verticales[j].arrEdges[i]);
                    }
                }
            }

            fprintf(file, "}");
        } else {
            printf("Error during writing file!");
            exit("Error");
        }
}

void main(void){
    struct verticale verticales[SIZE];
    initVerticales(&verticales);
    vizualgraph(&verticales);
}

