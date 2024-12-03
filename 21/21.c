#include<stdio.h>
#include<math.h>

#define NDAT 20
#define PRECISION 0.1

int main(void){
        FILE*fp;
        float t[NDAT],x[NDAT],s[NDAT],y[NDAT];
        float para_v,para_x0;
        float err_v,err_x0;
        int ih;

        if((fp=fopen("u.dat","r"))!=NULL){
                for(ih=0;ih<NDAT;ih++){
                        fscanf(fp,"%f %f %f %f %f",&t[ih],&x[ih],&s[ih],&s[ih]);
                }
                fclose(fp);
        }
        else{
                printf("FILE OPEN ERROR\n");
                return -1;
        }

        float SUM_T2 =0, SUM_T =0, SUM_X =0, SUM_TX =0,SUM_1 =0;
        int i;
        for(i=0;i<NDAT;i++){
                SUM_T2 += t[i] * t[i] / (s[i] * s[i]);
                SUM_T += t[i] / (s[i] * s[i]);
                SUM_X += x[i] / (s[i] * s[i]);
                SUM_TX += t[i] * x[i] / (s[i] * s[i]);
                SUM_1 += 1.0 / (s[i] * s[i]); 
        }
        para_v = (SUM_TX * SUM_1 - SUM_X * SUM_T) / (SUM_T2 * SUM_1 - SUM_T * SUM_T );
        para_x0 = (SUM_T2 * SUM_X - SUM_TX * SUM_T) / (SUM_T2 * SUM_1 - SUM_T * SUM_T);

        err_v = sqrt(SUM_1 / (SUM_T2 * SUM_1 - SUM_T * SUM_T));
        err_x0 = sqrt(SUM_T2 / (SUM_T2 * SUM_1 - SUM_T * SUM_T));

        printf("v = %f, x0 = %f\n",para_v,para_x0);
        printf("Error in v = %f, Error in x0 = %f\n",err_v,err_x0);

        return 0;
}


