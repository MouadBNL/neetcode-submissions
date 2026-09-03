class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int j = 0;
        int cnt = 0;
        for(int s: students) q.push(s);

        while(!q.empty()) {
            int student = q.front();
            q.pop();
            if(student == sandwiches[j]) {
                j++;
                cnt=0;
            } else {
                q.push(student);
                cnt++;
            }

            if(cnt > students.size()) break;
        }


        return q.size();
    }
};