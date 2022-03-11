string longestPalindrome(string s) {
        
        int an1=0,an2=0;
        int ans = 0;
        
        int n = s.length();
        
        for(int k=1;k<n;k++)
        {
            int i=k-1,j = k+1;
            int c = 1;
            
            
            while(i>=0 && j<n)
            {
                if(s[i]==s[j])
                {
                    c+=2;
                    i--;
                    j++;
                }
                else{
                    break;
                }
            }
            
            if(ans<c)
            {
                ans = c;
                if(i>=0)
                {
                    an1 = i+1;
                }
                else{
                    an1 = 0;
                }
                if(j<n)
                {
                    an2 = j-1;
                }
                else{
                    an2 = n-1;
                }
            }
            if(s[k]==s[k-1])
            {
                c = 2;
                i=k-2;
                j = k+1;
                while(i>=0 && j<n)
                {
                    if(s[i]==s[j])
                    {
                        c+=2;
                        i--;
                        j++;
                    }
                    else{
                        break;
                    }
                }

                if(ans<c)
                {
                    ans = c;
                    if(i>=0)
                    {
                        an1 = i+1;
                    }
                    else{
                        an1 = 0;
                    }
                    if(j<n)
                    {
                        an2 = j-1;
                    }
                    else{
                        an2 = n-1;
                    }
                }

            }

            
            
        }
        // cout<<ans<<endl;
        if(ans==0)
        {
            for(int i=1;i<n;i++)
            {
                if(s[i]==s[i-1])
                {
                    an1 = i-1;
                    an2 = i;
                    break;
                }
            }
        }
        string anss;
        for(int i=an1;i<=an2;i++)
        {
            anss+=s[i];
        }
        return anss;
        
        
        
        
        
        
    }
