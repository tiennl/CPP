long long doistring(string x){
	long long c=0;
	stringstream str2num(x);
				str2num>>c;
	return c;
}


string toString(ll a){
    ostringstream temp;
    temp<<a;
    return temp.str();
}
