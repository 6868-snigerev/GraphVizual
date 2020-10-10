#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

struct top {
    int value;
    int arrTops[SIZE];
};

void checkCoherence(struct top *tops){
    int numEdges = 0;
    int flag = 0;

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++) {
            if (tops[j].arrTops[i] == 1){
                numEdges++;
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {

        if (tops[i].arrTops[i] != 0){
            flag = 1;
        }
    }

    if((numEdges < ((SIZE-1)*(SIZE-2))/2) && flag == 0){
        printf("\nThis graph is connectivity");
    } else if (flag == 1){
        printf("\nThe requirements aren't met");
    } else {
        printf("\nThis graph is not connectivity");
    }

}

void initTops(struct top *tops) {
    int mx[SIZE][SIZE];
    FILE *fin;
    for (int i = 0; i < SIZE; i++) {
        printf("Enter the %d edge value\n", i+1);
        scanf("%d", &tops[i].value);
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tops[i].arrTops[j] = 0;
        }
    }

    fin = fopen("matrix.txt", "r");

    if (fin != NULL) {
        for(int j = 0; j < SIZE; j++) {
            for(int i = 0; i < SIZE; i++) {

                fscanf(fin, "%d,", &mx[i][j]);
                if (mx[i][j] == 1) {
                    tops[j].arrTops[i] = tops[j].value;
                }
            }
        }

        fclose(fin);
    } else {
        printf("Error");
    }
}
void vizualgraph(struct top *tops){
    FILE *file;
    file = fopen("graph.dot", "w");
        if (file != NULL) {
            fprintf(file, "graph mainGraph {\n");
            for (int i = 0; i < SIZE; i++) {

                for (int j = 0; j < SIZE; j++) {

                    if(tops[j].arrTops[i]!=0){
                    fprintf(file, "  %d -- %d\n", tops[i].value, tops[j].arrTops[i]);
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
    struct top tops[SIZE];
    initTops(&tops);
    vizualgraph(&tops);
    checkCoherence(&tops);
}

