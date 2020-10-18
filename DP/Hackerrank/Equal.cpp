//https://www.hackerrank.com/challenges/equal/problem?isFullScreen=true
int equal(vector<int> a) {
    int mn = *min_element(a.begin(),a.end());
    int numops = 0;
    int n = a.size();
    for(int i=0;i<n;i++){
        int nChocs = floor((a[i]-mn)/5.0);
        a[i]-=(5*floor((a[i]-mn)/5.0));
        numops+=nChocs;
    }
    mn = *min_element(a.begin(),a.end());

    vector<int> freq(5);

    for(int i=0;i<n;i++){
        freq[a[i]-mn]++;
    }

    int op = 1*(freq[1]+freq[2])+2*(freq[3]+freq[4]);
    int op1 = 1*(freq[0]+freq[1]+freq[4])+2*(freq[2]+freq[3]);

    if(op1<op) op = op1;
    op1 = 2*(freq[1]+freq[2]+freq[4])+1*(freq[0]+freq[3]);
    if(op1<op) op=op1;
    return numops+op;
}
