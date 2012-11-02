#ifndef XREAD_H_
#define XREAD_H_

int read_long_formatted(char *fileName,
                        int *NINTCI, int *NINTCF, int *NEXTCI, int *NEXTCF,
                        int *NBCESI, int *NBCESF, int *NBCEWI, int *NBCEWF, int *NBCELI, int *NBCELF,
                        int *NSDIR, int *NEDIR, int *NI, int *NJ, int *NK,
                        int *NDIR1, int *NDIR2, int *NDIR3,
                        int *NBS, int *NBW, int *NBL, int *NBN, int *NBE, int *NBH, int *IDIM, int *INCR,
                        int ***LCC,
                        int **LBS, int **LBN, int **LBW, int **LBE, int **LBL, int **LBH,
                        int **NTRAEW, int **NTRANS, int **NTRAHL, int **NBOARD,
                        double **BS, double **BE, double **BN, double **BW, double **BL, double **BH, double **BP, double **SU
                       );

int read_formatted(char *fileName,
                   int *NINTCI, int *NINTCF, int *NEXTCI, int *NEXTCF,
                   int ***LCC,
                   double **BS, double **BE, double **BN, double **BW, double **BL, double **BH, double **BP, double **SU,
                   int **NBOARD
                  );


int read_formatted_bin(char *fileName,
                   int *NINTCI, int *NINTCF, int *NEXTCI, int *NEXTCF,
                   int ***LCC,
                   double **BS, double **BE, double **BN, double **BW, double **BL, double **BH, double **BP, double **SU,
                   int **NBOARD
                  );
#endif /* XREAD_H_ */

