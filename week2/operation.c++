class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int output=0;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="X++"||operations[i]=="++X"){
                output++;
            }
            else {
                output--;
            }
        }
        return output;
    }
};