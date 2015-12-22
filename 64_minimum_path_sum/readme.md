#Dynamic Programming

Extrapolation Function:

S[i,j] = max(S[i,j-1],S[i-1,j])+A[i,j] , when i,j > 1
       = S[i,j-1]+A[i,j], when j == 0
       = S[i-1,j]+A[i,j], when i == 0
       = A[0,0], when i==j==0

Vector Initialization:
    vector<vector<int> > S(n_rows,vector<int>(n_cols))
