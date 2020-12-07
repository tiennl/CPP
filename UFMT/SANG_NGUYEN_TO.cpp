	for (int i=2;i<=m;i++) prime[i]=true;
	for (int p=2;p*p<=m;p++)  
        if (prime[p])
            for (int i=p*2;i<=m;i+=p) prime[i]=false; 
