#include<stdio.h>
#include<math.h>
#define NDAT 21
#define dv 0.001
#define PRECISION 0.1
#define vmin 4.00003

float func(float x,float v,float x0);
float calc_chi2(float [],float x[],float s[],float a,float b );
float dcdv(float t[],float x[],float s[],float a,float b);

int main(void){
        FILE*fp;
        float t[NDAT],x[NDAT],s[NDAT],a,b;
        int ih;
        if((fp=fopen("u.dat","r"))!=NULL){
                for(ih=0;ih<NDAT;ih++){
                        fscanf(fp,"%f %f %f %f %f",&t[ih],&x[ih],&a,&b,&s[ih]);
                        s[ih]=PRECISION;
                }
                fclose(fp);
        }
        float par_v=2.2, par_x0=3.4;
        float d2cdv2,err;
        d2cdv2=(dcdv(t,x,s,vmin+dv,par_x0)-dcdv(t,x,s,vmin,par_x0))/dv;
        err=sqrt(2/d2cdv2);
        printf("Solution = %f +- %f\n",vmin,err-1);
        return 0;
}

float dcdv(float t[],float x[],float s[],float a,float b)
{
        float dcdv=0;
        dcdv=(calc_chi2(t,x,s,a+dv,b)-calc_chi2(t,x,s,a,b))/dv;
        return dcdv;
}

float calc_chi2(float t[],float x[],float s[],float a,float b)
{
        float chi2;
        int i;
        for(i=0;i<NDAT;i++){
                chi2+=(x[i]-func(t[i],a,b))* (x[i]-func(t[i],a,b)) / (s[i] * s[i]);
        }
        return chi2;
}

float func(float t,float v,float x0)
{
        float x=v*t + x0;
        return x;
}
