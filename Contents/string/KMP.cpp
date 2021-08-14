void failure(string s, int len, int *f)
{    
    f[ 0 ] = -1;
    for(int i = 1; i < len; i++)
    {
        int k = f[ i-1 ];

        while(s[i] != s[k+1] && k >= 0)
            k = f[k];
        
        if(s[i] == s[k+1])f[i] = k+1;
        else f[i] = -1;
    }
}

int compare(string big, string little, int *f)
{
    int Blen = big.length(), Llen = little.length();
    int i = 0, j = 0;

    while(i < Blen && j < Llen)
    {
        if(big[i] == little[j])
        {
            i++;
            j++;
        }
        else if(j == 0)i++;
        else j = f[j-1] + 1;
    }

    if(j == Llen)return 1;
    else return 0;
}