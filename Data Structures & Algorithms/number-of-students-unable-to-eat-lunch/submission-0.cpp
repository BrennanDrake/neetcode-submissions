class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int num = students.size();
        queue<int> qu;

        for(int student:students){
            qu.push(student);
        }
        int rem = num;

        for(int sandwich:sandwiches){
            int count = 0;
            while(count<num && qu.front() != sandwich){
                qu.push(qu.front());
                qu.pop();
                count++;
            }
            if(qu.front() == sandwich){
                qu.pop();
                rem--;
            } else{
                break;
            }
        }
        return rem;
    }
};