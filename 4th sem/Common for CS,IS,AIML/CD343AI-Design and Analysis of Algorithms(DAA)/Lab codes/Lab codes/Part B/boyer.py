def badShift(P):
    n=len(P)
    BS=[n]*256
    for i in range(n-2,-1,-1):
        if BS[ord(P[i])]==n:
            BS[ord(P[i])]=n-i-1
    return BS

def goodShift(P):
    n=len(P)
    i=n-2
    k=1
    GS=[0]*len(P)
    while i>-1:
        if P[i]==P[n-1]:
            GS[k]=n-i-1
            k+=1
        i-=1
    while k<n:
        GS[k]=GS[k-1]
        k+=1
    
    return GS

def Boyer(T,P):
    GS=goodShift(P)
    BS=badShift(P)
    m=len(T)
    n=len(P)
    i=n-1
    while i<m:
        k=0
        while k<=n and T[i-k]==P[n-1-k]:
            k+=1
        d1=BS[ord(T[i-1-k])]-k
        if d1<0:
            d1=max(1,d1)
        if(k!=n):
            d2=GS[k]
        else:
            d2=0
        if k==n:
            return i-n+1
        else:
            i+=max(d1,d2)
    return -1

#print(goodShift('baobab'))
T=input("Enter the text\n")
P=input("Enter the pattern\n")
res=Boyer(T,P)
if res==-1:
    print("The pattern is not found in the text\n")
else:
    print("The pattern is found in position",res+1)