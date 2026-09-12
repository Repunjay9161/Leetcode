class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
       int count =0;
       int c =brokenLetters.length();
       string s="";
       for(int i=0;i<text.size()+1;i++){
        if(text[i]==' '||i==text.length()){
            for(char ch : brokenLetters  ){
                if(s.contains(ch)){
                    c--;
                    break;
                }
            }
            if(c==brokenLetters.length()){
                count++;
            }
            else{ 
                c=brokenLetters.length();}
            s="";
        }
        else{
           s+=text[i];
        }
       }
       return count; 
    }
};