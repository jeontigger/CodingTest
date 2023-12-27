class Solution {
public:
    void intToBit(int num){
        for(int i =0; i<8;i++){
            cout << bool(num & (1 << 7 - i));
        }
        cout << endl;
    }
    bool validUtf8(vector<int>& data) {
        int first = data[0];
        bool utf0 = first & 1 << 7 ;
        int cnt = 0;
        // for(int i = 0; i<data.size();i++){
        //     intToBit(data[i]);
        // }
        for(int i =0; i<data.size();i++){
            int num = data[i];
            if(cnt == 0){
                if(0 == (num & (1 << 7))){
                    cnt = 0;
                    continue;
                }
                else if(6 == ((num >> 5) & 7)){
                    cnt = 1;
                    continue;
                }
                else if(14 == ((num >> 4) & 15)){
                    cnt = 2;
                    continue;
                }
                else if(30 == ((num >> 3) & 31)){
                    cnt = 3;
                    continue;
                }
                else
                    return false;
            }else{
                if(2 == ((num >> 6) & 3)){
                    cnt--;
                }else{
                    return false;
                }
            }

        }

        if(cnt == 0){
            return true;
        }else{
            return false;
        }

        // if(data.size()==1){
        //     if(utf0){
        //         return false;
        //     }else{
        //         return true;
        //     }
        // }

        // int second = data[1];
        // if(data.size()==2){
        //     if(6 == ((first >> 5) & 6) && 2 == ((second >> 6) & 2)){
        //         return true;
        //     }else{
        //         return false;
        //     }
        // }

        // int third = data[2];
        // if(data.size() == 3){
        //     if(6 == ((first >> 5) & 6) && 2 == ((second >> 6) & 2) && 2 == ((third >> 6) & 2)){
        //         return true;
        //     }else{
        //         return false;
        //     }
        // }



    }
};