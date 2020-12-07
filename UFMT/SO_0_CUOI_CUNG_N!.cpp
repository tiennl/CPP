long long numberZeroDigits(long long n)
{
    long long count=0;
    double k = log(n) / log(5);
    for (int i = 1 ; i <= k ; i++)
        count += n / pow(5,i);
    return count; 
}
// So 0 cuoi cung cua n giai thua
// https://math.stackexchange.com/questions/1806642/find-the-number-of-trailing-zeros-in-n
