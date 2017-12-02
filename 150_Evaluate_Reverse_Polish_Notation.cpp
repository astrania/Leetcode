/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.size() == 1) return atoi(tokens[0].c_str());
        
        stack<int> s;
        
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") 
　　　　　　　{
                s.push(atoi(tokens[i].c_str()));
            } else {
                int m = s.top();
                s.pop();
                int n = s.top();
                s.pop();
                if (tokens[i] == "+") s.push(n + m);
                if (tokens[i] == "-") s.push(n - m);
                if (tokens[i] == "*") s.push(n * m);
                if (tokens[i] == "/") s.push(n / m);
            }
        }
        
        return s.top();
    }
};
