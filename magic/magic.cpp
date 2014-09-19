#include <fstream>

using namespace std;

int main(int argc, char** argv){
    ifstream fin(argv[1]);
    int num;
    fin >> num;
    ofstream fo(argv[2]);
    int data[16];
    int data2[16];
    for(int i=0;i<num;i++){
        int r1, r2;
        fin>> r1;
        for(int j=0;j<16;j++){
            fin >> data[j];
        }
        fin >> r2;
        for(int j=0;j<16;j++){
            fin >> data2[j];
        }
        int ret=0, retv=0;
        bool flag = false;
        fo << "Case #" << i+1 << ": ";
        for(int j=0;j<4;j++){
            int t = data[(r1-1)*4+j];
            for(int jj=0;jj<4;jj++){
                if(t==data2[(r2-1)*4+jj]){
                    ret++;
                    if(ret > 1){
                        fo << "Bad magician!" << endl;
                        flag = true;
                        break;
                    }
                    retv = t;
                }
            }
            if(flag){
                    break;
            }
        }
        if(ret == 0){
            fo << "Volunteer cheated!" << endl;
        }
        else if(ret==1){
            fo << retv << endl;
        }
    }
    fin.close();
    fo.close();
}

