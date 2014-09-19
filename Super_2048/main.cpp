#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char** argv){
    ifstream fin(argv[1]);
    int num;
    fin >> num;
    for(int i=0;i<num;i++){
        int n;
        string direction;
        fin >> n >> direction;
        vector< vector<int> > data;
        for(int j=0;j<n;j++){
            vector<int> dt(n,0);
            for(int k=0;k<n;k++){
                fin >> dt[k];
            }
            data.push_back(dt);
        }
		/*cout << "Case #" << i+1 << ":" << endl;
        for(int j=0;j<n;j++){
            for(int k=0;k<n-1;k++){
                cout << data[j][k] << " ";
            }
            cout << data[j][n-1] << endl;
        }*/
        if(direction == "up"){
            for(int j=0;j<n;j++){
                int pr=0,pw = 0;
                bool flag = false;
                while(pr<n){
                    if(data[pr][j] == 0){
                        pr++;
                    }else{
                        data[pw][j] = data[pr][j];
                        pr++;
                        pw++;
                    }
                }
                while(pw < n){
                    data[pw][j] = 0;
                    pw++;
                }
                pr=0;pw=0;
                while(pr<n-1){
                    if(data[pr][j] == data[pr+1][j]){
                        data[pw][j] = 2*data[pr][j];
                        pr+=2;
                        pw++;
                        flag = true;
                    }else{
                        data[pw][j] = data[pr][j];
                        pr++;
                        pw++;
                    }
                }
                if(pr < n){
                if(data[pr][j] !=0){
                    data[pw][j] = data[pr][j];
                    pw++;
                }
                }
                if(flag){
                    while(pw<n){
                        data[pw][j] = 0;
                        pw++;
                    }
                }
            }
        }else if(direction == "down"){
            for(int j=0;j<n;j++){
                int pr =n-1, pw = n-1;
                bool flag = false;
                while(pr>=0){
                    if(data[pr][j]==0){
                        pr--;
                    }else{
                        data[pw][j] = data[pr][j];
                        pw--;
                        pr--;
                    }
                }
                while(pw>=0){
                    data[pw][j]=0;
                    pw--;
                }
                pw=n-1;
                pr=n-1;
                while(pr>0){
                    if(data[pr][j] == data[pr-1][j]){
                        data[pw][j] = data[pr][j]+data[pr][j];
                        pr -= 2;
                        pw--;
                        flag = true;
                    }else{
                        data[pw][j] = data[pr][j];
                        pr--;
                        pw--;
                    }
                }
                if(pr>=0){
                if(data[pr][j] !=0){
                    data[pw][j] = data[pr][j];
                    pw--;
                }}
                if(flag){
                    while(pw>=0){
                        data[pw][j] = 0;
                        pw--;
                    }
                }
            }
        }else if(direction == "left"){
            for(int j=0;j<n;j++){
                int pr=0;int pw=0;
                bool flag = false;
                while(pr<n){
                    if(data[j][pr]==0){
                        pr++;
                    }else{
                        data[j][pw] = data[j][pr];
                        pw++;
                        pr++;
                    }
                }
                while(pw<n){
                    data[j][pw]=0;
                    pw++;
                }
                pw=0;
                pr=0;
				//cout << "Case #" << i+1 << ":" << endl;
        /*(for(int jj=0;jj<n;jj++){
            for(int kk=0;kk<n-1;kk++){
                cout << data[jj][kk] << " ";
            }
            cout << data[jj][n-1] << endl;
        }*/
                while(pr < n-1){
                    if(data[j][pr]==data[j][pr+1]){
                        data[j][pw] = data[j][pr]+data[j][pr];
                        pw++;
                        pr+=2;
                        flag = true;
                    }else{
                        data[j][pw] = data[j][pr];
                        pw++;
                        pr++;
                    }
                }
                if(pr<n){
                if(data[j][pr] !=0){
                    data[j][pw] = data[j][pr];
                    pw--;
                }}
                if(flag){
                    while(pw<n){
                        data[j][pw]=0;
                        pw++;
                    }
                }
            }
        }else if(direction == "right"){
            for(int j=0;j<n;j++){
                int pr=n-1;int pw=n-1;
                bool flag = false;
                while(pr>=0){
                    if(data[j][pr]==0){
                        pr--;
                    }else{
                        data[j][pw]=data[j][pr];
                        pw--;
                        pr--;
                    }
                }
                while(pw>=0){
                    data[j][pw]=0;
                    pw--;
                }
                pw=n-1;
                pr=n-1;
                while(pr>0){
                    if(data[j][pr] == data[j][pr-1]){
                        data[j][pw] = data[j][pr]+data[j][pr];
                        pr-=2;
                        pw--;
                        flag = true;
                    }else{
                        data[j][pw] = data[j][pr];
                        pr--;
                        pw--;
                    }
                }
                if(pr>=0){
                if(data[j][pr]!=0){
                    data[j][pw] = data[j][pr];
                    pw--;
                }}
                if(flag){
                    while(pw>=0){
                        data[j][pw] = 0;
                        pw--;
                    }
                }
            }
        }
        cout << "Case #" << i+1 << ":" << endl;
        for(int j=0;j<n;j++){
            for(int k=0;k<n-1;k++){
                cout << data[j][k] << " ";
            }
            cout << data[j][n-1] << endl;
        }
    }
    return 0;
}


