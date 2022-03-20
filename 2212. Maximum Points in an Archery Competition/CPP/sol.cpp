public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        
        long long s= 0;
        
        long long mx=INT_MIN;
        vector<int> ans(12); 
        
        rep(i, (1<<12)+1){
            long long ns=0, flag=0, g=numArrows;
            
            rep(j,12){
                
                if((i & (1<<j))) {
                    long long x= aliceArrows[j]+1;
                          g-=x;
                          ns+=j;
                        if(g<0) { flag=1; break;}

                }
            }
            
            if(flag==0 && ns>mx ){
                rep(k,12) ans[k]=0;
                rep(j,12){
                     if((i & (1<<j))){
                         ans[j]=  aliceArrows[j]+1;
                     }
                }
                if(g>0) ans[0]+=g;
                mx=ns;
            }
         }
        
        return ans;
        
    }