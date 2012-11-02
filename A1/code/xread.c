/*
 * 22-May-2009 Eric Xue
 * This function perform initialization step by reading from a data file
 */

#include <stdio.h>
#include <stdlib.h>

int read_long_formatted(char *fileName, int *NINTCI, int *NINTCF, int *NEXTCI,
                        int *NEXTCF, int *NBCESI, int *NBCESF, int *NBCEWI, int *NBCEWF,
                        int *NBCELI, int *NBCELF, int *NSDIR, int *NEDIR, int *NI, int *NJ,
                        int *NK, int *NDIR1, int *NDIR2, int *NDIR3, int *NBS, int *NBW,
                        int *NBL, int *NBN, int *NBE, int *NBH, int *IDIM, int *INCR,
                        int ***LCC, int **LBS, int **LBN, int **LBW, int **LBE, int **LBL,
                        int **LBH, int **NTRAEW, int **NTRANS, int **NTRAHL, int **NBOARD,
                        double **BS, double **BE, double **BN, double **BW, double **BL,
                        double **BH, double **BP, double **SU)
{
    int i;
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", fileName);
        return -1;
    }

    //26 variables in total!!!
    fscanf(fp, "%d", NINTCI);
    fscanf(fp, "%d", NINTCF);
    fscanf(fp, "%d", NEXTCI);
    fscanf(fp, "%d", NEXTCF);
    fscanf(fp, "%d", NBCESI);
    fscanf(fp, "%d", NBCESF);
    fscanf(fp, "%d", NBCEWI);
    fscanf(fp, "%d", NBCEWF);
    fscanf(fp, "%d", NBCELI);
    fscanf(fp, "%d", NBCELF);
    fscanf(fp, "%d", NSDIR);
    fscanf(fp, "%d", NEDIR);
    fscanf(fp, "%d", NI);
    fscanf(fp, "%d", NJ);
    fscanf(fp, "%d", NK);
    fscanf(fp, "%d", NDIR1);
    fscanf(fp, "%d", NDIR2);
    fscanf(fp, "%d", NDIR3);
    fscanf(fp, "%d", NBS);
    fscanf(fp, "%d", NBW);
    fscanf(fp, "%d", NBL);
    fscanf(fp, "%d", NBN);
    fscanf(fp, "%d", NBE);
    fscanf(fp, "%d", NBH);
    fscanf(fp, "%d", IDIM);
    fscanf(fp, "%d", INCR);

    //allocating LCC
    if ((*LCC = (int**) malloc(6 * sizeof(int*))) == NULL) {
        printf("malloc failed to allocate first dimension of LCC (6)");
        return -1;
    }

    for (i = 0; i < 6; i++) {
        if (((*LCC)[i] = (int *) malloc((*NINTCF + 1) * sizeof(int))) == NULL) {
            printf("malloc(LCC) failed\n");
            return -1;
        }
    }

    //start reading LCC
    //Note that C array index starts from 0 while Fortran starts from 1!
    for (i = (*NINTCI); i <= *NINTCF; i++) {
        fscanf(fp, "%d", &(*LCC)[0][i]);
        fscanf(fp, "%d", &(*LCC)[1][i]);
        fscanf(fp, "%d", &(*LCC)[2][i]);
        fscanf(fp, "%d", &(*LCC)[3][i]);
        fscanf(fp, "%d", &(*LCC)[4][i]);
        fscanf(fp, "%d", &(*LCC)[5][i]);
    }
#ifdef DEBUG

    printf("NBS = %d, NBW = %d, NBL = %d, NBN = %d, NBE = %d, NBH = %d\n", *NBS, *NBW, *NBL, *NBN, *NBE, *NBH);

