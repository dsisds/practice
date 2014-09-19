//#include <math>
#include <fstream>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv){
    ifstream fin(argv[1]);
    //ofstream fo(argv[2]);
    FILE *fo = fopen(argv[2], "w");
    int N;
    fin >> N;
    double C, F, X;

    for(int i=0;i<N;i++){
        fin >> C >> F >> X;
        //fo << "Case #"<< i+1 << ": ";
        fprintf(fo, "Case #%d: ", i+1);
        if(X <=C){
            //fo << setpxecision(10)<<X / 2 << endl;
            fprintf(fo, "%.7f\n", X/2);
            continue;
        }
        double t=0, old_t = -1;
        old_t = X / 2;
        double ft = 0 ;
        int n=1;
        ft = C /2;
        t = X / (2+F)+ft;
        while(1){
            if(t >= old_t){
                //fo << setprecision(10) << old_t << endl;
                fprintf(fo, "%.7f\n", old_t); 
                break;
            }
            n++;
            old_t = t;
            ft = ft + C/(2+(n-1)*F);
            t = X/(2+n*F)+ft;
        }
        cout << "number Farms(" << i+1 << "):" << n << endl;
    }
    fin.close();
    fclose(fo);
}
