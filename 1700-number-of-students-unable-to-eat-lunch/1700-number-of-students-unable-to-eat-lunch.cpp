class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int s_count=students.size(),c_sand=0,sq_sand=0;
        c_sand=count(students.begin(),students.end(),0);
        sq_sand=count(students.begin(),students.end(),1);
        for(int i=0;i<students.size();i++){
            if(sandwiches[i]==0){
                if(c_sand>0){
                    c_sand--;
                    s_count--;
                }
                else return s_count;
            }
            else{
                if(sq_sand>0){
                    sq_sand--;
                    s_count--;
                }
                else return s_count;
            }
        }
        return s_count;
    }
};