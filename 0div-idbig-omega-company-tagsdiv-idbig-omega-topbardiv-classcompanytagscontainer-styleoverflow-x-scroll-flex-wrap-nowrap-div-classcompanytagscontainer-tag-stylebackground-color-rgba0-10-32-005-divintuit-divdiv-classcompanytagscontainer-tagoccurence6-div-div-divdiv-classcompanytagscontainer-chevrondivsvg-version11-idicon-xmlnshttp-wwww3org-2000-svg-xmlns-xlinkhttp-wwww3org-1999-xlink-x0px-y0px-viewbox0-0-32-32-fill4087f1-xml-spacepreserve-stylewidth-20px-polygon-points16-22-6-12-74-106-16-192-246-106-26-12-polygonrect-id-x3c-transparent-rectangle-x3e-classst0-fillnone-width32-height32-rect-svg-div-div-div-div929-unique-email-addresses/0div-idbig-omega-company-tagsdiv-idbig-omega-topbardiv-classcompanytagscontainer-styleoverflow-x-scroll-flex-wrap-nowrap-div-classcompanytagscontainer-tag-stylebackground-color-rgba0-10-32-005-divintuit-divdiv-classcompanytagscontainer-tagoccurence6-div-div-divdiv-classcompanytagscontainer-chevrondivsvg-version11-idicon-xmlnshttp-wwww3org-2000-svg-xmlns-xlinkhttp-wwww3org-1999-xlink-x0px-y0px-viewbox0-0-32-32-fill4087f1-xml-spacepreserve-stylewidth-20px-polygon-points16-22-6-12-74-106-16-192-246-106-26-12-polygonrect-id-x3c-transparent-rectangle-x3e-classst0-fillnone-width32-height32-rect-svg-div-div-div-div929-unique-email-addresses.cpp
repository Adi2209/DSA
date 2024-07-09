class Solution {
private:
    void checkMail(string mail, unordered_set<string>& st){
        string front;
        string back;
        bool frontEnd = false;
        bool backStart = false;
        int size = mail.size();
        for(int ind = 0;ind<size;ind++){
            if(mail[ind] == '+'){
                frontEnd = true;
            }
            if(mail[ind] == '.' && backStart == true){
                back+=mail[ind];
                continue;
            }
             if(mail[ind] == '.'){
                continue;
            }
             if(mail[ind]=='@'){
                backStart = true;
                frontEnd=true;
            }
            if(frontEnd == false) front+=mail[ind];
            if(backStart == true) back+=mail[ind];
            
        }
        string finalMail = front  +back;
        cout<<"Front : "<<front<<"  Back:  "<<back<<endl;
        cout<<"Final Mail : "<<finalMail<<endl;
        st.insert(finalMail);
    }
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(auto &mail:emails){
            checkMail(mail,st);
        }
        return st.size();
    }
};