#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* file_in = argv[1];
    char* file_out = argv[2];

    FILE* fin = fopen(file_in, "r");
    FILE* fout= fopen(file_out, "w");


    if (fin == NULL) {
        printf("Error opening file %s\n", file_in);
        return -1;
    }

    if (fout == NULL) {
        printf("Error opening file %s\n", file_out);
        return -1;
    }


    int i, j;
    int buffer[6];
    double buffer2[8];
    int NINTCI;
    int NINTCF;
    int NEXTCI;
    int NEXTCF;


    //4 variables in total!!!
    fscanf(fin, "%d", &NINTCI);
    fscanf(fin, "%d", &NINTCF);
    fscanf(fin, "%d", &NEXTCI);
    fscanf(fin, "%d", &NEXTCF);

    fwrite(&NINTCI, sizeof(int), 1, fout);
    fwrite(&NINTCF, sizeof(int), 1, fout);
    fwrite(&NEXTCI, sizeof(int), 1, fout);
    fwrite(&NEXTCF, sizeof(int), 1, fout);

    //start reading LCC
    //Note that C array index starts from 0 while Fortran starts from 1!

    for (i = NINTCI; i <= NINTCF; i++) {
        for (j = 0; j < 6; ++j)
            fscanf(fin, "%d", &(buffer[j]));

        for (j = 0; j < 6; ++j)
            fwrite(&(buffer[j]), sizeof(int), 1, fout);
    }


    // read the other arrays
    for (i = NINTCI; i <= NINTCF; i++) {
        for(j = 0; j < 8; ++j) 
            fscanf(fin, "%lf", &(buffer2[j]));

        for(j = 0; j < 8; ++j) 
            fwrite(&(buffer2[j]), sizeof(double), 1, fout);
    }


    for (i = NINTCI; i <= NINTCF; i++) {
        fscanf(fin, "%d", &(buffer[0]));
        fwrite(&(buffer[0]), sizeof(int), 1, fout);
    }

    fclose(fin);
    fclose(fout);
    return 0;

}
