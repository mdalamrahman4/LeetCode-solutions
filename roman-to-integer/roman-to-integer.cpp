class Solution {
public:
    int romanToInt(string s) {
    long long no=0;
      for(int i=0;s[i]!='\0';i++)
      {
          if(i!=0 && s[i-1]=='I')
          {
              if(s[i]=='V' || s[i]=='X')
              {
                  no=no-2;
              }
          }
          else if(i!=0 && s[i-1]=='X')
          {
              if(s[i]=='L' || s[i]=='C')
              {
                  no=no-20;
              }
          }
          else if(i!=0 && s[i-1]=='C')
          {
              if(s[i]=='D' || s[i]=='M')
              {
                  no=no-200;
              }
          }
          if(s[i]=='I')
              no=no+1;
          else if(s[i]=='V')
              no=no+5;
          else if(s[i]=='X')
              no=no+10;
          else if(s[i]=='L')
              no=no+50;
          else if(s[i]=='C')
              no=no+100;
          else if(s[i]=='D')
              no=no+500;
          else if(s[i]=='M')
              no=no+1000;
      }

        return no;
    }
};