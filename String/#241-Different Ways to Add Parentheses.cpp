//M1
//Using simulation and intuition
//Faster than 46.04% (4ms)

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        for(int i=0; i<expression.size(); i++){
            char curr = expression[i];
            if(curr == '+' or curr == '-' or curr == '*'){
                vector<int> s1 = diffWaysToCompute(expression.substr(0,i));
                vector<int> s2 = diffWaysToCompute(expression.substr(i+1));
                for(int &num1 : s1){
                    for(int &num2 : s2){
                        if(curr == '+') res.push_back(num1 + num2);
                        else if(curr == '-') res.push_back(num1 - num2);
                        else if(curr == '*') res.push_back(num1 * num2);
                    }
                }
            }
        }
        if(res.empty()) res.push_back(stoi(expression));
        return res;
    }
};
