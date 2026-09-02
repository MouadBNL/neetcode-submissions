class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> s;
        int sum = 0;

        for(string c:operations) {
            if(c == "C"){
                sum -= s.back();
                s.pop_back();
            }
            else if(c == "D") {
                sum += s.back()*2;
                s.push_back(s.back()*2);
            } else if (c == "+") {
                int k = s.back() + s[s.size()-2];
                s.push_back(k);
                sum+=k;
            } else {
                int k = std::atoi(c.c_str());
                sum+=k;
                s.push_back(k);
            }

            std::cout << "Sum: " << sum << ": ";
            for(int j : s) std::cout << j << ", ";
            std::cout << "\n";
        }


        for(int i : s) {
            std::cout << i << ", ";
        }
        return sum;
    }
};