#endif

    if ((*LBS = (int *) malloc((*NBS + 1) * sizeof(int))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }

    if ((*LBN = (int *) malloc((*NBN + 1) * sizeof(int))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }

    if ((*LBW = (int *) malloc((*NBW + 1) * sizeof(int))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }

    if ((*LBE = (int *) malloc((*NBE + 1) * sizeof(int))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }
    if ((*LBL = (int *) malloc((*NBL + 1) * sizeof(int))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }

    if ((*LBH = (int *) malloc((*NBH + 1) * sizeof(int))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }

    for (i = 1; i <= *NBS; i++) fscanf(fp, "%d", &((*LBS)[i]));
    for (i = 1; i <= *NBN; i++) fscanf(fp, "%d", &((*LBN)[i]));
    for (i = 1; i <= *NBW; i++) fscanf(fp, "%d", &((*LBW)[i]));
    for (i = 1; i <= *NBE; i++) fscanf(fp, "%d", &((*LBE)[i]));
    for (i = 1; i <= *NBL; i++) fscanf(fp, "%d", &((*LBL)[i]));
    for (i = 1; i <= *NBH; i++) fscanf(fp, "%d", &((*LBH)[i]));

#ifdef DEBUG
    for(i = 1; i <= *NBS; i++) {
        printf("%d ", (*LBS)[i]);
        if((i+1)%6 == 0)
            printf("\n");
    }

    for(i = 1; i < *NBH; i++) {
        printf("%d ", (*LBH)[i]);
        if((i+1)%6 == 0)
            printf("\n");
    }
#endif
    //
    if ((*NTRAEW = (int *) malloc((*NBW + 1) * sizeof(int))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }

    if ((*NTRANS = (int *) malloc((*NBS + 1) * sizeof(int))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }

    if ((*NTRAHL = (int *) malloc((*NBL + 1) * sizeof(int))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }

    for (i = 1; i <= *NBW; i++) fscanf(fp, "%d", &((*NTRAEW)[i]));
    for (i = 1; i <= *NBS; i++) fscanf(fp, "%d", &((*NTRANS)[i]));
    for (i = 1; i <= *NBL; i++) fscanf(fp, "%d", &((*NTRAHL)[i]));

#ifdef DEBUG
    for(i = 1; i <= *NBW; i++) {
        printf("%d ", (*NTRAEW)[i]);
        if((i+1)%6 == 0)
            printf("\n");
    }
    printf("\n");

    for(i = 1; i < *NBS; i++) {
        printf("%d ", (*NTRANS)[i]);
        if((i+1)%6 == 0)
            printf("\n");
    }
    printf("\n");

    for(i = 1; i <= *NBL; i++) {
        printf("%d ", (*NTRAHL)[i]);
        if((i+1)%6 == 0) {
            printf("\n");
        }
    }
    printf("\n");
#endif

    if ((*BS = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }

    if ((*BE = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }

    if ((*BN = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }

    if ((*BW = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }

    if ((*BL = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }

    if ((*BH = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }

    if ((*BP = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }

    if ((*SU = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }

    for (i = (*NINTCI); i <= *NINTCF; i++) {
        fscanf(fp, "%lf", &((*BS)[i]));
        fscanf(fp, "%lf", &((*BE)[i]));
        fscanf(fp, "%lf", &((*BN)[i]));
        fscanf(fp, "%lf", &((*BW)[i]));
        fscanf(fp, "%lf", &((*BL)[i]));
        fscanf(fp, "%lf", &((*BH)[i]));
        fscanf(fp, "%lf", &((*BP)[i]));
        fscanf(fp, "%lf", &((*SU)[i]));
    }

#ifdef DEBUG
    for(i = (*NINTCI); i <= *NINTCF; i++)
        printf("%e %e %e %e %e %e %e %e\n", (*BS)[i], (*BE)[i], (*BN)[i], (*BW)[i], (*BL)[i], (*BH)[i], (*BP)[i], (*SU)[i]);
#endif

    if ((*NBOARD = (int *) malloc((*NINTCF + 1) * sizeof(int))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }

    for (i = (*NINTCI); i <= *NINTCF; i++)
        fscanf(fp, "%d", &((*NBOARD)[i]));

    fclose(fp);
#ifdef DEBUG
    for(i = (*NINTCI); i <= *NINTCF; i++) {
        printf("%d ", (*NBOARD)[i]);
        if((i+1)%6 == 0)
            printf("\n");
    }
#endif
    return 0;
}


int read_formatted(char *fileName, int *NINTCI, int *NINTCF, int *NEXTCI,
                   int *NEXTCF, int ***LCC, double **BS, double **BE, double **BN,
                   double **BW, double **BL, double **BH, double **BP, double **SU,
                   int **NBOARD)
{
    int i;
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", fileName);
        return -1;
    }
    //4 variables in total!!!
    fscanf(fp, "%d", NINTCI);
    fscanf(fp, "%d", NINTCF);
    fscanf(fp, "%d", NEXTCI);
    fscanf(fp, "%d", NEXTCF);

    //allocating LCC
    if ((*LCC = (int**) malloc(6 * sizeof(int*))) == NULL) {
        printf("malloc failed to allocate first dimension of LCC (6)");
        return -1;
    }
    for (i = 0; i < 6; i++) {
        if (((*LCC)[i] = (int *) malloc((*NINTCF + 1) * sizeof(int))) == NULL) {
            printf("malloc(LCC) failed\n");
            return -1;
        }
    }
    //start reading LCC
    //Note that C array index starts from 0 while Fortran starts from 1!
    for (i = (*NINTCI); i <= *NINTCF; i++) {
        fscanf(fp, "%d", &(*LCC)[0][i]);
        fscanf(fp, "%d", &(*LCC)[1][i]);
        fscanf(fp, "%d", &(*LCC)[2][i]);
        fscanf(fp, "%d", &(*LCC)[3][i]);
        fscanf(fp, "%d", &(*LCC)[4][i]);
        fscanf(fp, "%d", &(*LCC)[5][i]);
    }

    // allocate other arrays
    if ((*BS = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }
    if ((*BE = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }
    if ((*BN = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }
    if ((*BW = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }
    if ((*BL = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }
    if ((*BH = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }
    if ((*BP = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }
    if ((*SU = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }

    // read the other arrays
    for (i = (*NINTCI); i <= *NINTCF; i++) {
        fscanf(fp, "%lf", &((*BS)[i]));
        fscanf(fp, "%lf", &((*BE)[i]));
        fscanf(fp, "%lf", &((*BN)[i]));
        fscanf(fp, "%lf", &((*BW)[i]));
        fscanf(fp, "%lf", &((*BL)[i]));
        fscanf(fp, "%lf", &((*BH)[i]));
        fscanf(fp, "%lf", &((*BP)[i]));
        fscanf(fp, "%lf", &((*SU)[i]));
    }

    // read board
    if ((*NBOARD = (int *) malloc((*NINTCF + 1) * sizeof(int))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }

    for (i = (*NINTCI); i <= *NINTCF; i++)
        fscanf(fp, "%d", &((*NBOARD)[i]));

    fclose(fp);
    return 0;
}


int read_formatted_bin(char *fileName, int *NINTCI, int *NINTCF, int *NEXTCI,
                   int *NEXTCF, int ***LCC, double **BS, double **BE, double **BN,
                   double **BW, double **BL, double **BH, double **BP, double **SU,
                   int **NBOARD)
{
    int i;
    int j;
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", fileName);
        return -1;
    }

    //4 variables in total!!!
    fread(NINTCI, sizeof(int), 1, fp);
    fread(NINTCF, sizeof(int), 1, fp);
    fread(NEXTCI, sizeof(int), 1, fp);
    fread(NEXTCF, sizeof(int), 1, fp);

    //allocating LCC
    if ((*LCC = (int**) malloc(6 * sizeof(int*))) == NULL) {
        printf("malloc failed to allocate first dimension of LCC (6)");
        return -1;
    }
    for (i = 0; i < 6; i++) {
        if (((*LCC)[i] = (int *) malloc((*NINTCF + 1) * sizeof(int))) == NULL) {
            printf("malloc(LCC) failed\n");
            return -1;
        }
    }
    //start reading LCC
    //Note that C array index starts from 0 while Fortran starts from 1!
    for (i = (*NINTCI); i <= *NINTCF; i++) {
        for( j = 0; j < 6; ++j)
            fread(&(*LCC)[j][i], sizeof(int), 1,  fp);
    }

    // allocate other arrays
    if ((*BS = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }
    if ((*BE = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }
    if ((*BN = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }
    if ((*BW = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }
    if ((*BL = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }
    if ((*BH = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }
    if ((*BP = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }
    if ((*SU = (double *) malloc((*NEXTCF + 1) * sizeof(double))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }

    // read the other arrays
    for (i = (*NINTCI); i <= *NINTCF; i++) {
        fread(&((*BS)[i]), sizeof(double), 1, fp);
        fread(&((*BE)[i]), sizeof(double), 1, fp);
        fread(&((*BN)[i]), sizeof(double), 1, fp);
        fread(&((*BW)[i]), sizeof(double), 1, fp);
        fread(&((*BL)[i]), sizeof(double), 1, fp);
        fread(&((*BH)[i]), sizeof(double), 1, fp);
        fread(&((*BP)[i]), sizeof(double), 1, fp);
        fread(&((*SU)[i]), sizeof(double), 1, fp);
    }

    // read board
    if ((*NBOARD = (int *) malloc((*NINTCF + 1) * sizeof(int))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }

    for (i = (*NINTCI); i <= *NINTCF; i++)
        fread(&((*NBOARD)[i]), sizeof(int), 1, fp);

    fclose(fp);
    return 0;
}
