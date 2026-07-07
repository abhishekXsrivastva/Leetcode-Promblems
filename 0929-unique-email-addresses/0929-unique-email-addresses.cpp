class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;
        for(auto& email : emails){
            string normalized = "";
            int i = 0;
            while(email[i] != '@'){
                if(email[i] == '+'){
                    while(email[i] != '@'){
                        i++;
                    }
                    break;
                }
                 if(email[i] != '.'){
                     normalized += email[i];
                 } 
                 i++;
            }
             normalized += email.substr(i);
             uniqueEmails.insert(normalized);
           
        }
          return uniqueEmails.size();
    }
};