#include <stdio.h>
#include <math.h>

double pow(double x, double y);
double hyp(float a, float b);
int linesInFile(char fName[]);
int main(int argc, char *argv[])
{
    double a;
    double b;
    int numLines;
    char fName[]="aAndB.txt";
    FILE * fp;
    //printf("Enter A: ");
    //scanf("%f", &a);
    // printf("Enter B: ");
    //scanf("%f", &b);
    numLines = linesInFile(fName);
    fp = fopen (fName, "r");
    double c[numLines];
    int i;
    char fChar;
    for (i=0; i<numLines; i=i+1){//read a and b, calculate c and store in c[] array
        fscanf(fp, "%lf", &a);
        fscanf(fp, "%lf", &b);
        c[i]=hyp(a, b);
    }
    fclose(fp);
    fp = fopen (fName, "w");
    for (i=0; i<numLines; i=i+1){//append c contents to each file line
        for (fChar=getc(fp); fChar!=EOF; fChar=getc(fp)){ //scan to the end of each line
            if (fChar=="\n"){
                //append here
                fprintf(fp, "%f", c[i]);
            }
        }
    }
    // fprintf(fp, "%f\n", a);
    // fprintf(fp, "%f\n", b);
    // double c = hyp(a,b);
    // printf("%f is the hypotenuse.", c);
}

int linesInFile(char fName[]){
    FILE * fp;
    int count = 0;
    char c;
    fp = fopen(fName, "r");
    if (fp==NULL){
        printf("Could not open file: %s", fName);
        return 0;
    }
    for (c=getc(fp); c!=EOF; c=getc(fp)){
        if ((char)c=="\n"){
            count += 1;
        }
    }
    fclose(fp);
    return count;
}

double hyp(float a, float b){
    double c;
    double asq;
    double bsq;
    asq=pow(a, 2);
    bsq=pow((double)b, (double)2);
    c = pow(asq+bsq, 0.5);
    return c;
}