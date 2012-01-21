import math
def improved_sieve(N):
    M=(N-1)/2
    x=(int(math.sqrt(N))-1)/2
    S=[]
    for i in range(M+1):
        S.append(False);

    for i in range (1,x+1):
        if (S[i]==False):
            for j in range (2*i*(i+1),M+1,2*i+1):
                S[j]=True

    s=2;
    for i in range (1,M+1):
        if (S[i]==False):
            s+=(2*i+1)

    print s

N=input()
improved_sieve(N)
