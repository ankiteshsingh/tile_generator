#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


extern "C" {
    int* get_offset(int w, int h, int nw, int nh, int offset_max);
}
int* get_offset(int w, int h, int nw, int nh, int offset_max){
    int* arr=new int[h*w];
    srand (time(NULL));
    int* wo = new int[nw]();
    int* wh = new int[nh]();
    wo[0]=0;wo[nw-1]=w-1;
    wh[0]=0;wh[nh-1]=h-1;
    for(int i=1;i<nw-1;i++) wo[i]= 1+rand()%(w-2);sort(wo,wo+nw);
    for(int i=1;i<nh-1;i++) wh[i]= 1+rand()%(h-2);sort(wh,wh+nh);
    // for(int i=0;i<nw;i++)cout<<wo[i]<<" ";
    // cout<<endl;
    // for(int i=0;i<nh;i++)cout<<wh[i]<<" ";
    // cout<<endl;
    unordered_map<int, int> map;
    int cnt=0;
    for(int j=0;j<nh-1;j++){
        for(int i=0;i<nw-1;i++){
            map.insert({wh[j] * w + wo[i],-1*offset_max/2 + rand()% offset_max});//
        }
    }
    // for(auto i:map){
    //     cout<<"h: "<<i.first/nw<<" w: "<<i.first%nw <<" "<<i.second<<endl;
    // }
    bool row_flag=false;
    for(int j=0;j<h;j++){
        for(int i=0;i<w;i++){
            int idx=j*w +i;
            if(map.find(idx)!=map.end()){
                arr[idx]=map[idx];
                row_flag=true;
            }
            else{
                if(row_flag) arr[idx] = arr[idx-1];
                else arr[idx] = arr[(j-1)*w +i];
            }
            // printf("%2d ",arr[idx]);
        }
        row_flag=false;
        // cout<<endl;
    }
    delete[] wo;delete[] wh;
    return arr;
}

