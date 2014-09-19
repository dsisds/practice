#include <iostream>

#define INT_MAX 2147483647
#define INT_MIN -2147483648
using namespace std;

int is_mul_overflow(int a, int b) {
		if(a==0) return false;
        return INT_MAX / a < b;
}

bool is_add_overflow(int a, int b){
    return a > INT_MAX - b;
}
int atoi_t(const char *str) {
        int ret = 0;
        const char* s = str;
        bool started = false;
        //bool sign = false;
        bool pos = true;
        if(str == NULL){
            return 0;
        }
        while(*s != '\0'){
            if(*s == ' ' && started == false){
                s++;
				cout << "space" << endl;
                continue;
            }
            if(!started){
                if(*s == '-' || *s == '+'){
                    if(*s == '-'){
                        pos = false;
                    }else{
                        pos = true;
                    }
                    //sign = true;
                    started = true;
					cout << "started with sign "<< *s << endl;
                }else if(*s >= '0' && *s <= '9'){
				cout << "stared with number " << *s - '0' << endl;
                    started = true;
                    ret += *s - '0';
                }else{
                    //pos = true;
                    return 0;
                }
                s++;
            }else{
                if(*s >= '0' && *s <='9'){
					cout << "num:" << *s-'0' << " curret:" << ret << endl;
					if(is_mul_overflow(ret, 10)){
                        if(pos){
                            return INT_MAX;
                        }else{
                            return INT_MIN;
                        }
                    }
					cout << "add" << endl;
                    if(is_add_overflow(ret*10, *s-'0')){
                        if(pos){
                            return INT_MAX;
                        }else{
                            return INT_MIN;
                        }
                    }
                    ret = ret*10 + (*s-'0');
                }else{
                    break;
                }
                s++;
            }
        }
		cout << "get number" << endl;
        if(pos){
            return ret;
        }else{
            return -ret;
        }
    }
	
	int main(int argc, char** argv){
		cout << atoi_t(argv[1]) << endl;
		}