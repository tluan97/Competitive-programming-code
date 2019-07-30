#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

const string DIR_NAME = "test_";
const string TEST_NAME = "PLUS";
const string INP_NAME = ".INP";
const string OUT_NAME = ".OUT";
const int NUM_TEST = 10;

string number(int i){
    if (i>=10) return to_string(i);
    return "0"+to_string(i);
}
bool copyFile(const char *SRC, const char* DEST)
{
    std::ifstream src(SRC, std::ios::binary);
    std::ofstream dest(DEST, std::ios::binary);
    dest << src.rdbuf();
    return src && dest;
}
void luan(){
    for (int i=0;i<NUM_TEST;i++){
        CreateDirectory((DIR_NAME+number(i)).c_str(), NULL);
        system((TEST_NAME+".exe").c_str());
        system((TEST_NAME+"_gen.exe").c_str());
        copyFile(
            (TEST_NAME+INP_NAME).c_str(),
            (DIR_NAME+number(i)+"\\"+TEST_NAME+INP_NAME).c_str()
        );
        copyFile(
            (TEST_NAME+OUT_NAME).c_str(),
            (DIR_NAME+number(i)+"\\"+TEST_NAME+OUT_NAME).c_str()
        );
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    luan();
    return 0;
}