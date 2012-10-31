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
    fread( "%d", NINTCI);
    fread( "%d", NINTCF);
    fread( "%d", NEXTCI);
    fread( "%d", NEXTCF);
    fread( "%d", NBCESI);
    fread( "%d", NBCESF);
    fread( "%d", NBCEWI);
    fread( "%d", NBCEWF);
    fread( "%d", NBCELI);
    fread( "%d", NBCELF);
    fread( "%d", NSDIR);
    fread( "%d", NEDIR);
    fread( "%d", NI);
    fread( "%d", NJ);
    fread( "%d", NK);
    fread( "%d", NDIR1);
    fread( "%d", NDIR2);
    fread( "%d", NDIR3);
    fread( "%d", NBS);
    fread( "%d", NBW);
    fread( "%d", NBL);
    fread( "%d", NBN);
    fread( "%d", NBE);
    fread( "%d", NBH);
    fread( "%d", IDIM);
    fread( "%d", INCR);

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
        fread( "%d", &(*LCC)[0][i]);
        fread( "%d", &(*LCC)[1][i]);
        fread( "%d", &(*LCC)[2][i]);
        fread( "%d", &(*LCC)[3][i]);
        fread( "%d", &(*LCC)[4][i]);
        fread( "%d", &(*LCC)[5][i]);
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

    for (i = 1; i <= *NBS; i++) fread( "%d", &((*LBS)[i]));
    for (i = 1; i <= *NBN; i++) fread( "%d", &((*LBN)[i]));
    for (i = 1; i <= *NBW; i++) fread( "%d", &((*LBW)[i]));
    for (i = 1; i <= *NBE; i++) fread( "%d", &((*LBE)[i]));
    for (i = 1; i <= *NBL; i++) fread( "%d", &((*LBL)[i]));
    for (i = 1; i <= *NBH; i++) fread( "%d", &((*LBH)[i]));

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

    for (i = 1; i <= *NBW; i++) fread( "%d", &((*NTRAEW)[i]));
    for (i = 1; i <= *NBS; i++) fread( "%d", &((*NTRANS)[i]));
    for (i = 1; i <= *NBL; i++) fread( "%d", &((*NTRAHL)[i]));

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
        fread( "%lf", &((*BS)[i]));
        fread( "%lf", &((*BE)[i]));
        fread( "%lf", &((*BN)[i]));
        fread( "%lf", &((*BW)[i]));
        fread( "%lf", &((*BL)[i]));
        fread( "%lf", &((*BH)[i]));
        fread( "%lf", &((*BP)[i]));
        fread( "%lf", &((*SU)[i]));
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
        fread( "%d", &((*NBOARD)[i]));

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
    fread( "%d", NINTCI);
    fread( "%d", NINTCF);
    fread( "%d", NEXTCI);
    fread( "%d", NEXTCF);

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
        fread( "%d", &(*LCC)[0][i]);
        fread( "%d", &(*LCC)[1][i]);
        fread( "%d", &(*LCC)[2][i]);
        fread( "%d", &(*LCC)[3][i]);
        fread( "%d", &(*LCC)[4][i]);
        fread( "%d", &(*LCC)[5][i]);
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
        fread( "%lf", &((*BS)[i]));
        fread( "%lf", &((*BE)[i]));
        fread( "%lf", &((*BN)[i]));
        fread( "%lf", &((*BW)[i]));
        fread( "%lf", &((*BL)[i]));
        fread( "%lf", &((*BH)[i]));
        fread( "%lf", &((*BP)[i]));
        fread( "%lf", &((*SU)[i]));
    }

    // read board
    if ((*NBOARD = (int *) malloc((*NINTCF + 1) * sizeof(int))) == NULL) {
        printf("malloc() failed\n");
        return -1;
    }

    for (i = (*NINTCI); i <= *NINTCF; i++)
        fread( "%d", &((*NBOARD)[i]));

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
